#ifndef DMI_HANDLER_H
#define DMI_HANDLER_H

#include <QObject>
#include <QQmlContext>

#include <QTimer>

#include "network_client.h"
#include "button_handler.h"
#include "speedometer.h"

typedef std::pair<double, double> Grad_Pos;

// Remove before handover of project
static const std::vector<Grad_Pos> test_vector = { {15, -375.73}, {0, 201.26}, {-10, 800.26}, {12, 3500}, {0, 4500.0} };

class DMI_Handler : public QObject
{
    Q_OBJECT
public:
    explicit DMI_Handler(QQmlContext *rootContext, QObject *obj);
    DMI_Handler(bool testStart = true);
    ~DMI_Handler();

private:
    int m_doorCounter{0};
    int m_pantCounter{0};
    int m_permittedSpeed;

    double m_maxDistance{4000};
    double m_trainPos{0};

    bool m_testStart{false};
    bool m_animationState{false};

    Network_Client *m_client;
    Button_Handler *m_buttonHandler;
    QObject *m_rootObject;
    QTimer *m_animationTimer;
    QJsonObject m_jsonState;
    QJsonObject m_latestUpdate{};
    Speedometer *m_speedometer;

    std::vector<Grad_Pos> m_gradientProfile = test_vector;

private:
    double toLogScale(double value);
    double toLinScale(double value);

    int distanceToPixelHeight(double);

    void d5loghandler();
    void updateGUI(QString const& key, QObject *obj);

public slots:
    void receiveUpdate();
    void animationHandler();
    void recieveMaxDistance(int x);
};

#endif // DMI_HANDLER_H
