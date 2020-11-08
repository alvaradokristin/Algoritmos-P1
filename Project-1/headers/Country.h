//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_COUNTRY_H
#define PROJECT_1_COUNTRY_H

#include <string>
using namespace std;

namespace headers {
    /*
     * This is the class Country, this will have all the necesary information of a country and a pointer to create lists of countries
     * */
    class Country {

        friend class List;

    public:
        Country(string pId, string pName, string pDimensions);
        Country(string pId, string pName, string pDimensions, Country *pNextCountry);
        Country(string pId, string pName, string pDimensions, Country *pNextCountry, Country *pAdjacentList);
        Country *nextCntry;
        Country *adjList;


    //private:
        string id;
        string name;
        string dimensions;
    };
}

#endif //PROJECT_1_COUNTRY_H