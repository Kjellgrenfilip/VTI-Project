#include "dmi_handler.h"

#include <QJsonObject>
#include <QQmlComponent>
#include <QQuickItem>
#include <QJSEngine>
#include <QFile>
#include <QMetaObject>

DMI_Handler::DMI_Handler(QQmlContext *rootContext, QObject *obj) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{obj}, m_animationTimer{new QTimer{this}}, m_jsonState{},
    m_speedometer{new Speedometer{obj}},m_PASPQueue{}
{
    rootContext->setContextProperty("buttonHandler", m_buttonHandler);

    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));
    connect(m_animationTimer, SIGNAL(timeout()), this, SLOT(animationHandler()));

    m_client->connectToServer();

    m_animationTimer->setInterval(500);
    m_animationTimer->start();

    callCreatePASPImageInQML();

    QObject *image;
    QString hello;
    QMetaObject::invokeMethod(m_rootObject->findChild<QObject*>("etcsD"), "createPASPImage", Q_RETURN_ARG(QString, hello));
    qDebug() << hello;/*

   // QMetaObject::invokeMethod(this, "createPASPImage", Q_RETURN_ARG(QObject*, image));
    //image->setProperty("x", 500);
    //qDebug() << image.;
   // something->setProperty("color","red");
    //m_qmlObject->findChild<QObject>("speed").setProperty("color", "MyConst.orange");

}

DMI_Handler::DMI_Handler(bool testStart) : QObject(), m_client{new Network_Client{}},
    m_buttonHandler{new Button_Handler{}}, m_rootObject{}, m_animationTimer{new QTimer{this}},
    m_jsonState{}, testStart(testStart)
{
    connect(m_buttonHandler, SIGNAL(sendUpdate(QJsonObject)), m_client, SLOT(sendUpdate(QJsonObject)));
    connect(m_client, SIGNAL(updateReceived()),this, SLOT(receiveUpdate()));

    m_client->connectToServer();
}

DMI_Handler::~DMI_Handler()
{
    delete m_client;
    delete m_buttonHandler;
    delete m_animationTimer;
}
/*void DMI_Handler::d5loghandler(std::vector<std::pair<double,double>> input,int scale)
{
    double totallength{0};
    double currentlength{0};
    int iterator = 1;
    double scaleLength = 270;
    double linearLength = 35;
    double logLength = scaleLength - linearLength;
    double log100 = 2;
    double log1000 = 3;

    for(std::pair<double,double>x : input)
    {
        if(x.second > 0.0)
        {
            totallength += x.second;
        }
    }
    for(std::pair<double,double>x : input)
    {
        if(x.second > 0.0)
        {
            if ( x.second + currentlength <= scale/8 )
                x.second = -currentlength + (x.second + currentlength)  * (linearLength/100);
            else if ( x.second + currentlength <= scale )
                x.second = -currentlength + linearLength + (log10(x.second) - log100) / (log1000 - log100) * logLength;
            else
                x.second = scaleLength - currentlength;
            currentlength += x.second;
        }
    }
    for(auto x : input)
    {
        if(x.second > 0.0 && iterator <=4)
        {
            QObject *obj = m_rootObject->findChild<QObject*>("d5bar" + std::to_string(iterator));
            std::string text{"barValue" + std::to_string(iterator++)};

            obj->setProperty(text ,x.second);
        }
    }
}*/
/*
void DMI_Handler::callCreatePASPImageInQML()
{
    emit doCreatePASPImage();
}*/

void DMI_Handler::receiveUpdate()
{
    if(firstTime)
    {

        //QQmlComponent rectangle = QQmlComponent(m_Engine, QUrl("PASPImage.qml"));
        qDebug() << "HERE";
        QQuickItem *childItem = qobject_cast<QQuickItem*>(rectangle.create());
        qDebug() << "HERE2";
        childItem->setParent(m_qmlObject);
        m_PASPQueue.enqueue(childItem);
       // qDebug() << m_qmlObject->childItems().empty();
        qDebug() << childItem->width();
        firstTime = false;*/
    }

    m_latestUpdate = m_client->getUpdate();
    foreach(const QString& key, m_latestUpdate.keys())
    {
        if(key == VTI_DMI::SUPERVISIONSTATUS)
        {
            m_speedometer->updateSpeedometer(m_latestUpdate);
            return;
        }
        m_jsonState.insert(key, m_latestUpdate.value(key));
        qDebug() << key;
        //Update GUI
        if(!testStart)
        {
            QObject *obj = m_rootObject->findChild<QObject*>(key);
            if(!obj)
            {
                qDebug() << "Unknown object: " << key;
                continue;
            }

            if ( key == VTI_DMI::VELOCITY )
            {
                // Special case example
            }
            else if ( key == VTI_DMI::SPEEDLIMIT || key == VTI_DMI::DISTANCE || key == VTI_DMI::ETCSC3Text)
            {
                QString newValue = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newValue);
            }

            else if ( key == VTI_DMI::DISTANCE )
            {
                QString distanceStr = m_latestUpdate.value(key).toString();
                obj->setProperty("text", distanceStr);

                obj = m_rootObject->findChild<QObject*>(VTI_DMI::DISTANCE_BAR);
                double distance = distanceStr.toDouble();
                obj->setProperty("barValue", distanceToPixelHeight(distance));
            }

            else if( key == VTI_DMI::TEXTINFO)
            {
                QString newText = m_latestUpdate.value(key).toString();
                obj->setProperty("text", newText);
            }

            else if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image
                      || key == VTI_DMI::ETCSB5Image  ||  key == VTI_DMI::ETCSB7Image
                      || key == VTI_DMI::ETCSC1Image)
            {
                QString value = m_latestUpdate.value(key).toString();
                QString s;
                if(key == VTI_DMI::ETCSB7Image)
                    s = "symbols/Track Conditions/MO_";
                else if(key == VTI_DMI::ETCSC1Image)
                {
                    s = "symbols/Level/LE_";
                }
                else
                    s = "symbols/Track Conditions/TC_";
                s = s + value + ".bmp";
                qDebug() << s;

                obj->setProperty("source", s);
            }
            else
            {
                QString newState = m_latestUpdate.value(key).toString();
                qDebug() << key << " : " << newState;
                obj->setProperty("state", newState);
            }
            updateGUI(key, obj);
        }
    }
}

