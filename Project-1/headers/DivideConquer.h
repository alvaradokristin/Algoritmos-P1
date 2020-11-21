//
// Created by Kris on 11/20/2020.
//

#ifndef PROJECT_1_DIVIDECONQUER_H
#define PROJECT_1_DIVIDECONQUER_H

//#include "../sources/Painter.cpp" // multiple definition of `XMLPainter::XMLPainter()'
#include "List.h"
#include "Painter.h"

namespace headers {
    class DivideConquer : public Painter {

    public:
        DivideConquer(int pNumberColors);
        //void Create(int num);
        void divideList(List pDivList);
        void conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder, List pList);
        pointerCntry sortSubG(pointerCntry pPivot, pointerCntry pBorder, List pList);
        void paintGroup(pointerCntry pInit, pointerCntry pPivot);
        void doubleCheck(List pList);

    private:
        vector<string> vectorDC;
        int countriesToColor;
        int whiteCountries;
        int colorsToUse;
    };
}

#endif //PROJECT_1_DIVIDECONQUER_H
