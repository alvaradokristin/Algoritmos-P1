//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"

using namespace headers;
using namespace std;

typedef Country *pointerCntry;

// This is the basic constructor
Country::Country(string pId, string pName, string pDimensions, string pStyle) {
    string text = separateByChar(';', pStyle, 1);
    id = pId;
    name = pName;
    dimensions = pDimensions;
    style = pStyle;
    createCoordenates(pDimensions); // This will populate the vectors
    maxX = findMax(xCoordenates);
    maxY = findMax(yCoordenates);
    minX = findMin(xCoordenates);
    minY = findMin(yCoordenates);
    color = separateByChar(':', text, 2);
    nextCntry = NULL;
    prevCntry = NULL;
    adjVector = new vector<Country*>();
}

// This constructor is used when the new contry will be added at the beginning of the list, pNextCountry is the previous first country of the list
Country::Country(string pId, string pName, string pDimensions, string pStyle, Country *pNextCountry) {
    string text = separateByChar(';', pStyle, 1);
    id = pId;
    name = pName;
    dimensions = pDimensions;
    style = pStyle;
    createCoordenates(pDimensions); // This will populate the vectors
    maxX = findMax(xCoordenates);
    maxY = findMax(yCoordenates);
    minX = findMin(xCoordenates);
    minY = findMin(yCoordenates);
    color = separateByChar(':', text, 2);
    nextCntry = pNextCountry;
    prevCntry = NULL;
    adjVector = new vector<Country*>();
}

// This constructor is used when the country is created and it has a previous country, as an example, if the new country is added at the end of the list
Country::Country(string pId, string pName, string pDimensions, string pStyle, Country *pPrevCountry, Country *pNextCountry) {
    string text = separateByChar(';', pStyle, 1);
    id = pId;
    name = pName;
    dimensions = pDimensions;
    style = pStyle;
    createCoordenates(pDimensions); // This will populate the vectors
    maxX = findMax(xCoordenates);
    maxY = findMax(yCoordenates);
    minX = findMin(xCoordenates);
    minY = findMin(yCoordenates);
    color = separateByChar(':', text, 2);
    nextCntry = pNextCountry;
    prevCntry = pPrevCountry;
    adjVector = new vector<Country*>();
}

void Country::updateColor(Country *pCurrentCntry, string pNewColor) {
    pCurrentCntry->color = pNewColor;
    pCurrentCntry->style = "fill:" + pNewColor + ";fill-rule:evenodd";
}

string Country::separateByChar(char pChar, string pText, short pPosition) {
    string xCoor = "";
    string yCoor = "";
    bool isY = false;

    for (auto txtChar : pText) {
        if (txtChar != pChar && !isY) {
            xCoor = xCoor + txtChar;
        }
        if (txtChar == pChar && !isY) {
            isY = true;
        }
        if (txtChar != pChar && isY) {
            yCoor = yCoor + txtChar;
        }
    }
    if (pPosition == 1)
        return xCoor;
    else
        return yCoor;
}

void Country::addNewCoord(short pOption, short pElmtsAdded, string pCordenates) {
    float num_float;

    string value = separateByChar(',', pCordenates, pOption);
    num_float = stof(value);

    if (pOption == 1) {
        if (pElmtsAdded-1 >= 0)
            num_float = xCoordenates.at(pElmtsAdded-1) + num_float;

        xCoordenates.push_back(num_float);
    }
    else {
        if (pElmtsAdded-1 >= 0)
            num_float = yCoordenates.at(pElmtsAdded-1) + num_float;

        yCoordenates.push_back(num_float);
    }
}

void Country::createCoordenates(string pData) {
    string coordenates = "";
    float num_float;
    short vecElements = 1;
    string value;
    short elmtsAdded = 0;

    for (auto txtChar : pData) {
        if (txtChar != ' ') {
            coordenates = coordenates + txtChar;
        }
        else {
            if (coordenates != "m" && coordenates != "z") {
                addNewCoord(1, elmtsAdded, coordenates);
                addNewCoord(2, elmtsAdded, coordenates);

                elmtsAdded++;
            }
            coordenates = "";
        }
    }
}

float Country::findMax(vector<float> pVector){

    float max = -1;

    for (auto element = pVector.begin(); element != pVector.end(); element++) {
        if (*element >= max) {
            max = *element;
        }
    }
    return max;
}

float Country::findMin(vector<float> pVector){

    float max = 3.402823466e+38F;

    for (auto element = pVector.begin(); element != pVector.end(); element++) {
        if (*element <= max) {
            max = *element;
        }
    }
    return max;
}