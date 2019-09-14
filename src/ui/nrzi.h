#ifndef NRZI_H
#define NRZI_H

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include "../logic/Converter.h"

namespace Ui {
class nrzi;
}

class nrzi : public QMainWindow
{
    Q_OBJECT

public:
    explicit nrzi(QWidget *parent = nullptr);
    ~nrzi();
    static nrzi* getInstance();

    virtual void paintEvent(QPaintEvent *event);

public slots:
    void toHammingWindow();

private:
    Ui::nrzi *ui;
    static nrzi* nrziWindow;
    Converter* converter = Converter::getInstance();
    int state = 0;
    char* bin;
    int binArray[12];
    QLabel* bitArray[12];

private slots:
    void on_toHamming_clicked();
    void on_readyButton_clicked();
};

#endif // NRZI_H
