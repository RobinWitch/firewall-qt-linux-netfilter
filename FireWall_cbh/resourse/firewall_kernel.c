//#define __KERNEL__
//#define MODULE

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/if_ether.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/tcp.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <linux/udp.h>
#include <linux/time.h>
#include <linux/timex.h>
#include <linux/rtc.h>

struct nf_hook_ops myhook;

//保存正在使用规则的信息
unsigned int controlled_protocol = 0;
unsigned short controlled_srcport = 0;
unsigned short controlled_dstport = 0;
unsigned int controlled_saddr = 0;
unsigned int controlled_daddr = 0;
unsigned int controlled_type=0;	// o is Black,1 is White


//正在处理数据包信息转化为字符串用于日志输出
char ip_buff_src[16];
char ip_buff_dst[16];
char port_buff_src[10];
char port_buff_dst[10];
char protocol_buff[10];
char type_buff[10];
char time_buff[50];
char controlinfo[1600]; //存储多条规则，每条32byte
char *pchar;
int num = 0; //规则条数

struct sk_buff *tmpskb;
struct iphdr *piphdr;

char * addr_from_net(char * buff, __be32 addr)
{
    __u8 *p = (__u8*)&addr;
    snprintf(buff, 16, "%u.%u.%u.%u",
        (__u32)p[0], (__u32)p[1], (__u32)p[2], (__u32)p[3]);
    return buff;
}

char * time_from_tm(char * buff, struct rtc_time *tm)
{
    snprintf(buff, 50, "%04d/%02d/%02d %02d:%02d:%02d",
        tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);
    return buff;
}

bool port_check(unsigned short srcport, unsigned short dstport){
	if ((controlled_srcport == 0 ) && ( controlled_dstport == 0 ))
		return 1;
	if ((controlled_srcport != 0 ) && ( controlled_dstport == 0 ))
	{
		if (controlled_srcport == srcport) 
			return 1;
		else
			return 0;
	}
	if ((controlled_srcport == 0 ) && ( controlled_dstport != 0 ))
	{
		if (controlled_dstport == dstport) 
			return 1;
		else
			return 0;
	}
	if ((controlled_srcport != 0 ) && ( controlled_dstport != 0 ))
	{
		if ((controlled_srcport == srcport) && (controlled_dstport == dstport)) 
			return 1;
		else
			return 0;
	}
	return 0;
}

bool ipaddr_check(unsigned int saddr, unsigned int daddr){
	if ((controlled_saddr == 0 ) && ( controlled_daddr == 0 ))
		return 1;
	if ((controlled_saddr != 0 ) && ( controlled_daddr == 0 ))
	{
		if (controlled_saddr == saddr) 
			return 1;
		else
			return 0;
	}
	if ((controlled_saddr == 0 ) && ( controlled_daddr != 0 ))
	{
		if (controlled_daddr == daddr) 
			return 1;
		else
			return 0;
	}
	if ((controlled_saddr != 0 ) && ( controlled_daddr != 0 ))
	{
		if ((controlled_saddr == saddr) && (controlled_daddr == daddr)) 
			return 1;
		else
			return 0;
	}
	return 0;
}

bool icmp_check(void){
	struct icmphdr *picmphdr;
	picmphdr = (struct icmphdr *)(tmpskb->data +(piphdr->ihl*4));

	if (picmphdr->type == 0){
			if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
			 	printk("An ICMP packet is denied! \n");
				snprintf(port_buff_src, 10, " ");
        		snprintf(port_buff_dst, 10, " ");
				return 1;
			}
	}
	if (picmphdr->type == 8){
			if (ipaddr_check(piphdr->saddr,piphdr->daddr) == 1){
			 	printk("An ICMP packet is denied! \n");
				snprintf(port_buff_src, 10, " ");
        		snprintf(port_buff_dst, 10, " ");
				return 1;
			}
	}
    return 0;
}

bool tcp_check(void){
	struct tcphdr *ptcphdr;
	//   printk("<0>This is an tcp packet.\n");
	ptcphdr = (struct tcphdr *)(tmpskb->data +(piphdr->ihl*4));
	if ((ipaddr_check(piphdr->saddr,piphdr->daddr) == 1) && (port_check(ptcphdr->source,ptcphdr->dest) == 1)){
	 	printk("A TCP packet is denied! \n");
	 	snprintf(port_buff_src, 10, ":%d", ntohs(ptcphdr->source));
        snprintf(port_buff_dst, 10, ":%d", ntohs(ptcphdr->dest));
		return 1;
	}
	else
      return 0;
}

bool udp_check(void){
	struct udphdr *pudphdr;	
	//   printk("<0>This is an udp packet.\n");
	pudphdr = (struct udphdr *)(tmpskb->data +(piphdr->ihl*4));
	if ((ipaddr_check(piphdr->saddr,piphdr->daddr) == 1) && (port_check(pudphdr->source,pudphdr->dest) == 1)){
	 	snprintf(port_buff_src, 10, ":%d", ntohs(pudphdr->source));
        snprintf(port_buff_dst, 10, ":%d", ntohs(pudphdr->dest));
	 	printk("A UDP packet is denied! \n");
		return 1;
	}
	else
      return 0;
}

bool ip_check(void){
	if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
		printk("An IP packet is denied! \n");
		snprintf(port_buff_src, 10, " ");
        snprintf(port_buff_dst, 10, " ");
		return 1;
	}
	return 0;
}

