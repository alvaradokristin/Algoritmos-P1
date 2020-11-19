#ifndef PROJECT_1_PAINTER_H
#define PROJECT_1_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "../headers/XML_Painter.h"
using namespace std;

class Painter{

    Painter(int pNumber_Colors);
    int number_colors;
    string SVG_text;
    vector<string> *colors;
    XMLPainter *write;

    void to_update(string,string,vector<string>);
    void paint_contries(vector<string> countries,string country,int color);

};




#endif //PROJECT_1_PAINTER_H
