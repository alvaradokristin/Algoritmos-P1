#include "../headers/Painter.h"


Painter::Painter(int pNumber_Colors){
    write = new XMLPainter();
    write ->SingColors();
    colors = &write->color_to_use;

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

void Painter::paint_contries(vector<string> pCountries,string pCountry,int pColor) {
    string buffer;
    bool pass = false;
    int counter = 0;

    for (int indexC = 0; indexC < pCountries.size(); indexC++)
    {
        string CountryToCheck = pCountries[indexC];
        for (int indexParser = 0; indexParser <CountryToCheck.length(); indexParser++){
            if (CountryToCheck[indexParser-3] == 'i' and CountryToCheck[indexParser-2] == 'd' and CountryToCheck[indexParser-1] == '=' and CountryToCheck[indexParser] == '"'){
                pass = true;
            }else if (pass == true and CountryToCheck[indexParser] == '"'){
                pass = false;
            }
            if (pass = true){
                buffer += CountryToCheck[indexParser];
            }
        }
        if (buffer == pCountry){
            write->paint_contry(buffer,pColor);
        }
    }
}