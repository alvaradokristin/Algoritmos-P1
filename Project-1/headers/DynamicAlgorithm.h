#ifndef PROJECT_1_DYNAMICALGORITHM_H
#define PROJECT_1_DYNAMICALGORITHM_H
#include <vector>
#include "Painter.h"
#include "List.h"
#include "Timer.h"

using namespace std;

namespace headers{
    class Dynamic : public Painter{

        friend class Program;

    public:
        Dynamic(int pNumberColors,vector<string> pDynamicCountries,string pFilename, string pHeaderFile);
        void AlterPriority (vector<int> pPriorities);
        void DynamicAlgoritm (List pListCountries,int PCounter);

    private:
        vector<string> DynamicCountries;
        string Filename;
        string HeaderFile;
        vector<int> priorities;
        int colors_numbers;
        int CountriesBlanc;
        Timer timerDC;
    };

}

#endif //PROJECT_1_DYNAMICALGORITHM_H
