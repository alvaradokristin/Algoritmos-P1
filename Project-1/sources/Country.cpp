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
    isColored = false;
    maxX = setMax(pDimensions, 1);
    maxY = setMax(pDimensions, 2);
    minX = setMin(pDimensions, 1);
    minY = setMin(pDimensions, 2);
    color = separateByChar(':', text, 2);
    nextCntry = nullptr;
    prevCntry = nullptr;
    adjVector = new vector<Country*>();
}

// This constructor is used when the new contry will be added at the beginning of the list, pNextCountry is the previous first country of the list
Country::Country(string pId, string pName, string pDimensions, string pStyle, Country *pNextCountry) {
    string text = separateByChar(';', pStyle, 1);
    id = pId;
    name = pName;
    dimensions = pDimensions;
    style = pStyle;
    isColored = false;
    maxX = setMax(pDimensions, 1);
    maxY = setMax(pDimensions, 2);
    minX = setMin(pDimensions, 1);
    minY = setMin(pDimensions, 2);
    color = separateByChar(':', text, 2);
    nextCntry = pNextCountry;
    prevCntry = nullptr;
    adjVector = new vector<Country*>();
}

// This constructor is used when the country is created and it has a previous country, as an example, if the new country is added at the end of the list
Country::Country(string pId, string pName, string pDimensions, string pStyle, Country *pPrevCountry, Country *pNextCountry) {
    string text = separateByChar(';', pStyle, 1);
    id = pId;
    name = pName;
    dimensions = pDimensions;
    style = pStyle;
    isColored = false;
    maxX = setMax(pDimensions, 1);
    maxY = setMax(pDimensions, 2);
    minX = setMin(pDimensions, 1);
    minY = setMin(pDimensions, 2);
    color = separateByChar(':', text, 2);
    nextCntry = pNextCountry;
    prevCntry = pPrevCountry;
    adjVector = new vector<Country*>();
}

// This method will update the color on a country
void Country::updateColor(string pNewColor) { // Country *pCurrentCntry,
    color = pNewColor;
    style = "fill:" + pNewColor + ";fill-rule:evenodd";
    isColored = true;
}

// This function will separate a string by the character that you need
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

// ------------------------------------ V1 ------------------------------------ //
/*float Country::setMax(string pData, int pOption){
    string coordenates = "";
    float prevNumber = 0;
    float newPoint = 0;
    float max = -1;
    string value;

    for (auto txtChar : pData) {
        if (txtChar != ' ') {
            coordenates = coordenates + txtChar;
        }
        else {
            if (coordenates != "m" && coordenates != "z" && coordenates != "M" && coordenates != "Z" && coordenates != "l") {
                value = separateByChar(',', coordenates, pOption);
                newPoint = stof(value);
                prevNumber = prevNumber + newPoint;
                if (max <= prevNumber) {
                    max = prevNumber;
                }
            }
            coordenates = "";
        }
    }
    return max;
}

float Country::setMin(string pData, int pOption){
    string coordenates = "";
    float prevNumber = 0;
    float newPoint = 0;
    float min = 3.402823466e+38F;
    string value;

    for (auto txtChar : pData) {
        if (txtChar != ' ') {
            coordenates = coordenates + txtChar;
        }
        else {
            if (coordenates != "m" && coordenates != "z" && coordenates != "M" && coordenates != "Z" && coordenates != "l") {
                value = separateByChar(',', coordenates, pOption);
                newPoint = stof(value);
                prevNumber = prevNumber + newPoint;
                if (min >= prevNumber) {
                    min = prevNumber;
                }
            }
            coordenates = "";
        }
    }
    return min;
}*/

// ------------------------------------ V2 ------------------------------------ //
float Country::setMax(string pData, int pOption){
    string coordenates = "";
    float prevNumber = 0;
    float newPoint = 0;
    float max = -1;
    string value;
    bool isFirst = true;
    bool isM = false;

    for (auto txtChar : pData) {
        if (txtChar != ' ') {
            coordenates = coordenates + txtChar;
        }
        else {
            if (!isFirst) {
                if (coordenates != "m" && coordenates != "z" && coordenates != "M" && coordenates != "Z" && coordenates != "l") {
                    value = separateByChar(',', coordenates, pOption);
                    newPoint = stof(value);
                    if (!isM) {
                        prevNumber = prevNumber + newPoint;
                        if (max <= prevNumber) {
                            max = prevNumber;
                        }
                    }
                    else {
                        prevNumber = newPoint;
                        if (max <= prevNumber) {
                            max = prevNumber;
                        }
                        isM = false;
                    }
                }
                else if (coordenates == "M") {
                    isM = true;
                }
            }
            else {
                isFirst = false;
            }
            coordenates = "";
        }
    }
    return max;
}

float Country::setMin(string pData, int pOption){
    string coordenates = "";
    float prevNumber = 0;
    float newPoint = 0;
    float min = 3.402823466e+38F;
    string value;
    bool isFirst = true;
    bool isM = false;

    for (auto txtChar : pData) {
        if (txtChar != ' ') {
            coordenates = coordenates + txtChar;
        }
        else {
            if (!isFirst) {
                if (coordenates != "m" && coordenates != "z" && coordenates != "M" && coordenates != "Z" && coordenates != "l") {
                    value = separateByChar(',', coordenates, pOption);
                    newPoint = stof(value);
                    if (!isM) {
                        prevNumber = prevNumber + newPoint;
                        if (min >= prevNumber) {
                            min = prevNumber;
                        }
                    }
                    else {
                        prevNumber = newPoint;
                        if (min >= prevNumber) {
                            min = prevNumber;
                        }
                        isM = false;
                    }
                }
                else if (coordenates == "M") {
                    isM = true;
                }
            }
            else {
                isFirst = false;
            }
            coordenates = "";
        }
    }
    return min;
}