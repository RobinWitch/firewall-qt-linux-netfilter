#ifndef ADDNEWRULE_H
#define ADDNEWRULE_H

#include <QWidget>
#include<QDialog>
#include<rule.h>

namespace Ui {
class AddNewRule;
}

class AddNewRule : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewRule(QWidget *parent = nullptr);
    ~AddNewRule();

    Rule defaultRule;
signals:
    void addRuleSignal(Rule);
private slots:
    void on_AddNewRule_Button_clicked();

    void on_Close_Button_clicked();

private:
    Ui::AddNewRule *ui;
};

#endif // ADDNEWRULE_H
