#include "../headers/Painter.h"
#include "../headers/Read_XML.h"
#include "../headers/XML_Painter.h"
Painter::Painter(int pNumber_Colors, string pRute_name){
    number_colors = pNumber_Colors;
    readfile *read = new readfile(pRute_name);

}

void Painter::to_update(){

}