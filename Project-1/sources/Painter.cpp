#include "../headers/Painter.h"

Painter::Painter(int pNumber_Colors){
    write = new XMLPainter();
    write->numberofcolors = pNumber_Colors;
    write ->SingColors();
    colors = &write->color_to_use;

}

void Painter::to_update(string pFilename,string pAlgorim,vector<string> pUpdatedData,string pData){

    std::ofstream newFile("C:\\Users\\famil\\Downloads\\world"+pAlgorim+".svg", std::ios::trunc);
    newFile<<pData;
            for (int index=0; index < pUpdatedData.size();index++){
                cout<<pUpdatedData[index]<<endl;
                newFile<<pUpdatedData[index]<<endl;
            }
            newFile<<"</svg>";
}

vector<string> Painter::paint_contries(vector<string> pCountries,string pCountry,int pColor) {
    string buffer;
    bool pass = false;
    bool counter = true;

    for (int indexC = 0; indexC < pCountries.size(); indexC++)
    {
        string CountryToCheck = pCountries[indexC];

        for (int indexParser = 0; indexParser < CountryToCheck.length(); indexParser++){

            if ( CountryToCheck[indexParser-4] == 'i' and CountryToCheck[indexParser-3] == 'd' and CountryToCheck[indexParser-2] == '=' and CountryToCheck[indexParser-1] == '"'){
                pass = true;
            }else if (pass == true and CountryToCheck[indexParser] == '"'){
                counter = false;
                pass = false;
            }
            if (pass == true and counter == true){
                buffer += CountryToCheck[indexParser];
            }
        }
        if (buffer == pCountry){
            pCountries[indexC] = write->paint_contry(pCountries[indexC],pColor);
            return pCountries;
        }else{
            buffer = "";
            counter=true;
        }
    }
    return pCountries;
}