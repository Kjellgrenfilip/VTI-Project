#ifndef POWER_IMP_H
#define POWER_IMP_H

#include <QObject>

class power_imp : public QObject
{
    Q_OBJECT
public:
    explicit power_imp(QObject *parent = nullptr);

signals:

};

#endif // POWER_IMP_H