bool igmp_check(void){
	if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
		printk("An IGMP packet is denied! \n");
		snprintf(port_buff_src, 10, " ");
        snprintf(port_buff_dst, 10, " ");
		return 1;
	}
	return 0;
}

bool egp_check(void){
	if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
		printk("An EGP packet is denied! \n");
		snprintf(port_buff_src, 10, " ");
        snprintf(port_buff_dst, 10, " ");
		return 1;
	}
	return 0;
}

bool ipv6_check(void){
	if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
		printk("An IPV6 packet is denied! \n");
		snprintf(port_buff_src, 10, " ");
        snprintf(port_buff_dst, 10, " ");
		return 1;
	}
	return 0;
}

bool ospf_check(void){
	if (ipaddr_check(piphdr->daddr,piphdr->saddr) == 1){
		printk("An OSPF packet is denied! \n");
		snprintf(port_buff_src, 10, " ");
        snprintf(port_buff_dst, 10, " ");
		return 1;
	}
	return 0;
}

/*unsigned int hook_func(unsigned int hooknum,struct sk_buff **skb,const struct net_device *in,const struct net_device *out,int (*okfn)(struct sk_buff *))
*/
unsigned int hook_func(void * priv,struct sk_buff *skb,const struct nf_hook_state * state){

	bool result = 0;
	struct timex txc;
	struct rtc_time tm;

   	tmpskb = skb;
	piphdr = ip_hdr(tmpskb);

	//时间
	do_gettimeofday(&txc.time);   //获取当前UTC时间
    	txc.time.tv_sec += 8 * 60 * 60;  //把UTC时间调整为本地时间
    	rtc_time_to_tm(txc.time.tv_sec, &tm);   //算出时间中的年月日等数值到tm中
	time_from_tm(time_buff, &tm);
	addr_from_net(ip_buff_src, piphdr->saddr);
	addr_from_net(ip_buff_dst, piphdr->daddr);


	if(num == 0) return NF_ACCEPT; 
	else {
		int i;
		pchar = controlinfo;
		for (i = 0; i<num; i++){
			//One rule
			controlled_protocol = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_saddr = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_daddr = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_srcport = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_dstport = *(( int *) pchar);
			pchar = pchar + 4;
			controlled_type= *(( int *) pchar);
			pchar = pchar + 4;
			
            if(controlled_type==1)
            {
                if(controlled_daddr == piphdr->daddr)
                    return NF_ACCEPT;
            }
			
			if(controlled_protocol==0){
				snprintf(protocol_buff, 10, "%s", "IP");
					result = ip_check();
			}
			else if(piphdr->protocol != controlled_protocol) 
      			{ result = 0; continue; }
			else{
      			if (piphdr->protocol  == 1){ //ICMP 
      				snprintf(protocol_buff, 10, "%s", "ICMP");
      				result = icmp_check();
      			}  
				else if (piphdr->protocol  == 2){ //IGMP
					snprintf(protocol_buff, 10, "%s", "IGMP");
					result = igmp_check();
				}   
				else if (piphdr->protocol  == 6){ //TCP
					snprintf(protocol_buff, 10, "%s", "TCP");
					result = tcp_check();
				}
				else if (piphdr->protocol  == 8){ //EGP
					snprintf(protocol_buff, 10, "%s", "EGP");
					result = egp_check();
				}  
				else if (piphdr->protocol  == 17){ //UDP
					snprintf(protocol_buff, 10, "%s", "UDP");
					result = udp_check();
				}
				else if (piphdr->protocol  == 41){ //IPV6
					snprintf(protocol_buff, 10, "%s", "IPV6");
					result = ipv6_check();
				} 
				else if (piphdr->protocol  == 89){ //OSPF
					snprintf(protocol_buff, 10, "%s", "OSPF");
					result = ospf_check();
				} 
				else
					return NF_ACCEPT;
				if(result == 0) continue;
      		}

		}
		if(result == 1)
		{
			printk("<CBH>%s %s packet which from  %s%s  to  %s%s   had been refused!  \n",
            time_buff,protocol_buff, ip_buff_src, port_buff_src,
            ip_buff_dst, port_buff_dst);
			return NF_DROP;
		}
		return NF_ACCEPT;
	}

}

static ssize_t write_controlinfo(struct file * fd, const char __user *buf, size_t len, loff_t *ppos)
{
	
	if (len == 0){
		return len;
	}

	if (copy_from_user(controlinfo, buf, len) != 0){
		printk("Can't get the control rule! \n");
		printk("Something may be wrong, please check it! \n");
		return 0;
	}

	pchar = controlinfo;
	num = len/24;
	
	return len;
}


struct file_operations fops = {
	.owner=THIS_MODULE, 
	.write=write_controlinfo,
}; 


static int __init initmodule(void)
{
	int ret;
	printk("Init Module\n");
	myhook.hook=hook_func;
	myhook.hooknum=NF_INET_POST_ROUTING;
	myhook.pf=PF_INET;
	myhook.priority=NF_IP_PRI_FIRST;
	nf_register_hook(&myhook);
	ret = register_chrdev(817, "/dev/controlInfo", &fops); 	
	if (ret != 0) printk("Can't register device file! \n"); 

    	return 0;
}

static void __exit cleanupmodule(void)
{
	nf_unregister_hook(&myhook);
	unregister_chrdev(817, "controlInfo");	 
        printk("CleanUp\n");
}

module_init(initmodule);
module_exit(cleanupmodule);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ChenBohong");
