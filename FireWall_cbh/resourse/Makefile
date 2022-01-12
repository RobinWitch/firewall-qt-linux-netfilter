obj-m += firewall_kernel.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)
MOD_NAME := "firewall_kernel.ko"

default:
	#gcc -o firewall_kernel.o firewall_kernel.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	
