#include "../headers/Painter.h"
#include "../headers/Read_XML.h"

Painter::Painter(int pNumber_Colors, string pRute_name){
    number_colors = pNumber_Colors;
    readfile *read = new readfile(pRute_name);
    SVG_text = read->getFile();
    countries = read->getData(SVG_text);

}

void Painter::to_update(string pFilename,string pAlgorim,vector<string> pUpdatedData){

    std::ofstream newFile("C:\\Users\\famil\\Downloads\\world2.svg", std::ios::app);
    std::fstream openedFile(pFilename);
    std::string line1;
    while (std::getline(openedFile, line1)) {
        if (line1 == "<path"){
            for (int index; index < pUpdatedData.size();index++){
                newFile<<pUpdatedData[index]<<endl;
            }
            newFile<<"</svg>";
            break;
        }
        newFile << line1 << std::endl;
    }
}

void Painter::paint_contries(vector<string> countries_and_colors) {

}