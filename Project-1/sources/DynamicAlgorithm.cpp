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
    //Create first priority queue
    for (int index  =0;index < pNumberColors;index++){
        priorities.push_back(index);
    }
    //Start timer
    timerDC.startTimer();
}

//Alters the priority queue by learning from a queue of a pseudo-color nucleus
void Dynamic::AlterPriority (vector<int> pPrioritiesValue){

    int priority = (pPrioritiesValue.size()-1);
    for (int indexround = 0; indexround < pPrioritiesValue.size(); indexround++){
        int maxindex = 0;
        for (int index = 0;index < pPrioritiesValue.size();index++){
            if (pPrioritiesValue[index] > pPrioritiesValue[maxindex]){
                maxindex = index;
            }
        }
        priorities.at(maxindex) = priority--;
        pPrioritiesValue.at(maxindex) = 0;
    }
}

//Create a dynamic algorithm, which takes 10 elements and examines the data with a priority queue
void Dynamic::DynamicAlgoritm (List pListCountries,int pCounter){

    int limit;
    if ( pListCountries.listLength()-pCounter != 11){
        limit = 10;
    }else{
        limit = 11;
    }
    //evaluate if it is your last iteration
    vector<int> counterforcountries; //create a color counter
    for (int index =0;index < colors_numbers;index++){
        counterforcountries.push_back(index);
    }
    int poscolortous;
    for (int pass = pCounter; pass < pCounter+limit;pass++){
        int position = pListCountries.getposition(pass)->adjVector->size();
        int available= colors_numbers;
        poscolortous = 0;
        bool pas = false;
        while (!pas){ //look for the adjacent ones
            pas = true;
            for (int index =0;index < position;index++){ //evaluates if the adjacent is painted
                if (pListCountries.getposition(pass)->adjVector->at(index)->isColored == true) { //evaluates if according to the priority queue it can paint
                    if (pListCountries.getposition(pass)->adjVector->at(index)->color == colors->at(poscolortous)) {
                        available--;
                        poscolortous ++;
                        if (available == 0){ //evaluate if there are still colors to paint
                            pas = true;
                            break;
                        }else{
                            pas = false;
                        }
                    }
                }
            }
        }
        if (available == 0){ //if not there are colors available, paint it white
            CountriesBlanc++;
            pListCountries.getposition(pass)->isColored = true;
            pListCountries.getposition(pass)->color="ffffff";
            DynamicCountries = paint_contries(DynamicCountries,pListCountries.getposition(pass)->id,12);
        }else{ //pint of necessary color
            counterforcountries.at(poscolortous)++;
            pListCountries.getposition(pass)->isColored = true;
            pListCountries.getposition(pass)->color=colors->at(poscolortous);
            DynamicCountries =paint_contries(DynamicCountries,pListCountries.getposition(pass)->id,poscolortous);
        }
    }
    Sleep(3000);
    // This will update the timer and print it
    timerDC.timeStamp();
    //update document svg
    to_update(Filename,"Dynamic",DynamicCountries,HeaderFile,CountriesBlanc,((timerDC.elapsed.count() / 1000)));
    //Code output parameter
    if (limit != 11){
        AlterPriority(counterforcountries);
        DynamicAlgoritm (pListCountries,pCounter+limit);
    }
}