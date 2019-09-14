//
// Created by kevin on 13/09/19.
//

#include <iostream>
#include "Converter.h"

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

bool Converter::hex3Dig(string ent) {
    return ent.length() <= 3;
}
