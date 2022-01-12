#ifndef RULE_H
#define RULE_H

#include <QWidget>

struct Rule
{
    QString src_ipv4;
    QString des_ipv4;
    QString src_port;
    QString des_port;
    QString protocol;
    QString type;
};

#endif // RULE_H
