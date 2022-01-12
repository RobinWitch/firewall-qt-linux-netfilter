#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QTableWidget>
#include<QFile>
#include<QFileDialog>
#include<QWidget>
#include<QMessageBox>
#include<QProcess>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<fcntl.h>
#include<unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ruleTable=ui->ruleTable;
    runStateLabel=ui->Run_State_Label;
    greenPix=ui->label_green;
    redPix=ui->label_red;
    ruleTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ruleTable->verticalHeader()->setHidden(true);
    ui->RUN_BUTTON->setEnabled(true);
    ui->STOP_BUTTON->setEnabled(false);
    greenPix->pixmap();
    greenPix->show();
    redPix->show();
    greenPix->setVisible(false);
    redPix->setVisible(true);
    getRuleFromTextFile();
    ui->label_red->setStyleSheet("QLabel{"
                                 "border-image:url(:/Image/Image/Red.png) ;"
                                 "}");
    ui->label_green->setStyleSheet("QLabel{"
                                 "border-image:url(:/Image/Image/Green.png) ;"
                                 "}");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ADD_RULE_BUTTON_clicked()
{
    qDebug()<<("add rule button had benn clicked");
    addNewRule=new AddNewRule();
    connect(addNewRule,SIGNAL(addRuleSignal(Rule)),this,SLOT(addRuleToTable(Rule)));
    addNewRule->exec();

}

void MainWindow::on_DELETE_RULE_BUTTON_clicked()
{
    qDebug()<<("delete rule button had benn clicked");
    int index=ruleTable->currentRow();
    if(index>=0)
    {
        ruleTable->removeRow(index);
        ruleList.removeAt(index);
        writeRuleToTextFile();
    }
    else
    {
        QMessageBox::critical(this, "error", "please choose a rule");
    }
}

void MainWindow::on_RUN_BUTTON_clicked()
{
    runShell("bash ../resourse/main.sh insmod");
    qDebug()<<("run button had benn clicked");
    ui->RUN_BUTTON->setEnabled(false);
    ui->STOP_BUTTON->setEnabled(true);
    runStateLabel->setText("FireWall is Running");
    sendRuleToFireWall();
    greenPix->setVisible(true);
    redPix->setVisible(false);
    refuse=new Refuse();
    refuse->show();
}

void MainWindow::on_STOP_BUTTON_clicked()
{
    runShell("bash ../resourse/main.sh rmmod");
    qDebug()<<("stop button had benn clicked");
    ui->RUN_BUTTON->setEnabled(true);
    ui->STOP_BUTTON->setEnabled(false);
    runStateLabel->setText("FireWall is Stopped");
    greenPix->setVisible(false);
    redPix->setVisible(true);
    refuse->close();
    delete refuse;
}

void MainWindow::addRuleToTable(Rule rule)
{
    //qDebug()<<("execute addRuleToTable");
    qDebug()<<rule.src_ipv4;
    //qDebug()<<ruleList.size();
    ruleList.append(rule);
    int num=ruleList.size()-1;
    ruleTable->setRowCount(num+1);
    //ruleTable->setItem(num,0,new QTableWidgetItem(ruleList.size()-1));
    ruleTable->setItem(num,0,new QTableWidgetItem(QString::number(num+1)));
    ruleTable->setItem(num,1,new QTableWidgetItem(rule.src_ipv4));
    ruleTable->setItem(num,2,new QTableWidgetItem(rule.src_port));
    ruleTable->setItem(num,3,new QTableWidgetItem(rule.des_ipv4));
    ruleTable->setItem(num,4,new QTableWidgetItem(rule.des_port));
    ruleTable->setItem(num,5,new QTableWidgetItem(rule.protocol));
    ruleTable->setItem(num,6,new QTableWidgetItem(rule.type));
    for (int i=0; i<ruleTable->columnCount(); i++){
        ruleTable->item(num, i)->setTextAlignment(Qt::AlignCenter);
    }
    writeRuleToTextFile();
}

void MainWindow::writeRuleToTextFile()
{
    QDir dir("../resourse");
    if(!dir.exists())
        dir.mkdir("../resource");
    QFile f("../resourse/rules.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QMessageBox::critical(this, "错误", "无法打开rule.txt！");
        return ;
    }
    QTextStream stream(&f);
    foreach (Rule rule, ruleList) {
        QString s = rule.src_ipv4 + "%"
                + rule.src_port + "%"
                + rule.des_ipv4 + "%"
                + rule.des_port + "%"
                + rule.protocol + "%"
                + rule.type;
        stream << s << endl;
        qDebug()<<s;
    }
    f.close();
    return;
}

void MainWindow::getRuleFromTextFile()
{
    //only used in program init
    QFile f("../resourse/rules.txt");
    if(!f.exists())
    {
        qDebug()<<"write";
    }
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "错误", "无法打开rule.txt！");
    }
    QTextStream stream(&f);
    while (!stream.atEnd())
    {
        QString lineStr = stream.readLine();
        qDebug()<<lineStr;
        QStringList lineSpilt = lineStr.split("%");
        Rule rule;
        rule.src_ipv4 = lineSpilt[0];
        rule.src_port = lineSpilt[1];
        rule.des_ipv4 = lineSpilt[2];
        rule.des_port = lineSpilt[3];
        rule.protocol = lineSpilt[4];
        rule.type=lineSpilt[5];
        //ruleList.append(rule);
        addRuleToTable(rule);

    }
}

