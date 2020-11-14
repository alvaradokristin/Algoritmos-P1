#include "../headers/XML_Painter.h"

XML_Painter::XML_Painter(int pNumberColor) {
    color_to_use = null;
    numberofcolors = pColortouse;
    totalcolors={"#009688","#000000","#76448A","#B7950B","#229954","#BA4A00","#979A9A","#283747","#FF00FF","#00FFFF","#00FF00","#FFFF00","#808000"};
}
void XML_Painter::SingColors (){
    for (int colors; colors < numberofcolors;colors++){
        color_to_use.push_back(totalcolors[colors]);
    }
}
string XML_Painter::paint_contry(string pCountry, int color) {
    string buffer;
    bool pass = false;
    int counter = 0;

    for (int index = 0; index < pCountry.length(); index++)
    {
        if (pCountry[index-2] == 'l' and pCountry[index-1] == ':' and pCountry[index] == '#'){
            pass = true;
        }else if (pCountry[index] == ';'){
            pass = false;
        }
        if (pass = true){
            pCountry[index] = color_to_use[color][counter++];
        }
    }
    return pCountry;
}

