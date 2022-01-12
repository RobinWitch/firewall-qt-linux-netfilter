/********************************************************************************
** Form generated from reading UI file 'refuse.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUSE_H
#define UI_REFUSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Refuse
{
public:
    QPlainTextEdit *refuseText;
    QLabel *label;

    void setupUi(QWidget *Refuse)
    {
        if (Refuse->objectName().isEmpty())
            Refuse->setObjectName(QStringLiteral("Refuse"));
        Refuse->resize(940, 438);
        Refuse->setBaseSize(QSize(2, 2));
        refuseText = new QPlainTextEdit(Refuse);
        refuseText->setObjectName(QStringLiteral("refuseText"));
        refuseText->setGeometry(QRect(30, 100, 881, 311));
        label = new QLabel(Refuse);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 30, 251, 41));
        label->setBaseSize(QSize(2, 2));
        QFont font;
        font.setPointSize(18);
        label->setFont(font);

        retranslateUi(Refuse);

        QMetaObject::connectSlotsByName(Refuse);
    } // setupUi

    void retranslateUi(QWidget *Refuse)
    {
        Refuse->setWindowTitle(QApplication::translate("Refuse", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("Refuse", "Log Refuse Information", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Refuse: public Ui_Refuse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUSE_H
