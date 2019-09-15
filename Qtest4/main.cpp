#include "mainwindow.h"
#include "hamming.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   for (int i=0;i<1;i++){
        Hamming::init(1);
        Hamming::firstLine("101010110001");
        Hamming::completeLines();
        Hamming::show();
        int *p=Hamming::getParity();
        Hamming::firstLine("101010110000");
        Hamming::completeLines();
        Hamming::show();
        int *p2=Hamming::getParity();
        Hamming::compareParity(p,p2);
        int* p3=Hamming::compareArray(p,p2);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
