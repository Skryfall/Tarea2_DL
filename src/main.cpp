#include <iostream>
#include <QApplication>
#include "ui/nrzi.h"

int main(int argc, char *argv[]) {

    QApplication* app = new QApplication(argc, argv);
    nrzi* nrziWindow = nrzi::getInstance();
    nrziWindow -> show();
    return app -> exec();
}
