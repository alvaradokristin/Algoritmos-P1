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
        void updateMap();
        int getPosVec(vector<string> pColToUSe, string pColor);
        //void printSubG(pointerCntry pInit, pointerCntry pBorder);
        //void printVec(vector<string> pVec);

    //private:
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

/* The active includes in main for the test (only the divide and conquer.h and the read xml.cpp, the resrt are commented)
//#include "headers/Timer.h"
//#include "headers/List.h"
#include "headers/DivideConquer.h"
#include "sources/DivideConquer.cpp"
#include "sources/Read_XML.cpp"
#include "headers/Painter.h"
//#include "sources/Painter.cpp" -- Error
 */

// Test divide and conquer in main
    /*string filename = "D:\\OneDrive\\Escritorio\\world.svg";

    Readfile *read = new Readfile(filename);
    string text =read->getFile();
    vector<string> all = read->getData(text);

    List newListDC;

    newListDC.create(all);

    newListDC.searchAdjacents();

    DivideConquer DC(10, filename, read->encabezado);
    DC.vectorDC = all;
    DC.listDC.first = newListDC.first;
    DC.divideList();

    /*cout << "======================================================================\nFinal list: " << endl;
    DC.listDC.printList();*/

    /*cout << "Number of countries: " << DC.listDC.listLength() << endl;
    cout << "Number of countries that were not painted: " << DC.countriesToColor << endl;
    cout << "Number of countries painted in white: " << DC.whiteCountries << endl;
    DC.updateMap();*/

#endif //PROJECT_1_DIVIDECONQUER_H
