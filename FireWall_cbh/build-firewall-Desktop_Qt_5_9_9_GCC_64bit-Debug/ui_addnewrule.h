/********************************************************************************
** Form generated from reading UI file 'addnewrule.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWRULE_H
#define UI_ADDNEWRULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewRule
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddNewRule_Button;
    QSpacerItem *horizontalSpacer;
    QPushButton *Close_Button;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *protocol_comboBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *src_ipv4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *des_ipv4;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *src_port;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *des_port;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *type_comboBox;

    void setupUi(QWidget *AddNewRule)
    {
        if (AddNewRule->objectName().isEmpty())
            AddNewRule->setObjectName(QStringLiteral("AddNewRule"));
        AddNewRule->resize(400, 346);
        horizontalLayoutWidget = new QWidget(AddNewRule);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(50, 250, 311, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        AddNewRule_Button = new QPushButton(horizontalLayoutWidget);
        AddNewRule_Button->setObjectName(QStringLiteral("AddNewRule_Button"));

        horizontalLayout->addWidget(AddNewRule_Button);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Close_Button = new QPushButton(horizontalLayoutWidget);
        Close_Button->setObjectName(QStringLiteral("Close_Button"));

        horizontalLayout->addWidget(Close_Button);

        horizontalLayoutWidget_2 = new QWidget(AddNewRule);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(120, 160, 160, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        protocol_comboBox = new QComboBox(horizontalLayoutWidget_2);
        protocol_comboBox->setObjectName(QStringLiteral("protocol_comboBox"));

        horizontalLayout_2->addWidget(protocol_comboBox);

        horizontalLayoutWidget_3 = new QWidget(AddNewRule);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 30, 160, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        src_ipv4 = new QLineEdit(horizontalLayoutWidget_3);
        src_ipv4->setObjectName(QStringLiteral("src_ipv4"));

        horizontalLayout_3->addWidget(src_ipv4);

        horizontalLayoutWidget_4 = new QWidget(AddNewRule);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(220, 30, 160, 41));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_4);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        des_ipv4 = new QLineEdit(horizontalLayoutWidget_4);
        des_ipv4->setObjectName(QStringLiteral("des_ipv4"));

        horizontalLayout_4->addWidget(des_ipv4);

        horizontalLayoutWidget_5 = new QWidget(AddNewRule);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(30, 90, 160, 41));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        src_port = new QLineEdit(horizontalLayoutWidget_5);
        src_port->setObjectName(QStringLiteral("src_port"));

        horizontalLayout_5->addWidget(src_port);

        horizontalLayoutWidget_6 = new QWidget(AddNewRule);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(220, 90, 160, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(horizontalLayoutWidget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        des_port = new QLineEdit(horizontalLayoutWidget_6);
        des_port->setObjectName(QStringLiteral("des_port"));

        horizontalLayout_6->addWidget(des_port);

        horizontalLayoutWidget_7 = new QWidget(AddNewRule);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(120, 200, 160, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(horizontalLayoutWidget_7);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        type_comboBox = new QComboBox(horizontalLayoutWidget_7);
        type_comboBox->setObjectName(QStringLiteral("type_comboBox"));

        horizontalLayout_7->addWidget(type_comboBox);


        retranslateUi(AddNewRule);

        QMetaObject::connectSlotsByName(AddNewRule);
    } // setupUi

    void retranslateUi(QWidget *AddNewRule)
    {
        AddNewRule->setWindowTitle(QApplication::translate("AddNewRule", "Form", Q_NULLPTR));
        AddNewRule_Button->setText(QApplication::translate("AddNewRule", "AddNewRule", Q_NULLPTR));
        Close_Button->setText(QApplication::translate("AddNewRule", "Close", Q_NULLPTR));
        label->setText(QApplication::translate("AddNewRule", "Protocol", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddNewRule", "src_ipv4:", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddNewRule", "des_ipv4:", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddNewRule", "src_port:", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddNewRule", "des_port:", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddNewRule", "Type", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNewRule: public Ui_AddNewRule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWRULE_H
