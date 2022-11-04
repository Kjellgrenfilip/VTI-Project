#include <QtTest>

// add necessary includes here
#include "../test_module/test_module.h"
// #include "../test_module/network_server.h"
#include "../train_dmi/dmi_handler.h"
#include "../network_interface.h"
#include "test_templates.h"

class test : public QObject
{
    Q_OBJECT

public:
    test(){};
    ~test(){};

private slots:
    void testPontUp();
    void testPontDown();
    void testMainBreaker();
    void testHeating();
    void testDoors();
    void testReverse();
    void testActivation();
    void testParking();
};

void delay(int timeToWait)
{
    QTime dieTime= QTime::currentTime().addMSecs(timeToWait);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

struct TestConf
{
    TestConf()
    {
        testModule = new Test_Module{};
        delay(100);
        dmiHandler = new DMI_Handler{};
        delay(100);
        dmiHandler->m_buttonHandler->activatePressed();
        delay(100);
    };

    ~TestConf()
    {
        delete dmiHandler;
        delete testModule;
    }

    Test_Module* testModule;
    DMI_Handler* dmiHandler;
};

void test::testPontUp()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->pontUpPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PONTUP_ACTIVATION);

    tc.testModule->resetStates();
    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);
    tc.dmiHandler->m_buttonHandler->pontUpPressed();
    delay(3000);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PONTUP_ACTIVATION_MAINBREAKER);

}

void test::testPontDown()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->pontDownPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PONTDOWN_ACTIVATION);
}

void test::testMainBreaker()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_MAINBREAKER_ACTIVATION);

    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_MAINBREAKER_DEACTIVATION);

    tc.testModule->resetStates();
    tc.dmiHandler->m_buttonHandler->pontUpPressed();
    delay(3500);
    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_MAINBREAKER_ACTIVATION_PONTUP);
}

void test::testHeating()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->heatingPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_HEAT_ACTIVATION_NOPONT);

    tc.dmiHandler->m_buttonHandler->pontUpPressed();
    delay(3300);
    tc.dmiHandler->m_buttonHandler->heatingPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_HEAT_ACTIVATION_PONT);
    tc.dmiHandler->m_buttonHandler->heatingPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_HEAT_DEACTIVATION);
}

void test::testDoors()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->leftDoorPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_OPEN_LEFT);
    tc.dmiHandler->m_buttonHandler->rightDoorPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_OPEN_LEFT_RIGHT);
    tc.dmiHandler->m_buttonHandler->departureButtonPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_DEPARTURE_RIGHT_LEFT);
    tc.dmiHandler->m_buttonHandler->closeDoorPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_CLOSE_LEFT_RIGHT);
    delay(3500);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_CLOSED);

    tc.testModule->resetStates();
    tc.dmiHandler->m_buttonHandler->rightDoorPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_OPEN_RIGHT);
    tc.dmiHandler->m_buttonHandler->departureButtonPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_DEPARTURE_RIGHT);
    tc.dmiHandler->m_buttonHandler->closeDoorPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_CLOSE_RIGHT);
    delay(3500);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::DOORS_CLOSED_RIGHT);
}

void test::testReverse()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->reversePressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::REVERSE_ACTIVATED);
    tc.dmiHandler->m_buttonHandler->reversePressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::REVERSE_DEACTIVATED);
}

void test::testActivation()
{
    TestConf tc{};
}

void test::testParking()
{
    TestConf tc{};
    tc.dmiHandler->m_buttonHandler->parkBrakePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_PARK_DEACTIVATE);
    tc.dmiHandler->m_buttonHandler->parkBrakePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_PARK_ACTIVATE);
    tc.dmiHandler->m_buttonHandler->electricityBrakePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_EBRAKE_ACTIVATED);
    tc.dmiHandler->m_buttonHandler->electricityBrakePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_EBRAKE_DEACTIVATED);

    tc.dmiHandler->m_buttonHandler->magneticBrakePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_MGBRAKE_PRESSED);
    tc.dmiHandler->m_buttonHandler->magneticBrakeReleased();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_MGBRAKE_RELEASED);

}

QTEST_MAIN(test)

#include "tst_test.moc"
