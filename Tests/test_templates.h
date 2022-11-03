#ifndef TEST_TEMPLATES_H
#define TEST_TEMPLATES_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

#include "../network_interface.h"

namespace VTI_TESTCASE
{
    using namespace VTI_DMI;
    using namespace STATE;



    //Activation
    //TESTCASES FOR VOLTAGAE GROUP
    QJsonObject const VOLTAGE_PONTUP_ACTIVATION
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::ACTIVE   },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE  },
        { MAIN_BREAKER,         STATE::DEFAULT },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::DEFAULT  }
    };
    QJsonObject const VOLTAGE_PONTUP_ACTIVATION_MAINBREAKER
    {
        { VOLTAGE,              STATE::ACTIVE   },
        { PONTOGRAPH_UP,        STATE::ACTIVE   },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE },
        { MAIN_BREAKER,         STATE::ACTIVE   },
        { VOLTAGE_WARNING,      STATE::INACTIVE },
        { HEATING,              STATE::DEFAULT  }
    };
    QJsonObject const VOLTAGE_PONTDOWN_ACTIVATION
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::INACTIVE },
        { PONTOGRAPH_DOWN,      STATE::ACTIVE   },
        { MAIN_BREAKER,         STATE::DEFAULT  },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::INACTIVE }
    };

    QJsonObject const VOLTAGE_MAINBREAKER_ACTIVATION
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::DEFAULT  },
        { PONTOGRAPH_DOWN,      STATE::DEFAULT  },
        { MAIN_BREAKER,         STATE::ACTIVE   },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::DEFAULT  }
    };
    QJsonObject const VOLTAGE_MAINBREAKER_ACTIVATION_PONTUP
    {
        { VOLTAGE,              STATE::ACTIVE  },
        { PONTOGRAPH_UP,        STATE::ACTIVE  },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE  },
        { MAIN_BREAKER,         STATE::ACTIVE   },
        { VOLTAGE_WARNING,      STATE::INACTIVE },
        { HEATING,              STATE::DEFAULT }
    };
    QJsonObject const VOLTAGE_MAINBREAKER_DEACTIVATION
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::DEFAULT  },
        { PONTOGRAPH_DOWN,      STATE::DEFAULT  },
        { MAIN_BREAKER,         STATE::INACTIVE },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::DEFAULT  }
    };

    QJsonObject const VOLTAGE_HEAT_ACTIVATION_NOPONT
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::DEFAULT  },
        { PONTOGRAPH_DOWN,      STATE::DEFAULT  },
        { MAIN_BREAKER,         STATE::DEFAULT  },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::DEFAULT  }
    };
    QJsonObject const VOLTAGE_HEAT_ACTIVATION_PONT
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::ACTIVE   },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE },
        { MAIN_BREAKER,         STATE::DEFAULT  },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::ACTIVE   }
    };
    QJsonObject const VOLTAGE_HEAT_DEACTIVATION
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::ACTIVE   },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE },
        { MAIN_BREAKER,         STATE::DEFAULT  },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::INACTIVE }
    };

    QJsonObject const DOORS_OPEN_LEFT
    {
        { VOLTAGE,              STATE::DEFAULT  },
        { PONTOGRAPH_UP,        STATE::ACTIVE   },
        { PONTOGRAPH_DOWN,      STATE::INACTIVE },
        { MAIN_BREAKER,         STATE::DEFAULT  },
        { VOLTAGE_WARNING,      STATE::WARNING  },
        { HEATING,              STATE::INACTIVE }
    };








}


#endif // TEST_TEMPLATES_H
