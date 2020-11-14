#ifndef PROJECT_1_PAINTER_H
#define PROJECT_1_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Painter{

    Painter(int pNumber_Colors,string Rute_name);
    int number_colors;
    string SVG_text;
    vector<string>countries;
    vector<string>colors;

    void to_update(string,string,vector<string>);
    void paint_contries(vector<string> countries_and_colors);

};




#endif //PROJECT_1_PAINTER_H
