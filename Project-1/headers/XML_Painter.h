#ifndef PROJECT_1_XML_PAINTER_H
#define PROJECT_1_XML_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class XML_Painter{

    XML_Painter(int pNumberColor);

    vector<string> totalcolors;
    vector<string> color_to_use;
    int numberofcolors;

    string paint_contry (string colors,int color);
    void SingColors ();


};
#endif //PROJECT_1_XML_PAINTER_H
