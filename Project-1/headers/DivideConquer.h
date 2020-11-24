//
// Created by Kris on 11/20/2020.
//

#ifndef PROJECT_1_DIVIDECONQUER_H
#define PROJECT_1_DIVIDECONQUER_H

#include "List.h"
#include "Painter.h"
#include "Timer.h"

namespace headers {
    class DivideConquer : public Painter {

        friend class Program;

    public:
        DivideConquer(int pNumberColors, string pFileName, string pHeader, vector<string> pDataVector);
        void start(pointerCntry pFirst);
        void divideList();
        bool conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder);
        pointerCntry sortSubG(pointerCntry pPivot, pointerCntry pBorder);
        void paintGroup(pointerCntry pInit, pointerCntry pPivot);
        void doubleCheck();
        void updateMap();
        int getPosVec(vector<string> pColToUSe, string pColor);

    private:
        vector<string> vectorDC;
        int countriesToColor;
        int whiteCountries;
        int colorsToUse;
        List listDC;
        string findingFileName;
        string fileHeader;
        Timer timerDC;
    };
}

#endif //PROJECT_1_DIVIDECONQUER_H