QString MainWindow::runShell(QString cmd)
{
    QProcess *shell = new QProcess(this);
    shell->start(cmd);
    shell->waitForFinished();
    return shell->readAll();
}

void MainWindow::sendRuleToFireWall()
{

    int count = 0; //记录规则数量
    //规则转化为字符串再发送
    memset(controlinfo,0,sizeof(controlinfo));
    foreach(Rule ruleString, ruleList){
        ruleFormatChange(ruleString, (controlinfo+(count*24)));
            count++;
    }
    int fp;
    fp =open("/dev/controlInfo",O_RDWR,S_IRUSR|S_IWUSR);
    if (fp > 0)
    {
        write(fp,controlinfo,count*24);
        //qDebug()<<"now file fp"+QString::number(fp);
        //for(int i=0;i<1600;i+=4)
        //{
            //qDebug()<<"num"+QString::number(i/4);
            //qDebug()<<*(int *)(controlinfo+i);
        //}
    }
    else {
        QMessageBox::critical(this, "错误", "无法打开controlInfo！");
    }
    ::close(fp);
    qDebug()<<"the number of rule send to firewall is "+QString::number(count);
}

void MainWindow::ruleFormatChange(Rule ruleString, char *p_controlinfo)
{
    unsigned int controlled_protocol = 0;
    unsigned short controlled_srcport = 0;
    unsigned short controlled_dstport = 0;
    unsigned int controlled_saddr = 0;
    unsigned int controlled_daddr = 0;
    unsigned int controlled_type=0;

    //协议
    if (strncmp(ruleString.protocol.toStdString().data(), "ICMP",4) == 0 )
        controlled_protocol = 1;
    else if (strncmp(ruleString.protocol.toStdString().data(), "IGMP",4) == 0 )
        controlled_protocol = 2;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "TCP",3) == 0  )
        controlled_protocol = 6;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "EGP",3) == 0  )
        controlled_protocol = 8;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "UDP",3) == 0 )
        controlled_protocol = 17;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "IPV6",4) == 0 )
        controlled_protocol = 41;
    else if ( strncmp(ruleString.protocol.toStdString().data(), "OSPF",4) == 0 )
        controlled_protocol = 89;
    else if (strncmp( ruleString.protocol.toStdString().data(), "IP",2) == 0 )
        controlled_protocol = 0;

    //源地址
    if (strncmp(ruleString.src_ipv4.toStdString().data(),"any",3) == 0)
        controlled_saddr = 0;
    else if ( inet_aton(ruleString.src_ipv4.toStdString().data(), (struct in_addr* )&controlled_saddr) == 0){
        printf("Invalid source ip address! please check and try again! \n ");

    }

    //目的地址
    if (strncmp(ruleString.des_ipv4.toStdString().data(),"any",3) == 0)
        controlled_daddr = 0;
    else if ( inet_aton(ruleString.des_ipv4.toStdString().data(), (struct in_addr* )&controlled_daddr) == 0){
        printf("Invalid destination ip address! please check and try again! \n ");
    }

    //源端口
    unsigned short tmpport;
    if (strncmp(ruleString.src_port.toStdString().data(),"any",3) == 0)
        controlled_srcport = 0;
    else {
        tmpport = atoi(ruleString.src_port.toStdString().data());
        if (tmpport == 0){
            printf("Invalid source port! please check and try again! \n ");
        }
        controlled_srcport = htons(tmpport);
    }

    //目的端口
    if (strncmp(ruleString.des_port.toStdString().data(),"any",3) == 0)
        controlled_dstport = 0;
    else {
        tmpport = atoi(ruleString.des_port.toStdString().data());
        if (tmpport == 0){
            printf("Invalid dst port! please check and try again! \n ");
        }
        controlled_dstport = htons(tmpport);
    }

    //目的端口
    if (strncmp(ruleString.type.toStdString().data(),"Black",5) == 0)
        controlled_type = 0;
    else if(strncmp(ruleString.type.toStdString().data(),"White",5) == 0)
        controlled_type = 1;

    //放入字符串中
    *(int *)p_controlinfo = controlled_protocol;
    *(int *)(p_controlinfo + 4) = controlled_saddr;
    *(int *)(p_controlinfo + 8) = controlled_daddr;
    *(int *)(p_controlinfo + 12) = controlled_srcport;
    *(int *)(p_controlinfo + 16) = controlled_dstport;
    *(int *)(p_controlinfo + 20) = controlled_type;

    qDebug()<<*(int *)p_controlinfo;
    qDebug()<<*(int *)(p_controlinfo + 4);
    qDebug()<<*(int *)(p_controlinfo + 8);
    qDebug()<<*(int *)(p_controlinfo + 12);
    qDebug()<<*(int *)(p_controlinfo + 16);
    qDebug()<<*(int *)(p_controlinfo + 20);

}
