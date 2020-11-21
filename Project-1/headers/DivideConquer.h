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
        void divideList();
        void conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder);
        pointerCntry sortSubG(pointerCntry pPivot, pointerCntry pBorder);
        void paintGroup(pointerCntry pInit, pointerCntry pPivot);
        void doubleCheck();

    //private:
        vector<string> vectorDC;
        int countriesToColor;
        int whiteCountries;
        int colorsToUse;
        List listDC;
        //pointerCntry border;
    };
}

#endif //PROJECT_1_DIVIDECONQUER_H
