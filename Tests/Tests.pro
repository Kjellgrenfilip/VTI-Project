QT += testlib network
QT += quick
QT += multimedia

CONFIG += qt console warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test.cpp \
            ../test_module/test_module.cpp \
            ../test_module/network_server.cpp \
            ../train_dmi/dmi_handler.cpp \
            ../train_dmi/button_handler.cpp \
            ../train_dmi/network_client.cpp

HEADERS +=  ../test_module/test_module.h \
            ../test_module/network_server.h \
            ../train_dmi/dmi_handler.h \
            ../train_dmi/button_handler.h \
            ../train_dmi/network_client.h \
            test_templates.h