void DMI_Handler::updateGUI(QString const& key, QObject *obj)
{
    if ( key == VTI_DMI::VELOCITY )
    {
        //Special case
    }
    else if ( key == VTI_DMI::SPEEDLIMIT || key == VTI_DMI::DISTANCE || key == VTI_DMI::ETCSC3Text)
    {
        QString newValue = m_latestUpdate.value(key).toString();
        obj->setProperty("text", newValue);
    }

    else if ( key == VTI_DMI::DISTANCE_BAR )
    {
        int newValue = m_latestUpdate.value(key).toDouble();
        qDebug() << "DISTANCE: " << newValue;
        obj->setProperty("barValue", newValue);
    }

    else if( key == VTI_DMI::TEXTINFO)
    {
        QString newText = m_latestUpdate.value(key).toString();
        obj->setProperty("text", newText);
    }

    else if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image
              || key == VTI_DMI::ETCSB5Image  ||  key == VTI_DMI::ETCSB7Image
              || key == VTI_DMI::ETCSC1Image)
    {
        QString value = m_latestUpdate.value(key).toString();
        QString s;
        if(key == VTI_DMI::ETCSB7Image)
            s = "symbols/Track Conditions/MO_";
        else if(key == VTI_DMI::ETCSC1Image)
        {
            s = "symbols/Level/LE_";
        }
        else
            s = "symbols/Track Conditions/TC_";
        s = s + value + ".bmp";
        qDebug() << s;

        obj->setProperty("source", s);
    }
    else
    {
        QString newState = m_latestUpdate.value(key).toString();
        qDebug() << key << " : " << newState;
        obj->setProperty("state", newState);
    }

    if ( key == VTI_DMI::ETCSB3Image || key == VTI_DMI::ETCSB4Image || key == VTI_DMI::ETCSB5Image )
    {
        QString value = m_latestUpdate.value(key).toString();

        QString s = "symbols/Track Conditions/TC_" + value + ".bmp";
        qDebug() << s;
        obj->setProperty("source", s);
    }
    else
    {
        QString newState = m_latestUpdate.value(key).toString();
        qDebug() << key << " : " << newState;
        obj->setProperty("state", newState);
    }
}

void DMI_Handler::animationHandler()
{
    foreach(const QString& key, m_jsonState.keys())
    {
        QString currentState = m_jsonState.value(key).toString();
        if ( currentState == STATE::WARNING || currentState == STATE::BLINKING )
        {
            QObject *image = m_rootObject->findChild<QObject*>(key + "Image");
            if ( image == nullptr )
                continue;

            QObject *imageBlinking = m_rootObject->findChild<QObject*>(key + "ImageBlinking");
            if ( imageBlinking == nullptr )
                continue;

            image->setProperty("visible", animationState);
            imageBlinking->setProperty("visible", !animationState);
            if(key == VTI_DMI::DOOR_CLOSE && !animationState)
            {
                doorCounter++;
                if(doorCounter>3)
                {
                    doorCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_DOORS, true);
                    m_client->sendUpdate(json);
                }
            }
            if ( key == VTI_DMI::PANTOGRAPH_UP && !animationState)
            {
                pantCounter++;
                if(pantCounter>3)
                {
                    pantCounter = 0;
                    QJsonObject json{};
                    json.insert(VTI_DMI::RESET_PANTOGRAPH_UP, true);
                    m_client->sendUpdate(json);
                }
            }
        }
    }

    animationState = !animationState;
}

int DMI_Handler::distanceToPixelHeight(double distance)
{
    double scaleLength{186};
    double linearLength{33};
    double logLength{scaleLength - linearLength};
    double log100{2};
    double log1000{3};
    int pixelHeight{0};

    if ( distance <= 100 )
        pixelHeight = distance * (linearLength/100);
    else if ( distance <= 1000 )
        pixelHeight = linearLength + (log10(distance) - log100) / (log1000 - log100) * logLength;
    else
        pixelHeight = 186;

    return pixelHeight;
}
