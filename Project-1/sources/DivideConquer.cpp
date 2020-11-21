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
DivideConquer::DivideConquer(int pNumberColors) : Painter(pNumberColors) {
    colorsToUse = pNumberColors;
    countriesToColor = 211;
    whiteCountries = 0;
}

// This will divide the list of countries in groups of 10
void DivideConquer::divideList() {
    pointerCntry init = listDC.first;
    pointerCntry pivot = listDC.first;
    pointerCntry border = listDC.first;

    cout << listDC.first->id << endl;
    cout << "Init: " << init->id << "\nPivot: " << pivot->id << "\nBorder :" << border->id << endl;
    int numCntrs = listDC.listLength();

    cout << "numnCntrs: " << numCntrs << endl;

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        if ((elmts % 10 != 0) || (numCntrs - elmts > 10) || (elmts == 0)) {
            border = border -> nextCntry;
        }
        else {
            cout << "After the for:" << "\nInit: " << init->id << "\nPivot: " << pivot->id << "\nBorder: " << border->id << endl;
            conquerSubG(init, pivot, border->prevCntry); // The error is here
            init = border;
            pivot = border;
        }
    }
    if (init != nullptr) { // In case there are any subgrups left
        conquerSubG(init, pivot, border);
    }
    doubleCheck();
}

// This will conquer every subgroup of 10 countries
void DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder) { // The error is here
    cout << "\nInside conquerSubG1:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
    if (pPivot != pBorder) {
        cout << "=============================================" << endl;
        cout << "Inside conquerSubG:\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        pInit = sortSubG(pPivot, pBorder);
        cout << "New Init: " << pInit->id << "\nList first: " << listDC.first->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        cout << "====================List====================" << endl;
        listDC.printList();
        cout << "############################################" << endl;
        if (pPivot != pBorder) {
            cout << "Before the painting:\npInit: " << pInit->id << "\nPivot: " << pPivot->id << endl;
            paintGroup(pInit, pPivot);
            pPivot = pPivot -> nextCntry;
            pInit = pPivot;
        }
        cout << "\nInside conquerSubG2:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        conquerSubG(pInit, pPivot, pBorder);
    }
    else {
        cout << "\nInside conquerSubG3:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        paintGroup(pInit, pPivot);
    }
}

// This will sort a subgroup where the adj of the pivot will be moved before the pivot
pointerCntry DivideConquer::sortSubG(pointerCntry pPivot, pointerCntry pBorder) {
    pointerCntry countries;
    pointerCntry init;
    bool isFirst = true;

    for(auto elements : *pPivot -> adjVector) {
        countries = pPivot;
        while (countries != pBorder -> nextCntry) {
            if ((countries == elements) && (countries != pBorder)) {
                countries = countries -> nextCntry;
                cout << "Inside sortSubG:\nelements: " << elements->id << "\nPivot: " << pPivot->id << endl;
                listDC.moveBefore(elements, pPivot);
                cout << "Inside sortSubG:\nList first: " << listDC.first->id << endl;
                if (isFirst) {
                    isFirst = false;
                    init = elements;
                }
            }
            else if ((countries == elements) && (countries == pBorder)) {
                pBorder = pBorder -> prevCntry;
                cout << "New border: " << pBorder->id << endl;
                countries = countries -> nextCntry;
                listDC.moveBefore(elements, pPivot);
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
    cout << "sortSubG end:\nInit: " << init->id << "\nList First: " << listDC.first->id << endl;
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {
    pointerCntry cntry = pInit;
    int contriesClrd = 0; // Countries already colored and this will determine the color (priority), if is gratter than the amount of colors to use, then it will paint it White

    if (cntry == pPivot) {
        while (cntry != pPivot -> nextCntry) {
            if (!cntry -> isColored) { // If the country is not colored
                if (cntry != pInit) {
                    if (contriesClrd < colorsToUse) {
                        vectorDC = paint_contries(vectorDC, cntry->id, contriesClrd);
                        cntry->updateColor(colors->at(contriesClrd));
                        contriesClrd++;
                        countriesToColor--;
                    }
                    else {
                        vectorDC = paint_contries(vectorDC, cntry->id, 12);
                        cntry->updateColor("ffffff");
                        contriesClrd++;
                        whiteCountries++;
                        countriesToColor--;
                    }
                }
                else {
                    vectorDC = paint_contries(vectorDC, cntry->id, 0);
                    cntry->updateColor(colors->at(0));
                    contriesClrd++;
                    countriesToColor--;
                }
            }
            cntry = cntry -> nextCntry;
        }
    }
    else {
        vectorDC = paint_contries(vectorDC, cntry->id, 0);
        cntry->updateColor(colors->at(0));
        countriesToColor--;
    }
}

// Once all the list is painted, this will double check that there are no adj with the same color, if there are, it will update the color
void DivideConquer::doubleCheck() {
    pointerCntry countries = listDC.first;
    int numCntrs = listDC.listLength();

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        vector<string> colorsUsed; // This is a ventor of all the colors used on the adjacents
        bool isUsed = false; // If the color of this country os already used on the adjacents, isUsed will be true
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
                for(string colrsUsed : *colors) {
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
                vectorDC = paint_contries(vectorDC, countries->id, 12);
                countries->updateColor("ffffff");
                whiteCountries++;
            }
        }
        countries = countries -> nextCntry;
    }
}