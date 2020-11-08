//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_LIST_H
#define PROJECT_1_LIST_H

#include "../headers/Country.h"

using namespace cntry;

typedef Country *pointerCntry;

namespace lst {
    class List {

    public:
        List();
        void addBeginning(string pId, string pName, string pDimensions);
        void addEnd(string pId, string pName, string pDimensions);
        //void insertPos(string pId, string pName, string pDimensions, int pPosition);
        void removeFirst();
        void removeLast();
        void removePos(int pPosition);
        bool isListEmpty();
        void printList();
        void moveToNext();
        void moveToBeginning();
        void moveToEnd();
        int listLength();

    private:
        pointerCntry first;
        pointerCntry current;
    };
}

#endif //PROJECT_1_LIST_H