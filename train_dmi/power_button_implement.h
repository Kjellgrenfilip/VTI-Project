#ifndef POWER_BUTTON_IMPLEMENT_H
#define POWER_BUTTON_IMPLEMENT_H
#include <QObject>
#include <QString>
#include <qqml.h>
class power_button_implement : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)
    //QML_ELEMENT
public:
    power_button_implement();
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

    QString message{"hello"};
public slots:
    void print();
};

#endif // POWER_BUTTON_IMPLEMENT_H
