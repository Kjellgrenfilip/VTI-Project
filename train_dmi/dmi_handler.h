#ifndef DMI_HANDLER_H
#define DMI_HANDLER_H

#include <QObject>
#include <QQmlContext>

#include <QTimer>

#include "network_client.h"
#include "button_handler.h"

typedef std::pair<double, double> Grad_Pos;

static const std::vector<Grad_Pos> test_vector = { {15, -375.73}, {0, 201.26}, {-10, 604.26}, {0, 1835.26} };

class DMI_Handler : public QObject
{
    Q_OBJECT
public:
    explicit DMI_Handler(QQmlContext *rootContext, QObject *obj);
    DMI_Handler(bool testStart = true);
    ~DMI_Handler();

public:
    Network_Client *m_client;
    Button_Handler *m_buttonHandler;
    QObject *m_rootObject;
    QTimer *m_animationTimer;

    QJsonObject m_jsonState;
    QJsonObject m_latestUpdate{};

    bool testStart{false};
    bool animationState{false};
    int doorCounter{0};
    int pantCounter{0};

    int distanceToPixelHeight(double);
    void d5loghandler(std::vector<Grad_Pos> input, int scale);
    double toLogScale(double value, double maxDistance);
    double toLinScale(double value, double maxDistance);



signals:

public slots:
    void receiveUpdate();
    void animationHandler();
};

#endif // DMI_HANDLER_H
