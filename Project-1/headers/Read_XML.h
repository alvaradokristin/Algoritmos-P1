//
// Created by famil on 11/10/2020.
//

#ifndef ALGORITMOS_P1_READ_XML_H
#define ALGORITMOS_P1_READ_XML_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

// Function prototypes
string getFile( string filename );                         // Reads whole file into a string buffer
vector<string> getData( const string &text, string tag );  // Gets collection of items between given tags
void stripTags( string &text );                            // Strips any tags

#endif //ALGORITMOS_P1_READ_XML_H
