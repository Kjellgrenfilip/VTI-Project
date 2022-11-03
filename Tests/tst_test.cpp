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
    test();
    ~test();

private slots:
    void test_case1();
    void testPontUp();
};

test::test()
{

}

test::~test()
{

}

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
    DMI_Handler* dmiHandler{};
};

void test::test_case1()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

void test::testPontUp()
{
    TestConf tc{};

    tc.dmiHandler->m_buttonHandler->pontUpPressed();
    delay(100);

    QCOMPARE(tc.dmiHandler->m_latestUpdate, JSON_TESTS::JSON_PONTUP_TEST);
}

QTEST_MAIN(test)

#include "tst_test.moc"
