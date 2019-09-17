#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QDebug>
#include "../logic/hamming.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int* actualParity;
    QString actualInput;
    bool Changed;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* getInstance();
    void setBin(char* bin);

public slots:
    void toNRZIWindow();

private slots:
    void on_pushButton_clicked();
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_returnToNRZI_clicked();

private:
    Ui::MainWindow *ui;
    static MainWindow* hammingWindow;
    string bin;
};
#endif // MAINWINDOW_H
