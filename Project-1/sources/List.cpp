//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"
#include "../headers/List.h"

using namespace headers;
using namespace std;

typedef Country *pointerCntry;

List::List() {first = current = NULL; }

bool List::isListEmpty() { return first == NULL ;}

int List::listLength()
{
    int counter = 0;

    pointerCntry auxPointer;
    auxPointer = first;

    if (!isListEmpty()) {
        while (auxPointer != NULL) {
            auxPointer = auxPointer -> nextCntry;
            counter++;
        }
        return counter;
    }
    else {
        return counter;
    }
}

// This method will add a new Country at the beginning of the list
void List::addBeginning(string pId, string pName, string pDimensions) {
    if (!isListEmpty()) {
        first = new Country(pId, pName, pDimensions, first);
    }
    else {
        first = new Country(pId, pName, pDimensions);
    }
}

// This method will add a new Country at the end fo the list
void List::addEnd(string pId, string pName, string pDimensions) {
    if (!isListEmpty()) {
        pointerCntry auxPointer = first;
        while (auxPointer -> nextCntry != NULL) {
            auxPointer = auxPointer -> nextCntry;
        }
        auxPointer -> nextCntry = new Country(pId, pName, pDimensions);
    }
    else {
        first = new Country(pId, pName, pDimensions);
    }
}

// This method will remove the first country on the list
void List::removeFirst() {
    if (!isListEmpty()){
        if (first -> nextCntry != NULL) {
            pointerCntry auxPointer = first;
            first = first -> nextCntry;
            delete auxPointer;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}

// This method will remove the last country on the list
void List::removeLast() {
    pointerCntry temporalPointer = first;

    if (!isListEmpty()) {
        if (first -> nextCntry != NULL) {
            pointerCntry auxPointer = first;

            while (auxPointer -> nextCntry -> nextCntry != NULL) {
                auxPointer = auxPointer -> nextCntry;
            }
            temporalPointer = auxPointer -> nextCntry;
            auxPointer -> nextCntry = NULL;
            delete temporalPointer;
        }
        else {
            first = NULL;
            delete temporalPointer;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}

// This method will remove the contri on position X
void List::removePos(int pPosition) {
    pointerCntry temporalPointer = first;

    if (!isListEmpty()) {
        if ((pPosition <= listLength()) && (pPosition > 0)) {
            int counter = 2;
            pointerCntry auxPointer = first;

            while (counter < pPosition) {
                auxPointer = auxPointer -> nextCntry;
                counter++;
            }

            temporalPointer = auxPointer -> nextCntry;
            auxPointer -> nextCntry = auxPointer -> nextCntry -> nextCntry;
            delete temporalPointer;
        }
        else if (pPosition == 1) {
            first = first -> nextCntry;
            delete temporalPointer;
        }
        else {
            cout << "The position provided is not valid." << endl;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}

//This method will move actual to the first node
void List::moveToBeginning() {
    current = first;
}

// This method will move actual pointer to the next node
void List::moveToNext() {
    if (current) current = current -> nextCntry;
}

// This method will move actual to the final node
void List::moveToEnd() {
    current = first;
    if(!isListEmpty())
        while(current -> nextCntry) moveToNext();
}

// This method will print the list
void List::printList() {
    pointerCntry auxPointer;
    auxPointer = first;

    if (!isListEmpty())
    {
        while (auxPointer)
        {
            cout << "ID: " << auxPointer -> id << endl;
            cout << "Name: " << auxPointer -> name << endl;
            cout << "Dimensions: " << auxPointer -> dimensions << endl;
            cout << "#==============================#" << endl;
            cout << endl;
            auxPointer = auxPointer -> nextCntry;
        }
    }
    else
    {
        cout << "The list is empty." << endl;
    }
}