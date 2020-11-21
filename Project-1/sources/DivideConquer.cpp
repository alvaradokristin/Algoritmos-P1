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

    //cout << listDC.first->id << endl;
    //cout << "Init: " << init->id << "\nPivot: " << pivot->id << "\nBorder :" << border->id << endl;
    int numCntrs = listDC.listLength();

    //cout << "numnCntrs: " << numCntrs << endl;

    for (int elmts = 1; elmts <= numCntrs; elmts++) {
        if (((elmts % 10 != 0) || (numCntrs - elmts > 10)) && (border -> nextCntry != nullptr)) {
            border = border -> nextCntry;
        }
        else {
            /*cout << "Group found!!!" << endl;
            cout << "elmts % 10: " << (elmts % 10) << "\nnumCntrs - elmts: " << (numCntrs - elmts) << "\n(border -> nextCntry != nullptr): " << (border -> nextCntry != nullptr) << endl;
            cout << "After the for:" << "\nInit: " << init->id << "\nPivot: " << pivot->id << "\nBorder: " << border->id << endl;*/
            if (border -> nextCntry != nullptr) {
                border = border -> nextCntry;
                conquerSubG(init, pivot, border->prevCntry); // border->prevCntry
            }
            else
                conquerSubG(init, pivot, border); // border->prevCntry
            init = border;
            pivot = border;
        }
        /*cout << "\n================ Inside Divide List!!! ================" << endl;
        cout << "elmts: " << elmts << "\nnumCntrs: " << numCntrs << "\nelmts <= numCntrs: " << (elmts <= numCntrs) << endl;
        if (border != nullptr)
            cout << "border: " << border->id << endl;
        else
            cout << "border: NULL" << endl;*/
    }
    if (init != nullptr) { // In case there are any subgrups left
        conquerSubG(init, pivot, border);
    }
    doubleCheck();
}

