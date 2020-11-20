//
// Created by Kris on 11/20/2020.
//

#include <iostream>
#include "../headers/DivideConquer.h"

//using namespace headers;
using namespace std;

// This will divide the list of countries in groups of 10
void DivideConquer::divideList(List pDivList) {
    pointerCntry init, pivot, border = pDivList.first;
    int numCntrs = pDivList.listLength();

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        if ((elmts % 10 != 0) || (numCntrs - elmts > 10) || (elmts == 0)) {
            border = border -> nextCntry;
        }
        else {
            conquerSubG(init, pivot, border->prevCntry, pDivList);
            init = border;
            pivot = border;
        }
    }
    conquerSubG(init, pivot, border, pDivList);
    doubleCheck(pDivList);
}

// This will conquer every subgroup of 10 countries
void DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder, List pList) {
    if (pPivot != pBorder) {
        pInit = sortSubG(pPivot, pBorder, pList);
        if (pPivot != pBorder) {
            paintGroup(pInit, pPivot);
            pPivot = pPivot -> nextCntry;
            pInit = pPivot;
        }
        conquerSubG(pInit, pPivot, pBorder, pList);
    }
    else {
        paintGroup(pInit, pPivot);
    }
}

// This will sort a subgroup where the adj of the pivot will be moved before the pivot
pointerCntry DivideConquer::sortSubG(pointerCntry pPivot, pointerCntry pBorder, List pList) {
    pointerCntry countries;
    pointerCntry init;
    bool isFirst = true;

    for(auto elements : *pPivot -> adjVector) {
        countries = pPivot;
        while (countries != pBorder -> nextCntry) {
            if ((countries == elements) && (countries != pBorder)) {
                countries = countries -> nextCntry;
                pList.moveBefore(elements, pPivot);
                if (isFirst) {
                    isFirst = false;
                    init = elements;
                }
            }
            else if ((countries == elements) && (countries == pBorder)) {
                pBorder = pBorder -> prevCntry;
                countries = countries -> nextCntry;
                pList.moveBefore(elements, pPivot);
                if (isFirst) {
                    isFirst = false;
                    init = elements;
                }
            }
            else {
                countries = countries -> nextCntry;
            }
        }
    }
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {

}

// Once all the list is painted, this will double check that there are no adj with the same color, if there are, it will update the color
void DivideConquer::doubleCheck(List pList) {
    pointerCntry countries = pList.first;
    int numCntrs = pList.listLength();

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        for(auto adjs : *countries -> adjVector) {
            if (countries -> color == adjs -> color) {
                
            }
        }
    }
}