//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_LIST_H
#define PROJECT_1_LIST_H

#include "../headers/Country.h"

using namespace headers;

typedef Country *pointerCntry;

namespace headers {
    /*
     * This is the class List, is to make the list of countries and the adjacents
     * */
    class List {

        friend class Country;

    public:
        List();
        void addBeginning(string pId, string pName, string pDimensions);
        void addEnd(string pId, string pName, string pDimensions);
        void addAdjacent(string Id, Country *pAdjList);
        void removeFirst();
        void removeLast();
        void removePos(int pPosition);
        bool isListEmpty();
        void printList();
        void moveToNext();
        void moveToBeginning();
        void moveToEnd();
        int listLength();

    //private:
        pointerCntry first;
        pointerCntry current;
    };
}

#endif //PROJECT_1_LIST_H

// This is an example to see if list is working
/*List myList;
List anaAdjacents;
List ledaAdjacents;

myList.addBeginning("Ana", "Gonzalez", "Aguilera");
myList.addBeginning("Leda", "Gonzalez", "Aguilera");

anaAdjacents.addEnd("Kristin", "Alvarado", "Gonzalez");
anaAdjacents.addEnd("Rodrigo", "Alvarado", "Gonzalez");

ledaAdjacents.addEnd("Jose", "Gonzalez", "Aguilera");

myList.addAdjacent("Ana", anaAdjacents.first);
myList.addAdjacent("Leda", ledaAdjacents.first);
myList.printList();

cout << "Now lets remove some people!" << endl;
cout << endl;

myList.removeLast();
myList.removeLast();
myList.printList();*/