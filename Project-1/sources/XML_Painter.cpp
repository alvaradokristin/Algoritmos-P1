#include "../headers/XML_Painter.h"

XMLPainter::XMLPainter() {
    numberofcolors = 0;
    totalcolors={"009688","000000","76448A","B7950B","229954","BA4A00","979A9A","283747","FF00FF","00FFFF","00FF00","FFFFFF","808000"}; // 12: "FFFF00"
}
void XMLPainter::SingColors (){
    for (int colors = 0; colors < numberofcolors;colors++){
        color_to_use.push_back(totalcolors[colors]);
        //cout<<color_to_use[colors]<<endl;
    }
}
string XMLPainter::paint_contry(string pCountry, int pcolor) {
    string buffer;
    bool pass = false;
    int counter = 0;
    string color;

    if (pcolor != 12) {
        color = color_to_use[pcolor];
    }
    else {
        color = "FFFFFF";
    }
    for (int index = 0; index < pCountry.length(); index++)
    {
        if (pCountry[index-3] == 'l' and pCountry[index-2] == ':' and pCountry[index-1] == '#'){
            pass = true;
        }else if (pass  == true and pCountry[index] == ';'){
            pass = false;
        }
        if (pass == true){
            pCountry[index] = color[counter++];
        }
    }
    return pCountry;
}

