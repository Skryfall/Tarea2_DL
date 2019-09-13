//
// Created by kevin on 13/09/19.
//

#ifndef TAREA2_DL_CONVERTER_H
#define TAREA2_DL_CONVERTER_H

#include <string>

using namespace std;

class Converter {

public:
    static Converter* getInstance();
    string hexABin(char* hex, char* res);
    bool hex3Dig(string ent);
    char hex[3];
    char bin[12];

private:
    static Converter* converter;
};


#endif //TAREA2_DL_CONVERTER_H
