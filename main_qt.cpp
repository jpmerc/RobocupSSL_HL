#include <iostream>
#include "InOut/InputStream.h"
#include "InOut/OutputStream.h"
#include "InOut/UDPOutputStream.h"
#include "Simulator/SimulatorCore.h"
#include <QApplication>
#include "include/GUI/MainBox.h"
#include "Logger/Logging.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainBox mainBox;
    mainBox.show();
    return mainBox.exec();
}
