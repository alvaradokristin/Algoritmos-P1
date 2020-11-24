#include "../sources/Painter.cpp"
#include <windows.h>

using namespace headers;
using namespace std;

Dynamic::Dynamic(int pNumberColors,vector<string> pDynamicCountries,string pFilename, string pHeaderFile) : Painter(pNumberColors) {
    colors_numbers = pNumberColors;
    DynamicCountries = pDynamicCountries;
    Filename =pFilename;
    HeaderFile = pHeaderFile;
    CountriesBlanc =0;
    for (int index  =0;index < pNumberColors;index++){
        priorities.push_back(index);
    }

}

void Dynamic::AlterPriority (vector<int> pPrioritiesValue){
    int maxindex = 0;
    int priority = pPrioritiesValue.size()-1;
    for (int indexround = 0; indexround < pPrioritiesValue.size(); indexround++){
        for (int index = 0;index < pPrioritiesValue.size();index++){
            if (pPrioritiesValue[index] > pPrioritiesValue[maxindex]){
                maxindex = index;
            }
        }
        priorities.at(maxindex) = priority--;
        pPrioritiesValue.at(maxindex) = 0;
        maxindex=0;
    }
}

void Dynamic::DynamicAlgoritm (List pListCountries,int pCounter){

    int limit;
    if ( pListCountries.listLength()-pCounter != 11){
        limit = 10;
    }else{
        limit = 11;
    }
    vector<Country*> ListToPaint;
    vector<int> counterforcountries;
    for (int index =0;index < colors_numbers;index++){
        counterforcountries.push_back(index);
    }
    int poscolortous=0;
    for (int index =0;index < priorities.size();index++){
    }
    for (int pass = pCounter; pass < pCounter+limit;pass++){
        int position = pListCountries.getposition(pass)->adjVector->size();
        int available= colors_numbers;
        poscolortous = 0;
        bool pas = false;
        while (!pas){
            pas = true;
            for (int index =0;index < position;index++){
                if (pListCountries.getposition(pass)->adjVector->at(index)->isColored == true) {
                    if (pListCountries.getposition(pass)->adjVector->at(index)->color == colors->at(poscolortous)) {
                        available--;
                        poscolortous ++;
                        if (available == 0){
                            pas = true;
                            break;
                        }else{
                            pas = false;
                        }
                    }
                }
            }
        }
            if (available == 0){
                CountriesBlanc++;
                pListCountries.getposition(pass)->isColored = true;
                pListCountries.getposition(pass)->color="ffffff";
                DynamicCountries = paint_contries(DynamicCountries,pListCountries.getposition(pass)->id,12);
            }else{
                counterforcountries.at(poscolortous)++;
                pListCountries.getposition(pass)->isColored = true;
                pListCountries.getposition(pass)->color=colors->at(poscolortous);
                DynamicCountries =paint_contries(DynamicCountries,pListCountries.getposition(pass)->id,poscolortous);
            }
        }
        //Sleep(10000);
        timerDC.timeStamp();
        to_update(Filename,"Dynamic",DynamicCountries,HeaderFile,CountriesBlanc,((timerDC.elapsed.count() / 1000)));
    if (limit != 11){
        AlterPriority(counterforcountries);
        DynamicAlgoritm (pListCountries,pCounter+limit);
    }
}