#ifndef HAMMING_H
#define HAMMING_H

#include <QDebug>
#include <stdio.h>
#include <cmath>
#include <QString>

const int filas = 7; //filas
const int columnas = 17; //columnas
const int paridad[]={0,1,3,7,15};
const int digitos[]={2,4,5,6,8,9,10,11,12,13,14,16};


class Hamming
{
private:
    static int parity;

public:
    static QString LastParity;
    static QString ActualParity;
    static int Error;
    static int arr[filas][columnas];
    static Hamming& getInstance()
            {
                static Hamming instance; // Guaranteed to be destroyed.
                                      // Instantiated on first use.
                return instance;
            }
    static void init(int parity,int valor=2);
    static void show();
    static bool firstLine(QString input);
    static void completeLines();
    static int* getParity();
    static int compareParity(int* P1,int* P2);
    static int* getPares();
    static int* compareArray(int* P1,int* P2);
    static int* getFinal();
    static void findError(QString input);
};

#endif // HAMMING_H
