#include "../headers/Painter.h"

Painter::Painter(int pNumber_Colors){
    write = new XMLPainter();
    write -> numberofcolors = pNumber_Colors;
    write -> SingColors();
    colors = &write->color_to_use;

}
// Update the svg document in the assigned address and with the algorithm name
void Painter::to_update(string pFilename,string pAlgorim,vector<string> pUpdatedData,string pData,int pColorBlank,double pTime){

    std::ofstream newFile("D:\\OneDrive\\Escritorio\\world " + pAlgorim + " algorithm.svg", std::ios::trunc);
    newFile<<pData;
            for (int index=0; index < pUpdatedData.size();index++){
                newFile<<pUpdatedData[index]<<endl;
            }
            //keep the number of countries blank
            newFile<< "<text x='1200' y= '830' font-size='2em' fill='black'>Countries in white: "+std::to_string(pColorBlank)+"</text>";
            //save the save round time
            newFile<< "<text x='1200' y= '860' font-size='2em' fill='black'>Time: "+std::to_string(pTime)+"</text>";
            newFile<<"</svg>";
}

// Paint a specific country based on the position of the color in the color list
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