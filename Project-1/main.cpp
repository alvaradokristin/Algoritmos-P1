#include <iostream>
#include <vector>
//#include <chrono>

//#include "headers/Timer.h"
#include "headers/List.h"
#include "sources/Read_XML.cpp"
#include "sources/Painter.cpp"

using namespace headers;
using namespace std;

int main() {

    string filename = "C:\\Users\\famil\\Downloads\\world.svg";

    Readfile *read = new Readfile(filename);
    string text =read->getFile();
    vector<string> all = read->getData(text);
    vector<string> alll;
    /*for ( string s : all )
    {
        cout << s << '\n';
    }*/
    Painter *paint = new Painter(3);
    paint->SVG_text = all;
    alll = paint->paint_contries(all,"AR",2);
    paint->to_update(filename,"Dymanic",alll,read->encabezado);

    return 0;

}
