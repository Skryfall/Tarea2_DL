#include <iostream>
#include <QtWidgets>
#include "nrzi.h"
#include "ui_nrzi.h"
#include "../logic/hamming.h"
#include "mainwindow.h"


using namespace std;

nrzi* nrzi::nrziWindow = nullptr;

nrzi::nrzi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nrzi)
{
    ui->setupUi(this);
    bitArray[0] = ui->bit1;
    bitArray[1] = ui->bit2;
    bitArray[2] = ui->bit3;
    bitArray[3] = ui->bit4;
    bitArray[4] = ui->bit5;
    bitArray[5] = ui->bit6;
    bitArray[6] = ui->bit7;
    bitArray[7] = ui->bit8;
    bitArray[8] = ui->bit9;
    bitArray[9] = ui->bit10;
    bitArray[10] = ui->bit11;
    bitArray[11] = ui->bit12;

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

void nrzi::paintEvent(QPaintEvent* event){
    int x1 = 100;
    int x2 = 50;
    int y1 = 150;
    int y2 = 300;
    QPainter line(this);
    QPen pen(Qt::black);
    pen.setWidth(5);

    line.setPen(pen);
    line.drawLine(50, 150, 50, 300);
    line.drawLine(50, 225, 700, 225);

    pen.setWidth(1);
    line.setPen(pen);
    for (int i = 0; i < 12; i++){
        line.drawLine(x1, y1, x1, y2);
        x1 += 50;
    }

    if (state == 1){
        QPen pen2(Qt::red);
        pen2.setWidth(5);
        line.setPen(pen2);
        x1 = 50;
        x2 = 50;
        y1 = 188;
        y2 = 188;
        bool alto = true;
        for (int i = 0; i < 12; i++) {
            if(bin[i] == '0'){
                bitArray[i]->setText("0");
                y2 = y1;
                x1 = x2;
                x2 += 50;
                line.drawLine(x1, y1, x2, y2);
                x1 = x2;
            }else{
                bitArray[i]->setText("1");
                x2 = x1;
                y2 = y1;
                if (alto){
                    y2 += 75;
                    line.drawLine(x1, y1, x2, y2);
                    y1 = y2;
                    x1 = x2;
                    x2 += 50;
                    line.drawLine(x1, y1, x2, y2);
                    x1 = x2;
                    alto = false;
                }else{
                    y2 -= 75;
                    line.drawLine(x1, y1, x2, y2);
                    y1 = y2;
                    x1 = x2;
                    x2 += 50;
                    line.drawLine(x1, y1, x2, y2);
                    x1 = x2;
                    alto = true;
                }
            }
        }
    }
}

void nrzi::toHammingWindow(){
    MainWindow* hammingWindow = MainWindow::getInstance();
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
        bin = converter->hexABin(converter->hex, converter->bin);
        dec = converter->hexADec(converter->hex);
        if (strlen(bin) != 0){;
            MainWindow* mainWindow = MainWindow::getInstance();
            mainWindow->setBin(bin);
            ui->binaryLabel->setText(QString::fromUtf8(bin));
            ui->decimalLabel->setText(QString::number(dec));
            state = 1;
            update();
        }
    }
    ui->hexEntry->setText("");
}
