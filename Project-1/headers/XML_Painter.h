#ifndef PROJECT_1_XML_PAINTER_H
#define PROJECT_1_XML_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class XML_Painter{

    XML_Painter(int pColortouse);

    vector<string> totalcolors;
    vector<string> color_to_use;
    vector<string> countries;

    void paint_contry ();


};
#endif //PROJECT_1_XML_PAINTER_H
