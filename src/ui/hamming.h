#ifndef HAMMING_H
#define HAMMING_H

#include <QMainWindow>

namespace Ui {
class hamming;
}

class hamming : public QMainWindow
{
    Q_OBJECT

public:
    explicit hamming(QWidget *parent = nullptr);
    ~hamming();
    static hamming* getInstance();

public slots:
    void toNRZIWindow();

private:
    Ui::hamming *ui;
    static hamming* hammingWindow;

private slots:
    void on_toNRZI_clicked();

};

#endif // HAMMING_H
