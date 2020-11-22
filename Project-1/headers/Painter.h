#ifndef PROJECT_1_PAINTER_H
#define PROJECT_1_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
//#include "../headers/XML_Painter.h"
#include "../sources/XML_Painter.cpp"

using namespace std;

class Painter{
public:

    Painter(int pNumber_Colors);
    int number_colors;
    vector<string> SVG_text;
    vector<string> *colors;
    XMLPainter *write;

    void to_update(string,string,vector<string>,string);
    vector<string> paint_contries(vector<string> countries,string country,int color);

};




#endif //PROJECT_1_PAINTER_H
