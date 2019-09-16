#include "hamming.h"


int Hamming::arr[filas][columnas]={};
int Hamming::parity=0;

void Hamming::init(int p,int valor)
{
    Hamming::parity=p;
    int i, j;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
         arr[i][j]=valor;
         }
    }
}

void Hamming::show()
{
    QString line;
    int i, j;
    for (i = 0; i < filas; i++) {
        line="";
        for (j = 0; j < columnas; j++) {
          line+="   "+QString::number( arr[i][j]);
         }
     //qDebug().noquote()<<line;
    }
    //qDebug()<<"---------------------";
}

bool Hamming::firstLine(QString input)
{
    if (input.length()!=12) return false;
    bool bits[12];
    for (int i=0 ; i<12 ;i++){
        if (input.at(i)=='0'){
            bits[i]=0;
        }
        else if (input.at(i)=='1'){
            bits[i]=1;
        }
        else{
            return false;
        }
    }
    int c=0;
    for (int j : digitos) {
    arr[0][j]=bits[c];
    arr[6][j]=bits[c];
    c++;
    }
    return true;
}

void Hamming::completeLines()
{
    int begin;
    int salto;
    for (int i=1;i<filas-1;i++){
        begin=paridad[i-1];
        salto=(int)pow(2,(i-1));
        //printf("%d,%d\n",begin,salto);
        int col=begin;
        int suma=0;
        while (col<columnas){
            for (int j=0;j<salto && col<columnas;j++){
                arr[i][col]=arr[0][col];
                suma+=arr[0][col];
                col++;
            }
            col+=salto;
        }
        arr[6][begin]=(suma+parity)%2;
        arr[i][begin]=(suma+parity)%2;
    }
}

int *Hamming::getParity()
{
    int* parity=new int[17];
    for(int i=0;i<17;i++){
       parity[i]=arr[filas-1][i];
    }
    return parity;
}

int Hamming::compareParity(int *P1, int* P2)
{
    int error=0;
    int pot=0;
    for(int i:paridad){
       if (P1[i]!=P2[i]){
           //qDebug()<<"error"<<i<<pot;
           error+=pow(2,pot);
       }
       pot++;
    }
    //qDebug()<<error;
    return error;
}

int *Hamming::getPares()
{
    int* parity=new int[5];
    for (int i=0;i<5;i++){
        parity[i]=paridad[i];
    }
    return parity;
}

int *Hamming::compareArray(int *P1, int *P2)
{
    int* errorArray=new int[5];
    int c=0;
    for(int i:paridad){
       if (P1[i]!=P2[i]){
           errorArray[c]=1;
       }
       else{
           errorArray[c]=0;
       }
       //qDebug()<<c<<errorArray[c]<<P1[i]<<P2[i];
       c++;
    }
    return errorArray;
}
