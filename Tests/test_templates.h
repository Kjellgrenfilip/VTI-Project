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
        { DOOR_LEFT,            STATE::WARNING  },
        { DOOR_RIGHT,           STATE::DEFAULT  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::DEFAULT  }
    };

    QJsonObject const DOORS_OPEN_RIGHT
    {
        { DOOR_LEFT,            STATE::DEFAULT  },
        { DOOR_RIGHT,           STATE::WARNING  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::DEFAULT  }
    };

    QJsonObject const DOORS_OPEN_LEFT_RIGHT
    {
        { DOOR_LEFT,            STATE::WARNING  },
        { DOOR_RIGHT,           STATE::WARNING  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::DEFAULT  }
    };

    QJsonObject const DOORS_DEPARTURE_RIGHT
    {
        { DOOR_LEFT,            STATE::DEFAULT  },
        { DOOR_RIGHT,           STATE::WARNING  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::WARNING  }
    };
    QJsonObject const DOORS_DEPARTURE_LEFT
    {
        { DOOR_LEFT,            STATE::WARNING  },
        { DOOR_RIGHT,           STATE::DEFAULT  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::WARNING  }
    };
    QJsonObject const DOORS_DEPARTURE_RIGHT_LEFT
    {
        { DOOR_LEFT,            STATE::WARNING  },
        { DOOR_RIGHT,           STATE::WARNING  },
        { DOOR_CLOSE,           STATE::INACTIVE },
        { DEPARTURE,            STATE::WARNING  }
    };
    QJsonObject const DOORS_CLOSE_LEFT_RIGHT
    {
        { DOOR_LEFT,            STATE::WARNING },
        { DOOR_RIGHT,           STATE::WARNING },
        { DOOR_CLOSE,           STATE::WARNING },
        { DEPARTURE,            STATE::WARNING }
    };
    QJsonObject const DOORS_CLOSED
    {
        { DOOR_LEFT,            STATE::INACTIVE },
        { DOOR_RIGHT,           STATE::INACTIVE },
        { DOOR_CLOSE,           STATE::ACTIVE   },
        { DEPARTURE,            STATE::INACTIVE }
    };

    QJsonObject const DOORS_CLOSE_RIGHT
    {
        { DOOR_LEFT,            STATE::DEFAULT },
        { DOOR_RIGHT,           STATE::WARNING  },
        { DOOR_CLOSE,           STATE::WARNING  },
        { DEPARTURE,            STATE::WARNING  }
    };
    QJsonObject const DOORS_CLOSED_RIGHT
    {
        { DOOR_LEFT,            STATE::INACTIVE },
        { DOOR_RIGHT,           STATE::INACTIVE },
        { DOOR_CLOSE,           STATE::ACTIVE   },
        { DEPARTURE,            STATE::INACTIVE }
    };









}


#endif // TEST_TEMPLATES_H
