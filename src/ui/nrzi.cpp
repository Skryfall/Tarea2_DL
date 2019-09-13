#include <iostream>
#include "nrzi.h"
#include "ui_nrzi.h"
#include "hamming.h"


using namespace std;

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

void nrzi::on_readyButton_clicked(){
    QString qhex = ui->hexEntry->displayText();
    string hex = qhex.toStdString();
    if (converter->hex3Dig(hex)){
        strcpy(converter->hex,hex.c_str());
        string bin = converter->hexABin(converter->hex, converter->bin);
        if (bin != ""){
            ui->binaryLabel->setText(QString::fromStdString(bin));
        }
    }
    ui->hexEntry->setText("");
}

