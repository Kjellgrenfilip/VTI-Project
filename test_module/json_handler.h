#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H

#include <QObject>

class JSON_Handler : public QObject
{
    Q_OBJECT
public:
    explicit JSON_Handler(QObject *parent = nullptr);

signals:

};

#endif // JSON_HANDLER_H
