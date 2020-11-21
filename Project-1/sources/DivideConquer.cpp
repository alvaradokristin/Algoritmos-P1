//
// Created by Kris on 11/20/2020.
//

#include <iostream>

//#include "../headers/Painter.h" // undefined reference to `headers::Painter::Painter(int)'
#include "../sources/Painter.cpp"
#include "../headers/DivideConquer.h"

using namespace headers;
using namespace std;

// This is the constructor
DivideConquer::DivideConquer(int pNumberColors, string pFileName, string pHeader) : Painter(pNumberColors) {
    colorsToUse = pNumberColors;
    countriesToColor = 211;
    whiteCountries = 0;
    findingFileName = pFileName;
    fileHeader = pHeader;
}

// This will divide the list of countries in groups of 10
void DivideConquer::divideList() {
    pointerCntry init = listDC.first;
    pointerCntry pivot = listDC.first;
    pointerCntry border = listDC.first;

    timerDC.startTimer();

    int numCntrs = listDC.listLength();

    for (int elmts = 1; elmts <= numCntrs; elmts++) {
        if (((elmts % 10 != 0) && (numCntrs - elmts > 10)) && (border -> nextCntry != nullptr)) {
            border = border -> nextCntry;
        }
        else {
            if (border -> nextCntry != nullptr) {
                border = border -> nextCntry;
                conquerSubG(init, pivot, border->prevCntry); // border->prevCntry
            }
            else {
                conquerSubG(init, pivot, border); // border->prevCntry
            }
            init = border;
            pivot = border;
        }
        if ((countriesToColor % 20 == 1) && (elmts % 10 == 0)) {
            to_update(findingFileName,"Divide",vectorDC,fileHeader);
            timerDC.timeStamp();
            timerDC.printTime();
        }
    }
    if (init != nullptr) { // In case there are any subgrups left
        conquerSubG(init, pivot, border);
    }
    doubleCheck();
    to_update(findingFileName,"Divide",vectorDC,fileHeader);
}

// This will conquer every subgroup of 10 countries
void DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder) {
    //printSubG(pInit, pBorder);
    if (pPivot != pBorder) {
        pInit = sortSubG(pPivot, pBorder);
        pBorder = savePointr;
        if (pPivot != pBorder) {
            paintGroup(pInit, pPivot);
            pPivot = pPivot -> nextCntry;
            pInit = pPivot;
        }
        if (pInit != nullptr) {
            conquerSubG(pInit, pPivot, pBorder);
        }
        conquerSubG(pInit, pPivot, pBorder);
    }
    else {
        if (!pInit->isColored)
            paintGroup(pInit, pPivot);
    }
}

