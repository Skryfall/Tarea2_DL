#ifndef NRZI_H
#define NRZI_H

#include <QMainWindow>

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

public slots:
    void toHammingWindow();

private:
    Ui::nrzi *ui;
    static nrzi* nrziWindow;

private slots:
    void on_toHamming_clicked();
};

#endif // NRZI_H
