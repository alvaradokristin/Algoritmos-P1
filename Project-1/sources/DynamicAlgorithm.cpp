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

    vector<Country> ListToPaint;
    vector<int> counterforcountries;
    for (int pass = pCounter; pass < pCounter+10;pass++){
        
    }

}