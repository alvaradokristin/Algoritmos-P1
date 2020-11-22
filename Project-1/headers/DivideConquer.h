//
// Created by Kris on 11/20/2020.
//

#ifndef PROJECT_1_DIVIDECONQUER_H
#define PROJECT_1_DIVIDECONQUER_H

//#include "../sources/Painter.cpp" // multiple definition of `XMLPainter::XMLPainter()'
#include "List.h"
#include "Painter.h"
#include "Timer.h"

namespace headers {
    class DivideConquer : public Painter {

    public:
        DivideConquer(int pNumberColors, string pFileName, string pHeader);
        //void Create(int num);
        void divideList();
        bool conquerSubG(pointerCntry pInit, pointerCntry pPivot, pointerCntry pBorder);
        pointerCntry sortSubG(pointerCntry pPivot, pointerCntry pBorder);
        void paintGroup(pointerCntry pInit, pointerCntry pPivot);
        void doubleCheck();
        void printSubG(pointerCntry pInit, pointerCntry pBorder);
        void updateMap();

    //private:
        vector<string> vectorDC;
        int countriesToColor;
        int whiteCountries;
        int colorsToUse;
        List listDC;
        pointerCntry savePointr;
        string findingFileName;
        string fileHeader;
        Timer timerDC;
    };
}

/* The active includes in main for the test (only the divide and conquer.h and the read xml.cpp, the resrt are commented)
//#include "headers/Timer.h"
//#include "headers/List.h"
#include "headers/DivideConquer.h"
#include "sources/Read_XML.cpp"
//#include "headers/Painter.h"
//#include "sources/Painter.cpp"
 */

