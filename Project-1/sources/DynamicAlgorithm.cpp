#include "../headers/DynamicAlgorithm.h"

vector<int> Dynamic::AlterPriority (vector<int> pPrioritiesValue){
    int maxindex = 0;
    int priority = pPrioritiesValue.size();
    for (int indexround = 0; indexround < pPrioritiesValue.size(); indexround++){
        for (int index = 0;index < pPrioritiesValue.size();index++){
            if (pPrioritiesValue[index] > pPrioritiesValue[maxindex]){
                maxindex = index;
            }
        }
        priorities.at(maxindex) = priority;
        pPrioritiesValue.at(maxindex) = 0;
        priority--;
    }
}

void Dynamic::DynamicAlgoritm (List pListCountries,int pCounter){

    int limit;
    if ( pListCountries.listLength()-pCounter != 1){
        limit = 10;
    }else{
        limit = 11;
    }
    vector<Country*> ListToPaint;
    vector<int> counterforcountries;

    for (int pass = pCounter; pass < pCounter+limit;pass++){
        ListToPaint.push_back(pListCountries.getposition(pass));
    }
    

}