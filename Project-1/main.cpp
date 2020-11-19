#include <iostream>
#include <vector>
//#include <chrono>

//#include "headers/Timer.h"
#include "headers/List.h"
#include "sources/Read_XML.cpp"
#include "sources/XML_Painter.cpp"

using namespace headers;
using namespace std;

int main() {

    string filename = "C:\\Users\\famil\\Downloads\\world.svg";

    readfile *read = new readfile(filename);
    string text =read->getFile();
    vector<string> all = read->getData(text);

    for ( string s : all )
    {
        cout << s << '\n';
    }

    


    return 0;


}
