#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTableWidget>
#include"addnewrule.h"
#include"refuse.h"
#include<QList>
#include<QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void writeRuleToTextFile();
    void getRuleFromTextFile();
    void sendRuleToFireWall();
    QString runShell(QString cmd);
    void ruleFormatChange(Rule ruleString, char *p_controlinfo);

private slots:

    void on_STOP_BUTTON_clicked();

    void on_ADD_RULE_BUTTON_clicked();

    void on_DELETE_RULE_BUTTON_clicked();

    void on_RUN_BUTTON_clicked();

    void addRuleToTable(Rule);

private:
    Ui::MainWindow *ui;
    AddNewRule *addNewRule;
    Refuse *refuse;
    QTableWidget *ruleTable;
    QList<Rule> ruleList;
    QLabel *runStateLabel;
    char controlinfo[1600];
    QLabel *redPix;
    QLabel *greenPix;
};
#endif // MAINWINDOW_H
