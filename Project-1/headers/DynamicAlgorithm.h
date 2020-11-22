#ifndef PROJECT_1_DYNAMICALGORITHM_H
#define PROJECT_1_DYNAMICALGORITHM_H
#include <vector>
#include "Painter.h"
#include "List.h"

using namespace std;

namespace headers{
    class Dynamic : public Painter{
    public:
        Dynamic(int pNumberColors,vector<string> pDynamicCountries,string pFilename, string pHeaderFile);
        void AlterPriority (vector<int> pPriorities);
        int GetPosLaterColor(int pAvailable);
        int GetMinColor();
        void DynamicAlgoritm (List pListCountries,int PCounter);
    private:
        vector<string> DynamicCountries;
        string Filename;
        string HeaderFile;
        int countriesBlanc;
        vector<int> priorities;
        int colors_numbers;
        int CountriesBlanc;
    };

}


#endif //PROJECT_1_DYNAMICALGORITHM_H
