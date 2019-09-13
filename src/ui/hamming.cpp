#include "hamming.h"
#include "ui_hamming.h"
#include "nrzi.h"

hamming* hamming::hammingWindow = nullptr;

hamming::hamming(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hamming)
{
    ui->setupUi(this);
}

hamming::~hamming()
{
    delete ui;
}

hamming* hamming::getInstance() {
    if (!hammingWindow) {
        hammingWindow = new hamming;
    }
    return hammingWindow;
}

void hamming::toNRZIWindow() {
    nrzi* nrziWindow = nrzi::getInstance();
    nrziWindow->show();
}

void hamming::on_toNRZI_clicked() {
    toNRZIWindow();
    hide();
}

