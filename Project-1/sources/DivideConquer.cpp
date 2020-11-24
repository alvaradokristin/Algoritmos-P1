//
// Created by Kris on 11/20/2020.
//

#include <iostream>
#include <windows.h>
#include <algorithm>

using namespace headers;
using namespace std;

// This is the constructor
DivideConquer::DivideConquer(int pNumberColors, string pFileName, string pHeader, vector<string> pDataVector) : Painter(pNumberColors) {

    colorsToUse = pNumberColors;
    countriesToColor = 211;
    whiteCountries = 0;
    findingFileName = pFileName;
    fileHeader = pHeader;
    vectorDC = pDataVector;
}

// This method will start the algorithm
void DivideConquer::start(pointerCntry pFirst) {
    listDC.first = pFirst;
    divideList();
    doubleCheck();
    updateMap();
}

// This method will update the information on the map
void DivideConquer::updateMap() {
    //Sleep(10000); // 10000

    // This will update the timer and print it
    timerDC.timeStamp();
    //timerDC.printTime();

    to_update(findingFileName,"Divide",vectorDC,fileHeader, whiteCountries, ((timerDC.elapsed.count() / 1000)));
}

// This will divide the list of countries in groups of 10
void DivideConquer::divideList() {
    pointerCntry init = listDC.first;
    pointerCntry pivot = listDC.first;
    pointerCntry border = listDC.first;
    bool isDone = false;

    timerDC.startTimer();

    int numCntrs = listDC.listLength();

    for (int elmts = 1; elmts <= numCntrs; elmts++) {
        if ((elmts % 20 != 0) && (border -> nextCntry != nullptr)) { // Subgroups of 20, this is the best option
            border = border -> nextCntry;
        }
        else {
            if (border -> nextCntry != nullptr) {
                border = border -> nextCntry;
                isDone = conquerSubG(init, pivot, border->prevCntry);
                updateMap();
            }
            else {
                isDone = conquerSubG(init, pivot, border);
            }
            init = border;
            pivot = border;
        }
    }
    if (init != nullptr) { // In case there are any subgroups left
        isDone = conquerSubG(init, pivot, border);
    }
    // This is the end, it will check that there is no adjacents with the same color and update the SVG
    doubleCheck();
    updateMap();
}

// This will conquer every subgroup of 20 countries
bool DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder) {
    if ((pPivot != pBorder) && (pPivot != nullptr)) {
        pInit = sortSubG(pPivot, pBorder);

        if (pPivot != pBorder) {
            paintGroup(pInit, pPivot);
            pPivot = pPivot -> nextCntry;
            pInit = pPivot;
            conquerSubG(pInit, pPivot, pBorder);
        }
        else {
            conquerSubG(pInit, pPivot, pBorder);
        }
    }
    else if ((pPivot == pBorder) && (pPivot != nullptr)) {
        paintGroup(pInit, pPivot);
        return true;
    }
    return true;
}

// This will sort a subgroup where the adj of the pivot will be moved before the pivot
pointerCntry DivideConquer::sortSubG(pointerCntry pPivot, pointerCntry pBorder) {

    pointerCntry countries = pPivot; // This will be each contry in this group
    pointerCntry init = pPivot; // This will be the new init, the ointer to be returned
    bool isFirst = true; // Will get the new init, when the first element has been moved

    if (pPivot -> adjVector -> size() > 0) { // If the pivot have adjacents
        countries = pPivot;

        while ((countries != pBorder -> nextCntry) && (countries != nullptr)) {
            for (auto adjs : *pPivot -> adjVector) {
                if (countries == adjs) {
                    listDC.moveBefore(countries, pPivot); // Move the adjacent before the pivot
                    if (isFirst) {
                        isFirst = false;
                        init = countries;
                    }
                }
            }
            countries = countries -> nextCntry;
        }
    }
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {
    pointerCntry countries = pInit; // This will be each contry in this group
    int prioritiesUsed = 0;
    bool isItPainted = false;

    while (countries != pPivot) {
        if (!(countries -> isColored)) { // If the country haven't been painted
            if (prioritiesUsed < colorsToUse) {
                vectorDC = paint_contries(vectorDC, countries->id, prioritiesUsed);
                countries -> updateColor(colors->at(prioritiesUsed));
                prioritiesUsed++;
            }
            else {
                vectorDC = paint_contries(vectorDC, countries->id, 12);
                countries -> updateColor("FFFFFF");
                whiteCountries++;
            }
                countriesToColor -= 1;
        }
        countries = countries -> nextCntry;
    }
    if (prioritiesUsed < colorsToUse) {
        if (countries -> isColored)
            isItPainted = true;
        vectorDC = paint_contries(vectorDC, countries->id, prioritiesUsed);
        countries -> updateColor(colors->at(prioritiesUsed));
        if (!isItPainted) {
            countriesToColor -= 1;
        }
        prioritiesUsed++;
    }
    else { // This will paint the country white
        if (countries -> isColored)
            isItPainted = true;
        vectorDC = paint_contries(vectorDC, countries->id, 12);
        countries -> updateColor("FFFFFF");
        whiteCountries++;
        if (!isItPainted)
            countriesToColor -= 1;
    }
}

// Once all the list is painted, this will double check that there are no adj with the same color, if there are, it will update the color
void DivideConquer::doubleCheck() {
    whiteCountries = 0;
    int pos;
    pointerCntry countries = listDC.first;

    while (countries != nullptr) {
        pos = -1;
        vector<string> colToUSe = *colors; // This is a vector of all the colors used in the adjacents
        bool isUsed = false; // If the color of this country is already used on the adjacents, isUsed will be true

        if (countries -> adjVector->size() > 0) {
            for(auto adjs : *countries -> adjVector) {
                pos = getPosVec(colToUSe, adjs->color);
                if (pos != -1) {
                    colToUSe.erase(colToUSe.begin() + pos);
                }
            }
            if (colToUSe.size() > 0) {
                pos = getPosVec(*colors, colToUSe.at(0));
                vectorDC = paint_contries(vectorDC, countries->id, pos);
                countries -> updateColor(colToUSe.at(0));
            }
            else { // This will paint the country white
                vectorDC = paint_contries(vectorDC, countries->id, 12);
                countries -> updateColor("FFFFFF");
                whiteCountries++;
            }
        }
        countries = countries -> nextCntry;
    }
}

// This function will retunr the position of the color inside the vector
int DivideConquer::getPosVec(vector<string> pColToUSe, string pColor) {
    int pos = -1;

    for(auto eachClr : pColToUSe) {
        if (eachClr == pColor){
            return pos + 1;
        }
        pos++;
    }
    return -1;
}