//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"

using namespace cntry;
using namespace std;

typedef Country *pointerCntry;

Country::Country(string pId, string pName, string pDimensions) {
    id = pId;
    name = pName;
    dimensions = pDimensions;
    nextCntry = NULL;
    adjList = NULL;
}

Country::Country(string pId, string pName, string pDimensions, Country *pNextCountry) {
    id = pId;
    name = pName;
    dimensions = pDimensions;
    nextCntry = pNextCountry;
    adjList = NULL;
}

Country::Country(string pId, string pName, string pDimensions, Country *pNextCountry, Country *pAdjacentList) {
    id = pId;
    name = pName;
    dimensions = pDimensions;
    nextCntry = pNextCountry;
    adjList = pAdjacentList;
}