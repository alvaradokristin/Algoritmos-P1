#ifndef ALGORITMOS_P1_READ_XML_H
#define ALGORITMOS_P1_READ_XML_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct readfile {
    string filename;
    bool stripOtherTags;
    readfile(string pfilename);

// Function prototypes

    string getFile();                                        // Reads whole file into a string buffer
    vector<string> getData(const string &pText);  // Gets collection of items between given tags

};
#endif
//ALGORITMOS_P1_READ_XML_H
/*
 * how to use the funtion in main
int main()
{string filename = "C:\\Users\\famil\\Downloads\\archivo.xml";
    string tag = "id";
    bool stripOtherTags = true;

    string text = getFile( filename );
    cout<<text<<endl;
    vector<string> all = getData( text, tag );
    for ( string &s : all )
    {
        if ( stripOtherTags ) stripTags( s );
        cout << s << '\n';

    }
}
*/