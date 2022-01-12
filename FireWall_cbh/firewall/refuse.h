#ifndef REFUSE_H
#define REFUSE_H

#include <QWidget>
#include<QDialog>
#include<qtimer.h>
#include<QTime>
namespace Ui {
class Refuse;
}

class Refuse : public QDialog
{
    Q_OBJECT

public:
    explicit Refuse(QWidget *parent = nullptr);
    ~Refuse();


private:
    Ui::Refuse *ui;
    QTimer *clock;

private slots:
    void logRefuse();
};

#endif // REFUSE_H
