#ifndef PROJECT_1_XML_PAINTER_H
#define PROJECT_1_XML_PAINTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class XMLPainter{

public:
    XMLPainter();

    vector<string> totalcolors;
    vector<string> color_to_use;
    int numberofcolors;

    string paint_contry (string pCountry,int pcolor);
    void SingColors ();
};
#endif //PROJECT_1_XML_PAINTER_H