// This will sort a subgroup where the adj of the pivot will be moved before the pivot
pointerCntry DivideConquer::sortSubG(pointerCntry pPivot, pointerCntry pBorder) {
    pointerCntry countries;
    pointerCntry init = pPivot;
    bool isFirst = true;

    if (pPivot -> adjVector->size() > 0) {
        for(auto elements : *pPivot -> adjVector) {
            countries = pPivot;
            while (countries != pBorder -> nextCntry) {
                if ((countries == elements) && (countries != pBorder)) {
                    countries = countries -> nextCntry;
                    listDC.moveBefore(elements, pPivot);
                    if (isFirst) {
                        isFirst = false;
                        init = elements;
                    }
                }
                else if ((countries == elements) && (countries == pBorder)) {
                    pBorder = pBorder -> prevCntry;
                    savePointr = pBorder;
                    countries = countries -> nextCntry;
                    listDC.moveBefore(elements, pPivot);
                    if (isFirst) {
                        isFirst = false;
                        init = elements;
                    }
                }
                else {
                    countries = countries -> nextCntry;
                    savePointr = pBorder;
                }
            }
        }
    }
    else {
        savePointr = pBorder;
    }
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {
    pointerCntry cntry = pInit;
    int contriesClrd = 0; // Countries already colored and this will determine the color (priority), if is gratter than the amount of colors to use, then it will paint it White
    if (cntry != pPivot) {
        while (cntry != pPivot -> nextCntry) {
            bool newToPaint = false;
            if (!cntry -> isColored) { // If the country is not colored
                if (cntry != pInit) {
                    if (contriesClrd < colorsToUse) {
                        if (!cntry->isColored) {
                            newToPaint = true;
                        }
                        vectorDC = paint_contries(vectorDC, cntry->id, contriesClrd);
                        cntry->updateColor(colors->at(contriesClrd));
                        contriesClrd++;
                        if (newToPaint) {
                            countriesToColor -= 1;
                        }
                    }
                    else { // This will paint the country white
                        if (!cntry->isColored) {
                            newToPaint = true;
                        }
                        vectorDC = paint_contries(vectorDC, cntry->id, 12); // 12
                        cntry->updateColor("FFFFFF");
                        contriesClrd++;
                        whiteCountries++;
                        if (newToPaint) {
                            countriesToColor -= 1;
                        }
                    }
                }
                else {
                    if (!cntry->isColored) {
                        newToPaint = true;
                    }
                    vectorDC = paint_contries(vectorDC, cntry->id, 0);
                    cntry->updateColor(colors->at(0));
                    contriesClrd++;
                    if (newToPaint) {
                        countriesToColor -= 1;
                    }
                }
            }
            cntry = cntry -> nextCntry;
        }
    }
    else {
        bool newToPaint = false;
        if (!cntry->isColored) {
            newToPaint = true;
        }
        vectorDC = paint_contries(vectorDC, cntry->id, 0);
        cntry->updateColor(colors->at(0));
        if (newToPaint) {
            countriesToColor -= 1;
        }
    }
}

// Once all the list is painted, this will double check that there are no adj with the same color, if there are, it will update the color
void DivideConquer::doubleCheck() {
    pointerCntry countries = listDC.first;
    int numCntrs = listDC.listLength();

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        vector<string> colorsUsed; // This is a ventor of all the colors used on the adjacents
        bool isUsed = false; // If the color of this country is already used on the adjacents, isUsed will be true
        for(auto adjs : *countries -> adjVector) {
            if (countries -> color == adjs -> color) {
                isUsed = true;
            }
            colorsUsed.push_back(adjs -> color);
        }
        if (isUsed) {
            int cont = 0;
            bool isReColored = false;
            for(string colrs : *colors) {
                bool isFound = true;
                for(string colrsUsed : colorsUsed) {
                    if (colrs == colrsUsed) {
                        isFound = false;
                        break;
                    }
                }
                if (isFound) {
                    vectorDC = paint_contries(vectorDC, countries->id, cont);
                    countries->updateColor(colors->at(cont));
                    isReColored = true;
                    break;
                }
                cont++;
            }
            if (!isReColored) { // This will paint the country: White since all the color available are used
                vectorDC = paint_contries(vectorDC, countries->id, 12); // 12
                countries->updateColor("FFFFFF");
                whiteCountries++;
            }
        }
        countries = countries -> nextCntry;
    }
}

void DivideConquer::printSubG(pointerCntry pInit, pointerCntry pBorder) {
    pointerCntry auxPointer = pInit;

    while (auxPointer != pBorder -> nextCntry) {
        cout << "ID: " << auxPointer -> id << endl;
        cout << "Name: " << auxPointer -> name << endl;
        cout << "Max X: " << auxPointer -> maxX << endl;
        cout << "Max Y: " << auxPointer -> maxY << endl;
        cout << "Min X: " << auxPointer -> minX << endl;
        cout << "Min X: " << auxPointer -> minY << endl;
        cout << "Color: " << auxPointer -> color << endl;
        cout << "Num Adj: " << auxPointer->adjVector->size() << endl;
        cout << "#==============================#" << endl;
        cout << endl;
        auxPointer = auxPointer -> nextCntry;
    }
    cout << "!!!!!!!!!!END!!!!!!!!!!" << endl;
}