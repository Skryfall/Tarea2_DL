#include "nrzi.h"
#include "ui_nrzi.h"
#include "hamming.h"

nrzi* nrzi::nrziWindow = nullptr;

nrzi::nrzi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nrzi)
{
    ui->setupUi(this);

}

nrzi::~nrzi(){
    delete ui;
}

nrzi* nrzi::getInstance() {
    if (!nrziWindow) {
        nrziWindow = new nrzi;
    }
    return nrziWindow;
}

void nrzi::toHammingWindow(){
    hamming* hammingWindow = hamming::getInstance();
    hammingWindow->show();
}

void nrzi::on_toHamming_clicked(){
    toHammingWindow();
    hide();
}

