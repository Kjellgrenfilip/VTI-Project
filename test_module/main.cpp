#include <QCoreApplication>
#include <QThread>

#include "test_module.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test_Module tester{};

    return a.exec();
}
