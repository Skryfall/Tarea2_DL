//
// Created by kevin on 13/09/19.
//

#include <iostream>
#include "Converter.h"
#include <math.h>

Converter* Converter::converter = nullptr;

Converter* Converter::getInstance() {
    if (!converter) {
        converter = new Converter;
    }
    return converter;
}

char* Converter::hexABin(char *hex, char *res) {
    int cont=0;
    for (int i=0; i<3;i++)
    {
        if (hex[i]=='0'){
            res[cont]='0';
            res[cont+1]='0';
            res[cont+2]='0';
            res[cont+3]='0';
        }
        if (hex[i]=='1'){
            res[cont]='0';
            res[cont+1]='0';
            res[cont+2]='0';
            res[cont+3]='1';
        }
        if (hex[i]=='2'){
            res[cont]='0';
            res[cont+1]='0';
            res[cont+2]='1';
            res[cont+3]='0';
        }
        if (hex[i]=='3'){
            res[cont]='0';
            res[cont+1]='0';
            res[cont+2]='1';
            res[cont+3]='1';
        }
        if (hex[i]=='4'){
            res[cont]='0';
            res[cont+1]='1';
            res[cont+2]='0';
            res[cont+3]='0';
        }
        if (hex[i]=='5'){
            res[cont]='0';
            res[cont+1]='1';
            res[cont+2]='0';
            res[cont+3]='1';
        }
        if (hex[i]=='6'){
            res[cont]='0';
            res[cont+1]='1';
            res[cont+2]='1';
            res[cont+3]='0';
        }
        if (hex[i]=='7'){
            res[cont]='0';
            res[cont+1]='1';
            res[cont+2]='1';
            res[cont+3]='1';
        }
        if (hex[i]=='8'){
            res[cont]='1';
            res[cont+1]='0';
            res[cont+2]='0';
            res[cont+3]='0';
        }
        if (hex[i]=='9'){
            res[cont]='1';
            res[cont+1]='0';
            res[cont+2]='0';
            res[cont+3]='1';
        }
        if (hex[i]=='A'){
            res[cont]='1';
            res[cont+1]='0';
            res[cont+2]='1';
            res[cont+3]='0';
        }
        if (hex[i]=='B'){
            res[cont]='1';
            res[cont+1]='0';
            res[cont+2]='1';
            res[cont+3]='1';
        }
        if (hex[i]=='C'){
            res[cont]='1';
            res[cont+1]='1';
            res[cont+2]='0';
            res[cont+3]='0';
        }
        if (hex[i]=='D'){
            res[cont]='1';
            res[cont+1]='1';
            res[cont+2]='0';
            res[cont+3]='1';
        }
        if (hex[i]=='E'){
            res[cont]='1';
            res[cont+1]='1';
            res[cont+2]='1';
            res[cont+3]='0';
        }
        if (hex[i]=='F'){
            res[cont]='1';
            res[cont+1]='1';
            res[cont+2]='1';
            res[cont+3]='1';
        }
        if (hex[i]!='0'&&hex[i]!='1'&&hex[i]!='2'&&hex[i]!='3'&&hex[i]!='4'&&hex[i]!='5'&&hex[i]!='6'&&hex[i]!='7'&&hex[i]!='8'&&hex[i]!='9'&&hex[i]!='A'&&hex[i]!='B'&&hex[i]!='C'&&hex[i]!='D'&&hex[i]!='E'&&hex[i]!='F'){
            return const_cast<char *>("");}
        cont=cont+4;
    }
    return res;
}

int Converter::hexADec(char* hex) {
    int res=0;
    int cont=2;
    for (int i=0;i<3;i++)
    {
        if (hex[i]=='1'){
            res=res+pow(16,cont);}
        if (hex[i]=='2'){
            res=res+2*pow(16,cont);}
        if (hex[i]=='3'){
            res=res+3*pow(16,cont);}
        if (hex[i]=='4'){
            res=res+4*pow(16,cont);}
        if (hex[i]=='5'){
            res=res+5*pow(16,cont);}
        if (hex[i]=='6'){
            res=res+6*pow(16,cont);}
        if (hex[i]=='7'){
            res=res+7*pow(16,cont);}
        if (hex[i]=='8'){
            res=res+8*pow(16,cont);}
        if (hex[i]=='9'){
            res=res+9*pow(16,cont);}
        if (hex[i]=='A'){
            res=res+10*pow(16,cont);}
        if (hex[i]=='B'){
            res=res+11*pow(16,cont);}
        if (hex[i]=='C'){
            res=res+12*pow(16,cont);}
        if (hex[i]=='D'){
            res=res+13*pow(16,cont);}
        if (hex[i]=='E'){
            res=res+14*pow(16,cont);}
        if (hex[i]=='F'){
            res=res+15*pow(16,cont);}
        cont=cont-1;
    }
    return res;
}

bool Converter::hex3Dig(string ent) {
    return ent.length() <= 3;
}