// This will conquer every subgroup of 10 countries
void DivideConquer::conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder) {
    //cout << "\nInside conquerSubG1:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
    if (pPivot != pBorder) {
        //cout << "=============================================" << endl;
        //cout << "Inside conquerSubG:\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        pInit = sortSubG(pPivot, pBorder);
        pBorder = savePointr;
        //cout << "New Init: " << pInit->id << "\nList first: " << listDC.first->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        /*cout << "====================List====================" << endl;
        listDC.printList();
        cout << "############################################" << endl;*/
        if (pPivot != pBorder) {
            //cout << "Before the painting:\npInit: " << pInit->id << "\nPivot: " << pPivot->id << endl;
            paintGroup(pInit, pPivot);
            pPivot = pPivot -> nextCntry;
            pInit = pPivot;
        }
        //cout << "\nInside conquerSubG2:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        conquerSubG(pInit, pPivot, pBorder);
    }
    else {
        //cout << "\nInside conquerSubG3:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << "\nBorder: " << pBorder->id << endl;
        if (!pInit->isColored)
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
        //cout << "countries: " << countries->id << "\npBorder: " << pBorder->id << endl;
        while (countries != pBorder -> nextCntry) {
            if ((countries == elements) && (countries != pBorder)) {
                countries = countries -> nextCntry;
                //cout << "Inside sortSubG:\nelements: " << elements->id << "\nPivot: " << pPivot->id << endl;
                listDC.moveBefore(elements, pPivot);
                //cout << "Inside sortSubG:\nList first: " << listDC.first->id << endl;
                if (isFirst) {
                    isFirst = false;
                    init = elements;
                }
            }
            else if ((countries == elements) && (countries == pBorder)) {
                pBorder = pBorder -> prevCntry;
                savePointr = pBorder;
                //cout << "New border: " << pBorder->id << endl;
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
    //cout << "sortSubG end:\nInit: " << init->id << "\nNew border-savePointr: " << savePointr->id  << "\nList First: " << listDC.first->id << endl;
    return init;
}

// This will paint a group of countries, it will ask for each country if they can be X priority
void DivideConquer::paintGroup(pointerCntry pInit, pointerCntry pPivot) {
    pointerCntry cntry = pInit;
    //cout << "Inside the paintGroup:\nInit: " << pInit->id << "\nPivot: " << pPivot->id << endl;
    int contriesClrd = 0; // Countries already colored and this will determine the color (priority), if is gratter than the amount of colors to use, then it will paint it White
    //cout << "cntry: " << cntry->id << "\npPivot: " << pPivot->id << "\ncntry != pPivot: " << (cntry != pPivot) << endl;
    if (cntry != pPivot) {
        /*if (pPivot -> nextCntry == nullptr) {
            cout << "cntry: " << cntry->id << "\npPivot: " << pPivot->id << "\npPivot->nextCntry: NULL" << endl;
        }
        else {
            cout << "cntry: " << cntry->id << "\npPivot: " << pPivot->id << "\npPivot->nextCntry: " << pPivot -> nextCntry->id << endl;
        }*/
        while (cntry != pPivot -> nextCntry) {
            //cout << "!cntry -> isColored: " << !cntry -> isColored << endl;
            if (!cntry -> isColored) { // If the country is not colored
                //cout << "cntry: " << cntry->id << "\nInit: " << pInit->id << endl;
                if (cntry != pInit) {
                    //cout << "contriesClrd: " << contriesClrd << "\ncolorsToUse: " << colorsToUse << endl;
                    if (contriesClrd < colorsToUse) {
                        //cout << "To be painted: " << cntry->id << "\nColor: " << colors->at(contriesClrd) << endl;
                        vectorDC = paint_contries(vectorDC, cntry->id, contriesClrd);
                        cntry->updateColor(colors->at(contriesClrd));
                        contriesClrd++;
                        countriesToColor--;
                    }
                    else { // This will paint the country white
                        //cout << "paintGroup - To be painted WHITE: " << cntry->id << "\nColor: " << colors->at(12) << endl;
                        vectorDC = paint_contries(vectorDC, cntry->id, 1); // 12
                        cntry->updateColor("FFFFFF");
                        contriesClrd++;
                        whiteCountries++;
                        countriesToColor--;
                    }
                }
                else {
                    //cout << "To be painted: " << cntry->id << "\nColor: " << colors->at(contriesClrd) << endl;
                    vectorDC = paint_contries(vectorDC, cntry->id, 0);
                    cntry->updateColor(colors->at(0));
                    contriesClrd++;
                    countriesToColor--;
                }
            }
            //cout << "\ncntry: " << cntry->id << endl;
            cntry = cntry -> nextCntry;
        }
    }
    else {
        //cout << "First country to be painted!!" << endl;
        //cout << "To be painted: " << cntry->id << "\nColor: " << colors->at(0) << endl;
        vectorDC = paint_contries(vectorDC, cntry->id, 0);
        cntry->updateColor(colors->at(0));
        countriesToColor--;
    }
    /*cout << "====================List====================" << endl;
    listDC.printList();
    cout << "############################################" << endl;*/
}

// Once all the list is painted, this will double check that there are no adj with the same color, if there are, it will update the color
void DivideConquer::doubleCheck() {
    //cout << "\nInside Doublecheck!!!" << endl;
    pointerCntry countries = listDC.first;
    int numCntrs = listDC.listLength();

    for (int elmts = 0; elmts < numCntrs; elmts++) {
        //cout << "countries: " << countries->id << "\nColor: " << countries->color << endl;
        vector<string> colorsUsed; // This is a ventor of all the colors used on the adjacents
        bool isUsed = false; // If the color of this country is already used on the adjacents, isUsed will be true
        for(auto adjs : *countries -> adjVector) {
            if (countries -> color == adjs -> color) {
                isUsed = true;
            }
            //cout << "color that found: " << adjs -> color << endl;
            colorsUsed.push_back(adjs -> color);
        }
        if (isUsed) {
            //cout << "Is Used, it will change the color of the country" << endl;
            int cont = 0;
            bool isReColored = false;
            //cout << "Number of colors used: " << colorsUsed.size() << endl;
            for(string colrs : *colors) {
                bool isFound = true;
                for(string colrsUsed : colorsUsed) {
                    //cout << "colrs: " << colrs << "\ncolrsUsed: " << colrsUsed << endl;
                    if (colrs == colrsUsed) {
                        //cout << "entro!!!!!!!!!!" << endl;
                        isFound = false;
                        break;
                    }
                }
                if (isFound) {
                    //cout << "isFound!!!!" << endl;
                    vectorDC = paint_contries(vectorDC, countries->id, cont);
                    countries->updateColor(colors->at(cont));
                    isReColored = true;
                    break;
                }
                cont++;
            }
            if (!isReColored) { // This will paint the country: White since all the color available are used
                //cout << "Paint country: " << countries->id << " White" << endl;
                vectorDC = paint_contries(vectorDC, countries->id, 1); // 12
                countries->updateColor("FFFFFF");
                whiteCountries++;
            }
        }
        countries = countries -> nextCntry;
    }
}