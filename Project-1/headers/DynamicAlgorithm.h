#ifndef PROJECT_1_DYNAMICALGORITHM_H
#define PROJECT_1_DYNAMICALGORITHM_H
#include <vector>
#include "../headers/Country.h"


using namespace std;

namespace headers {

    class Dynamic {

        friend class List;

    public:

        Dynamic();

        vector<int>CreatePriority (Country *pContriesEvalue);
        void DynamicAlgoritm (Country *pListCountries);

    private:

        vector<int> priorities;
        int colors_numbers;


    };

}


#endif //PROJECT_1_DYNAMICALGORITHM_H
