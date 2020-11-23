#include <iostream>
#include <vector>
//#include <chrono>

//#include "headers/Timer.h"
//#include "headers/List.h"
#include "headers/DivideConquer.h"
#include "sources/DivideConquer.cpp"
#include "sources/Read_XML.cpp"
#include "headers/Painter.h"
//#include "sources/Painter.cpp" -- Error

using namespace headers;
using namespace std;

int main() {

    string filename = "D:\\OneDrive\\Escritorio\\world.svg";

    Readfile *read = new Readfile(filename);
    string text =read->getFile();
    vector<string> all = read->getData(text);

    List newListDC;

    newListDC.create(all);

    newListDC.searchAdjacents();

    DivideConquer DC(7, filename, read->encabezado);
    DC.vectorDC = all;
    DC.listDC.first = newListDC.first;
    DC.divideList();

    /*cout << "======================================================================\nFinal list: " << endl;
    DC.listDC.printList();*/

    cout << "Number of countries: " << DC.listDC.listLength() << endl;
    cout << "Number of countries that were not painted: " << DC.countriesToColor << endl;
    cout << "Number of countries painted in white: " << DC.whiteCountries << endl;
    DC.updateMap();

    return 0;

}
