#include "addnewrule.h"
#include "ui_addnewrule.h"
#include<QDebug>
AddNewRule::AddNewRule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewRule)
{
    ui->setupUi(this);
    ui->src_ipv4->setText(defaultRule.src_ipv4);
    ui->des_ipv4->setText(defaultRule.des_ipv4);
    ui->src_port->setText(defaultRule.src_port);
    ui->des_port->setText(defaultRule.des_port);
    ui->protocol_comboBox->addItem("ICMP");
    ui->protocol_comboBox->addItem("IGMP");
    ui->protocol_comboBox->addItem("TCP");
    ui->protocol_comboBox->addItem("EGP");
    ui->protocol_comboBox->addItem("UDP");
    ui->protocol_comboBox->addItem("IPV6");
    ui->protocol_comboBox->addItem("OSPF");
    ui->protocol_comboBox->addItem("IP");
    ui->type_comboBox->addItem("White");
    ui->type_comboBox->addItem("Black");
}

AddNewRule::~AddNewRule()
{
    delete ui;
}

void AddNewRule::on_AddNewRule_Button_clicked()
{
    Rule newRule;
    newRule.src_ipv4=ui->src_ipv4->text();
    newRule.src_port=ui->src_port->text();
    newRule.des_ipv4=ui->des_ipv4->text();
    newRule.des_port=ui->des_port->text();
    newRule.protocol=ui->protocol_comboBox->currentText();
    newRule.type=ui->type_comboBox->currentText();
   // qDebug()<<newRule.src_ipv4;
    emit(addRuleSignal(newRule));
    this->close();
}

void AddNewRule::on_Close_Button_clicked()
{
    this->close();
}
