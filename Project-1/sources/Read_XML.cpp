#include "../headers/Read_XML.h"
readfile::readfile (string pFilename) {
    filename = pFilename;
}
//======================================================================
string readfile::getFile()
{
    string buffer;
    char c;

    ifstream in( filename );   if ( !in ) { cout << filename << " not found";   exit( 1 ); }
    while ( in.get( c ) ) buffer += c;
    in.close();

    cout<<buffer<<endl;

    return buffer;
}
//======================================================================
vector<string> readfile::getData(string pText )
{
    vector<string> collection;
    string buffer;
    bool pass = false;

    for (int index = 0; index < pText.length(); index++)
    {
        if (pText[index] == '<' and pText[index+1] == 'p' and pText[index+2] == 'a'){
            pass = true;
        }else if (pText[index-2] == ' ' and pText[index-1] == '/' and pText[index] == '>'){
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