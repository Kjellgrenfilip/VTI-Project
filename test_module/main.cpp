#include <QCoreApplication>

#include "network_server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Network_Server n_Server{};

    return a.exec();
}
