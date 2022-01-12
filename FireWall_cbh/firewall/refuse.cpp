#include "refuse.h"
#include "ui_refuse.h"
#include "mainwindow.h"
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


Refuse::Refuse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Refuse)
{
    clock=new QTimer(this);
    clock->start(200);//every 200ms execute once
    ui->setupUi(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(logRefuse()));
}

Refuse::~Refuse()
{
    delete ui;
}

void Refuse::logRefuse()
{
    MainWindow mw;
    QStringList ret = mw.runShell("bash ../resourse/log.sh").split("\n");
    QFile f("../resourse/log.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)){
        QMessageBox::critical(this, "错误", "无法打开log.txt！");
    }
    QTextStream stream(&f);
    foreach (QString line, ret) {
        if (line.split(">").length() < 2){
            continue;
        }
        ui->refuseText->appendPlainText(line.split(">")[1] + "\n");
        stream << line.split(">")[1] << endl;
    }
    f.close();
}
