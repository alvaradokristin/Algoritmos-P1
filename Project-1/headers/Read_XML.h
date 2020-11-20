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
    readfile(string pFilename);
    string getFile(); // Reads whole file into a string buffer
    vector<string> getData(string pText);  // Gets collection of items between given tags

};
#endif