
#include "../headers/Read_XML.h"

Readfile::Readfile (string pFilename) {
    filename = pFilename;
}
//======================================================================
string Readfile::getFile()
{
    string buffer;
    char c;

    ifstream in( filename );   if ( !in ) { /*cout << filename << " not found";*/   exit( 1 ); }
    while ( in.get( c ) ) buffer += c;
    in.close();

    return buffer;
}
//======================================================================
vector<string> Readfile::getData(string pText )
{
    vector<string> collection;
    string buffer;
    bool pass = false;
    bool counter = true;

    for (int index = 0; index < pText.length(); index++)
    {
        if (pText[index] == '<' and pText[index+1] == 'p' and pText[index+2] == 'a'){
            pass = true;
            counter= false;
        }else if (counter == true){
            encabezado+=pText[index];
        }else if (pass == true and pText[index-2] == ' ' and pText[index-1] == '/' and pText[index] == '>'){
            pass = false;
            buffer += ">";
            if (buffer != " "){
                collection.push_back(buffer);
            }
            buffer = " ";
        }
        if (pass == true){
            buffer += pText[index];
        }
    }
    return collection;
}