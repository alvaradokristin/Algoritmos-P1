#ifndef PROJECT_1_DYNAMICALGORITHM_H
#define PROJECT_1_DYNAMICALGORITHM_H
#include <vector>
#include "../sources/List.cpp"


using namespace std;

namespace headers {

    class Dynamic {

        friend class List;

    public:

        Dynamic();

        vector<int>AlterPriority (vector<int> pPriorities);
        void DynamicAlgoritm (List pListCountries,int PCounter);

    private:

        vector<int> priorities;
        int colors_numbers;


    };

}


#endif //PROJECT_1_DYNAMICALGORITHM_H
