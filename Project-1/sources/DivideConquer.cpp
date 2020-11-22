//
// Created by Kris on 11/20/2020.
//

#include <iostream>
#include <windows.h>

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

// This method will update the information on the map
void DivideConquer::updateMap() {
    Sleep(10000); // 10000
    to_update(findingFileName,"Divide",vectorDC,fileHeader);

    // This will update the timer and print it
    timerDC.timeStamp();
    timerDC.printTime();
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
        if (((elmts % 20 != 0) && (numCntrs - elmts > 20)) && (border -> nextCntry != nullptr)) { // 20
            border = border -> nextCntry;
        }
        else {
            if (border -> nextCntry != nullptr) {
                border = border -> nextCntry;
                isDone = conquerSubG(init, pivot, border->prevCntry); // border->prevCntry
                updateMap();
            }
            else {
                isDone = conquerSubG(init, pivot, border); // border->prevCntry
            }
            init = border;
            pivot = border;
        }
    }
    if (init != nullptr) { // In case there are any subgrups left
        isDone = conquerSubG(init, pivot, border);
    }
    doubleCheck();
    updateMap();
}

// This will conquer every subgroup of 10 countries
bool DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder) {
    if (pPivot != pBorder) {
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
    else {
        paintGroup(pInit, pPivot);
        return true;
    }
    return true;
}

// This will sort a subgroup where the adj of the pivot will be moved before the pivot
pointerCntry DivideConquer::sortSubG(pointerCntry pPivot, pointerCntry pBorder) {
    pointerCntry countries;
    pointerCntry init = pPivot;
    bool isFirst = true;

    if (!pPivot -> isColored) {
        if (pPivot->adjVector->size() > 0) {
            for (auto elements : *pPivot->adjVector) {
                countries = pPivot;
                while (countries != pBorder) {
                    if ((countries == elements) && (countries != pBorder)) {
                        countries = countries->nextCntry;
                        listDC.moveBefore(elements, pPivot);
                        if (isFirst) {
                            isFirst = false;
                            init = elements;
                        }
                    } else if ((countries == elements) && (countries == pBorder)) {
                        pBorder = pBorder->prevCntry;
                        countries = countries->nextCntry;
                        listDC.moveBefore(elements, pPivot);
                        if (isFirst) {
                            isFirst = false;
                            init = elements;
                        }
                    }
                    else {
                        countries = countries->nextCntry;
                    }
                }
                if (countries == nullptr) {
                }
            }
        }
    }
    else {
        init = pPivot -> nextCntry;
    }
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {
    pointerCntry cntry = pInit;
    int contriesClrd = 0; // Countries already colored and this will determine the color (priority), if is gratter than the amount of colors to use, then it will paint it White
    if (cntry != pPivot) {
        while (cntry != pPivot -> nextCntry) {
            if (!cntry->isColored) {
                bool newToPaint = false;
                if (!cntry->isColored) { // If the country is not colored
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
                        } else { // This will paint the country white
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
                    } else {
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
                cntry = cntry->nextCntry;
            }
        }
    }
    else {
        if (!cntry->isColored) {
            vectorDC = paint_contries(vectorDC, cntry->id, 0);
            cntry->updateColor(colors->at(0));
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

        /*if (auxPointer -> adjVector != NULL) { //-> size() > 0
                cout << "====================================List of adjacents:====================================" << endl;

                for(auto elements : *auxPointer -> adjVector) {
                    cout << "ID: " << elements -> id << endl;
                    cout << "Name: " << elements -> name << endl;
                    cout << "Max X: " << elements -> maxX << endl;
                    cout << "Max Y: " << elements -> maxY << endl;
                    cout << "Min X: " << elements -> minX << endl;
                    cout << "Min Y: " << elements -> minY << endl;
                    cout << "Color: " << elements -> color << endl;
                    cout << "#==============================#" << endl;
                    cout << endl;
                }

                cout << "====================================The adjacents ends here!====================================" << endl;
                cout << endl;
            }*/
        auxPointer = auxPointer -> nextCntry;
    }
    cout << "!!!!!!!!!!END!!!!!!!!!!" << endl;
}