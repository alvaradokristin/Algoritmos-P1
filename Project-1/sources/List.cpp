//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"
#include "../headers/List.h"

using namespace cntry;
using namespace lst;
using namespace std;

typedef Country *pointerCntry;

List::List() {first = current = NULL; }

bool List::isListEmpty() { return first == NULL ;}

// This method will add a new Country at the beginning of the list
void List::addBeginning(string pId, string pName, string pDimensions) {
    if (!isListEmpty()) {
        first = new Country(pId, pName, pDimensions, first);
    }
    else {
        first = new Country(pId, pName, pDimensions);
    }
}

// This method will add a new Country at the end fo the list
void List::addEnd(string pId, string pName, string pDimensions) {
    if (!isListEmpty()) {
        pointerCntry auxPointer = first;
        while (auxPointer -> nextCntry != NULL) {
            auxPointer = auxPointer -> nextCntry;
        }
        auxPointer -> nextCntry = new Country(pId, pName, pDimensions);
    }
    else {
        first = new Country(pId, pName, pDimensions);
    }
}