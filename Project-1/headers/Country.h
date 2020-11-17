//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_COUNTRY_H
#define PROJECT_1_COUNTRY_H

#include <string>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

namespace headers {
    /*
     * This is the class Country, this will have all the necesary information of a country and a pointer to create lists of countries
     * */
    class Country {

        friend class List;

    public:
        Country(string pId, string pName, string pDimensions, string pStyle);
        Country(string pId, string pName, string pDimensions, string pStyle, Country *pNextCountry);
        Country(string pId, string pName, string pDimensions, string pStyle, Country *pPrevCountry, Country *pNextCountry);
        void updateColor(string pNewColor);
        void createCoordenates(string pData);
        void addNewCoord(short pOption, short pElmtsAdded, string pCordenates);
        string separateByChar(char pChar, string pText, short pPosition);
        float findMin(vector<float> pVector);
        float findMax(vector<float> pVector);

    //private:
        Country *nextCntry;
        Country *prevCntry;
        vector<Country*> *adjVector;
        string id;
        string name;
        string dimensions;
        string style;
        string color;
        bool isColored;
        vector<float> xCoordenates;
        vector<float> yCoordenates;
        float maxX;
        float maxY;
        float minX;
        float minY;
    };
}

#endif //PROJECT_1_COUNTRY_H