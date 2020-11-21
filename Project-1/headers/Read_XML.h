#ifndef ALGORITMOS_P1_READ_XML_H
#define ALGORITMOS_P1_READ_XML_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Readfile;

struct Readfile {
    
    string filename;
    string encabezado;

// Function prototypes
    Readfile(string pFilename);
    string getFile(); // Reads whole file into a string buffer
    vector<string> getData(string pText);  // Gets collection of items between given tags

};
#endif

// Example
    /* string filename = "D:\\OneDrive\\Escritorio\\world.svg";

        Readfile *read = new Readfile(filename);
        string text =read->getFile();
        vector<string> all = read->getData(text);
        vector<string> alll;
        /*for ( string s : all )
        {
            cout << s << '\n';
        }*/

    /*Painter *paint = new Painter(3);
    paint->SVG_text = all;
    alll = paint->paint_contries(all,"AR",2);
    paint->to_update(filename,"Dymanic",alll,read->encabezado);

    cout << "Number of countries: " << alll.size() << endl;

    cout << "First country: \n" << alll.at(4) << '\n' << endl;*/