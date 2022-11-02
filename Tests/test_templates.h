#ifndef TEST_TEMPLATES_H
#define TEST_TEMPLATES_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

#include "../network_interface.h"

namespace JSON_TESTS
{
    using namespace VTI_DMI;
    using namespace STATE;

    QJsonObject const JSON_PONTUP_TEST
    {
        { VOLTAGE,              STATE::DEFAULT },
        { PONTOGRAPH_UP,        STATE::ACTIVE },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE },
        { MAIN_BREAKER,         STATE::DEFAULT },
        { VOLTAGE_WARNING,      STATE::WARNING },
        { HEATING,              STATE::DEFAULT }
    };
}


#endif // TEST_TEMPLATES_H
