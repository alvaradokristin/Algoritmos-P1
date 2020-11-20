//
// Created by Kris on 11/20/2020.
//

#ifndef PROJECT_1_DIVIDECONQUER_H
#define PROJECT_1_DIVIDECONQUER_H

#include "Painter.h"
#include "List.h"

namespace headers {
    class DivideConquer : public Painter {

    public:
        void divideList(List pDivList);
        void conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder, List pList);
        pointerCntry sortSubG(pointerCntry pPivot, pointerCntry pBorder, List pList);
        void paintGroup(pointerCntry pInit, pointerCntry pPivot);
        void doubleCheck(List pList);

    };
}

#endif //PROJECT_1_DIVIDECONQUER_H
