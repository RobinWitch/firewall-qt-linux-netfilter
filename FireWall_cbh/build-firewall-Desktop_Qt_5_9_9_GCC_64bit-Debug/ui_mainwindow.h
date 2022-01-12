/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTableWidget *ruleTable;
    QLabel *Run_State_Label;
    QLabel *label_red;
    QLabel *label_green;
    QPushButton *RUN_BUTTON;
    QPushButton *ADD_RULE_BUTTON;
    QPushButton *DELETE_RULE_BUTTON;
    QPushButton *STOP_BUTTON;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(822, 664);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 220, 701, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ruleTable = new QTableWidget(verticalLayoutWidget);
        if (ruleTable->columnCount() < 7)
            ruleTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ruleTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        ruleTable->setObjectName(QStringLiteral("ruleTable"));

        horizontalLayout->addWidget(ruleTable);


        verticalLayout->addLayout(horizontalLayout);

        Run_State_Label = new QLabel(centralwidget);
        Run_State_Label->setObjectName(QStringLiteral("Run_State_Label"));
        Run_State_Label->setGeometry(QRect(640, 555, 131, 21));
        label_red = new QLabel(centralwidget);
        label_red->setObjectName(QStringLiteral("label_red"));
        label_red->setGeometry(QRect(580, 540, 50, 50));
        label_red->setPixmap(QPixmap(QString::fromUtf8("Image/Red.png")));
        label_green = new QLabel(centralwidget);
        label_green->setObjectName(QStringLiteral("label_green"));
        label_green->setGeometry(QRect(580, 540, 51, 51));
        label_green->setPixmap(QPixmap(QString::fromUtf8("Image/Green.png")));
        RUN_BUTTON = new QPushButton(centralwidget);
        RUN_BUTTON->setObjectName(QStringLiteral("RUN_BUTTON"));
        RUN_BUTTON->setGeometry(QRect(550, 40, 111, 41));
        ADD_RULE_BUTTON = new QPushButton(centralwidget);
        ADD_RULE_BUTTON->setObjectName(QStringLiteral("ADD_RULE_BUTTON"));
        ADD_RULE_BUTTON->setGeometry(QRect(160, 40, 111, 41));
        DELETE_RULE_BUTTON = new QPushButton(centralwidget);
        DELETE_RULE_BUTTON->setObjectName(QStringLiteral("DELETE_RULE_BUTTON"));
        DELETE_RULE_BUTTON->setGeometry(QRect(160, 110, 111, 41));
        STOP_BUTTON = new QPushButton(centralwidget);
        STOP_BUTTON->setObjectName(QStringLiteral("STOP_BUTTON"));
        STOP_BUTTON->setGeometry(QRect(550, 110, 111, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 160, 131, 61));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 822, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = ruleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "No", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = ruleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Src_ipv4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = ruleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Src_port", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = ruleTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Des_ipv4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = ruleTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Des_port", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = ruleTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Protocol", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = ruleTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        Run_State_Label->setText(QApplication::translate("MainWindow", "FireWall isStoppd", Q_NULLPTR));
        label_red->setText(QString());
        label_green->setText(QString());
        RUN_BUTTON->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        ADD_RULE_BUTTON->setText(QApplication::translate("MainWindow", "ADD RUlE", Q_NULLPTR));
        DELETE_RULE_BUTTON->setText(QApplication::translate("MainWindow", "DELETE RULE", Q_NULLPTR));
        STOP_BUTTON->setText(QApplication::translate("MainWindow", "STOP", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "RuleTable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