// Test divide and conquer in main
    /*string d1 = "m 1228.7,654.7 0,-0.3 0.2,-0.5 0,-0.1 0.1,-0.5 -0.3,-0.3 -0.2,0 -0.2,-0.3 -0.3,0.3 0.3,0.5 -0.1,0.3 -0.1,0.4 0.1,0.4 0.2,0.2 0.3,-0.1 z";
    string d2 = "m 1909.1,646.4 -0.2,-0.2 -0.1,-0.4 -0.3,0 -0.3,0.1 0.2,0.6 0.2,0 0.5,-0.1 z m -35.6,0.8 -0.1,-0.2 -0.5,-0.4 -1.9,-1.3 -0.4,-0.1 -0.1,0.1 -0.1,0.3 0.1,0.2 0.5,0.1 0,0.1 0.3,0.2 0.7,0.2 0.4,0.3 0.1,0.5 0.3,0.1 0.3,0.1 0.4,-0.2 z m 32,-6.6 0,-0.1 0.2,-0.3 -0.2,-0.1 -0.5,-0.1 -0.7,0.1 -0.3,0.2 -0.2,0.3 -0.2,0 0,0.2 0.1,0.4 0.2,-0.1 0.2,0.1 0.5,-0.5 0.3,0 0.1,0 0.5,-0.1 z m -24.4,-2.3 -0.1,-0.2 -0.2,-0.1 -0.9,-0.7 -0.5,-0.2 -0.5,0 -0.1,0.5 0,0.3 0.6,0 0.4,0.2 0,0.6 0.2,0.2 0,0.5 1.2,0.9 0.7,0.4 0.7,0.1 0.4,0.2 0.5,-0.1 0.5,0.2 0.4,-0.1 -0.4,-0.3 0,-0.4 -0.5,-1.3 -0.3,-0.3 -0.5,0.1 -0.5,-0.2 -0.4,0 -0.7,-0.3 z m -0.4,-4.9 -0.6,-1.6 -0.2,-0.1 0.1,0.6 0.1,0.4 -0.1,0.5 -0.1,0.6 0.2,0.2 0.2,-0.2 0.4,0.5 0,-0.2 0,-0.7 z m -9.8,-2.2 -0.3,-0.1 -0.4,0.3 -0.1,0.3 -0.1,0.7 0,0.4 0.3,0.7 0.3,0.5 0.3,0.3 0.2,0.2 0.9,0.1 1.7,0.1 0.9,0.4 0.9,0.2 0.4,-0.1 0.5,-0.2 0.1,-0.1 -0.1,-0.6 -0.2,-0.3 -0.4,-0.2 -0.2,-0.6 -0.5,-0.4 -0.9,-0.7 -1.6,0 -0.6,0.1 -1.1,-1 z m 2.6,-1.8 -0.5,0.2 0,0.3 0.4,0.1 0.4,0.2 0.1,0.3 0,0 0.2,-0.1 0.4,0.2 0.2,-0.3 -0.4,-0.5 -0.4,-0.3 -0.1,0 -0.3,-0.1 z m -5.6,0.8 0.3,-0.2 0,-0.4 -0.3,0 -0.1,-0.2 -0.2,0 -0.3,0.2 -0.2,0.3 0.1,0.2 0.4,0 0.2,0.1 0.1,0 z m -8.4,-2.3 -0.1,-0.2 -0.3,-0.2 -0.2,0 -0.5,0.1 0.1,0.1 0.6,0.3 0.3,0.1 0.1,-0.2 z m 3.1,0.4 0.3,-0.2 -0.1,-0.2 -0.1,-0.5 -0.4,0.7 0.1,0.2 0.2,0 z m -0.5,-0.9 0,-0.2 0,-0.2 -0.2,-0.1 0.4,-0.3 -0.1,-0.1 -0.6,-0.2 -0.2,0.2 -0.2,0.1 -0.1,0.1 -0.1,0.1 -0.1,0.5 0.2,0.4 0.4,0.2 0.6,-0.5 z m -4,0.2 -0.3,-0.4 0.1,-0.5 0.2,-0.1 0.2,-0.5 -0.1,-0.4 -0.2,0.1 -0.7,0.6 -0.1,0.3 0.6,0.8 0.3,0.2 0,-0.1 z m 13,-1.3 -0.2,-0.4 0,-0.2 -0.3,-0.2 -0.2,0.1 -0.1,0.3 0.1,0.2 0.4,0.3 0.3,-0.1 z m 6,-1.2 -0.2,0 -0.1,0.1 -0.2,0 -0.3,0 -0.1,0.2 0.6,1.1 -0.3,0.5 0.4,2.2 0.4,1.2 0.8,0.8 0,0.2 0.8,0.5 0.6,1.3 0.2,0.1 0.1,-0.2 0,-0.6 -0.5,-1.1 0.1,-0.8 -0.2,-0.3 0,-0.3 -0.2,-0.8 -0.6,-0.7 -0.3,-0.1 -0.2,-0.3 0.2,-0.6 0.2,-0.2 0.1,-0.3 -1.3,-1.9 z m -16.6,-0.5 -0.6,-0.2 -0.2,-0.3 0,-1 -0.6,-0.3 -0.3,0.2 -0.6,0.7 -0.2,0.4 -0.5,0.3 -0.1,0.3 0,0.4 0.4,0.1 0.3,-0.4 0.9,-0.1 0.3,0.1 0,0.4 0.1,0.7 0.3,0.3 0.5,0.2 0.4,0.6 0.1,-0.3 0.2,0 0.2,-0.4 -0.3,-1.2 -0.3,-0.5 z m -6.5,-0.4 0.1,-0.5 -0.1,-0.9 -0.2,0.1 0,0.2 -0.1,0.4 0.2,0.8 0.1,-0.1 z m 3.2,-0.4 0.2,-0.2 0,-0.4 0,-0.5 -0.2,-0.4 -0.2,-0.2 -0.5,0.1 -0.4,0.5 0,0.5 0.4,0.6 0.6,0 0.1,0 z m -2.6,-1.2 0.2,-0.3 0.5,-0.7 0.1,-0.3 -0.5,-0.2 -0.4,-0.5 -0.4,-0.2 -0.3,0.4 0,0.4 0.5,0.6 -0.1,0.4 0.2,0.1 0.1,0.4 0.1,-0.1 z m 17.5,3.9 -0.1,-0.5 -0.3,-0.4 0.4,-0.5 -2.2,-1.9 -0.3,-0.2 -0.4,-0.1 -0.5,-0.4 -0.5,-0.1 -0.5,-0.4 -0.2,-0.3 -0.6,-0.4 -0.6,-0.8 -1.5,-0.3 0.1,0.2 0.4,0.4 0.1,0.7 0.5,0.4 0.5,0.6 0.2,0.1 0.2,0.2 0.4,0.5 0.8,0.4 0.8,0.6 0.3,0.1 0.3,0.3 1.5,0.7 0.5,0.7 0.7,0.5 0,-0.1 z m -21.8,-9.2 0.2,-0.3 -0.7,-0.5 -0.2,0.3 -0.2,0.5 0.4,0.2 0.5,-0.2 z m 9.1,1.5 -0.1,-0.1 -0.3,0 -0.4,-0.2 -0.7,-0.8 -0.2,-0.3 -0.2,-1 -0.4,-0.4 -1.4,-0.8 -0.8,-0.8 -0.7,-0.2 -0.2,0.2 0,0.5 0.2,0.3 1,0.9 1.1,1.7 1,1 0.8,0.1 0.4,0 0,0.1 0.1,0.2 0.5,0.2 0.5,-0.4 -0.2,-0.2 z";

    List myList;

    myList.addBeginning("YT", "Mayotte", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("SB", "Solomon Is.", d2, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT2", "Mayotte2", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT3", "Mayotte3", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT4", "Mayotte4", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT5", "Mayotte5", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT6", "Mayotte6", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT7", "Mayotte7", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT8", "Mayotte8", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT9", "Mayotte9", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT10", "Mayotte10", d1, "fill:#f2f2f2;fill-rule:evenodd");

    myList.searchAdjacents();

    //myList.first->adjVector->at(2)->updateColor("#252525");

    //cout << "Hello" << endl;

    //myList.printList();

    DivideConquer DC(10);
    DC.listDC.first = myList.first;
    DC.divideList();

    cout << "Final list: " << endl;
    DC.listDC.printList();*/

#endif //PROJECT_1_DIVIDECONQUER_H
