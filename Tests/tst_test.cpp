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
    void testPantUp();
    void testPantDown();
    void testMainBreaker();
    void testHeating();
    void testDoors();
    void testReverse();
    void testActivation();

    void testETCS_A();

    void testBreaks();
    void testEmergencyInfo();

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

void test::testPantUp()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->pantUpPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PANTUP_ACTIVATION);

    tc.testModule->resetStates();
    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);
    tc.dmiHandler->m_buttonHandler->pantUpPressed();
    delay(3500);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PANTUP_ACTIVATION_MAINBREAKER);

}

void test::testPantDown()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->pantDownPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_PANTDOWN_ACTIVATION);
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
    tc.dmiHandler->m_buttonHandler->pantUpPressed();
    delay(3500);
    tc.dmiHandler->m_buttonHandler->mainBreakerPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_MAINBREAKER_ACTIVATION_PANTUP);
}

void test::testHeating()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->heatingPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_HEAT_ACTIVATION_NOPANT);

    tc.dmiHandler->m_buttonHandler->pantUpPressed();
    delay(3300);
    tc.dmiHandler->m_buttonHandler->heatingPressed();
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::VOLTAGE_HEAT_ACTIVATION_PANT);
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

void test::testBreaks()
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

    /*tc.dmiHandler->m_buttonHandler->parkBrakePressed(); //Deactivate park_brake
    tc.testModule->m_jsonEx(VTI_DMI::VELOCITY, 15); //Set velocity > 0
    tc.dmiHandler->m_buttonHandler->parkBrakePressed(); //Activate park_brake. Should not be possible
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::BRAKES_PARK_VELOCITY);*/


}

void test::testEmergencyInfo()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->nboPressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::NBO_BUTTON_PRESSED);

    tc.dmiHandler->m_buttonHandler->firePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::FIRE_BUTTON_PRESSED);

    tc.dmiHandler->m_buttonHandler->nboPressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::SOLID_NBO_BUTTON_PRESSED);

    tc.dmiHandler->m_buttonHandler->firePressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::SOLID_FIRE_BUTTON_PRESSED);

    tc.dmiHandler->m_buttonHandler->receiptPressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::RECIEPT_BUTTON_PRESSED);

    // Press reciept in warning states
    tc.dmiHandler->m_buttonHandler->firePressed();
    tc.dmiHandler->m_buttonHandler->nboPressed();
    tc.dmiHandler->m_buttonHandler->receiptPressed();
    QCOMPARE(tc.dmiHandler->m_latestUpdate, VTI_TESTCASE::RECIEPT_BUTTON_PRESSED);
}

void test::testETCS_A()
{
    TestConf tc{};
    tc.testModule->updateSpeedLimit(-1);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::SPEEDLIMIT), "");

    tc.testModule->updateSpeedLimit(120);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::SPEEDLIMIT), "120");

    tc.testModule->updateDistance(104);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE), "100");

    tc.testModule->updateDistance(105);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE), "110");

    tc.testModule->updateDistance(-10);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE), "");

    tc.testModule->updateDistance(0);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE_BAR), 0);

    tc.testModule->updateDistance(100);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE_BAR), 33);

    tc.testModule->updateDistance(1000);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE_BAR), 186);

    tc.testModule->updateDistance(3000);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE_BAR), 186);

    tc.testModule->updateDistance(-100);
    delay(100);
    QCOMPARE(tc.dmiHandler->m_latestUpdate.value(VTI_DMI::DISTANCE_BAR), 0);
}

QTEST_MAIN(test)

#include "tst_test.moc"
