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
void List::addBeginning(string pId, string pName, string pDimensions, string pStyle) {
    if (!isListEmpty()) {
        first = new Country(pId, pName, pDimensions, pStyle, first);
    }
    else {
        first = new Country(pId, pName, pDimensions, pStyle);
    }
}

// This method will add a new Country at the end fo the list
void List::addEnd(string pId, string pName, string pDimensions, string pStyle) {
    if (!isListEmpty()) {
        pointerCntry auxPointer = first;
        while (auxPointer -> nextCntry != NULL) {
            auxPointer = auxPointer -> nextCntry;
        }
        auxPointer -> nextCntry = new Country(pId, pName, pDimensions, pStyle);
    }
    else {
        first = new Country(pId, pName, pDimensions, pStyle);
    }
}

// This method will add the list of adjacent to a country
/*void List::addAdjacent(Country *pcurrentCountry, Country *pAdjList) {
    if (!isListEmpty()) {
        pointerCntry auxPointer = first;
        bool isFound = false;
        while (auxPointer) { // -> nextCntry != NULL
            if (auxPointer -> id == pId) {
                isFound = true;
                break;
            }
            auxPointer = auxPointer -> nextCntry;
        }
        if (isFound) {
            auxPointer -> adjList = pAdjList;
        }
        else {
            cout << "ID: " << pId << " not found" << endl;
        }
    }
    else {
        cout << "The list is empty" << endl;
    }
}*/

// This method will add the list of adjacent to a country
/*void List::addAdjacent(Country *pCurrentCntry, Country *pAdjList) {
    if (pCurrentCntry) {
        pCurrentCntry->adjList = pAdjList;
    }
    else {
        cout << "The pointer is NULL" << endl;
    }
}*/

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

// This method will review all countries to find the adjacents, create a list of them and link them to the current country
void List::searchAdjacents() {
    pointerCntry cntry = first;

    for (int elementsLts = 0; elementsLts < listLength(); elementsLts++) {

        pointerCntry cntryList = first;

        for (int secElementLts = 0; secElementLts < listLength(); secElementLts++) {
            if (elementsLts != secElementLts) {

                if ((((cntryList -> maxY <= cntry -> maxY) && (cntryList -> maxY >= cntry -> minY)) || ((cntryList -> minY <= cntry -> maxY) && (cntryList -> minY >= cntry -> minY))) &&
                        (((cntryList -> maxX <= cntry -> maxX) && (cntryList -> maxX >= cntry -> minX)) || ((cntryList -> minX <= cntry -> maxX) && (cntryList -> minX >= cntry -> minX)))) {
                    cntry -> adjVector -> push_back(cntryList);
                }
            }

            cntryList = cntryList -> nextCntry;
        }

        cntry = cntry->nextCntry;
    }
}

// This method will print the list
void List::printList() {
    pointerCntry auxPointer = first;

    if (!isListEmpty())
    {
        while (auxPointer) {
            cout << "ID: " << auxPointer -> id << endl;
            cout << "Name: " << auxPointer -> name << endl;
            cout << "Max X: " << auxPointer -> maxX << endl;
            cout << "Max Y: " << auxPointer -> maxY << endl;
            cout << "Min X: " << auxPointer -> minX << endl;
            cout << "Min X: " << auxPointer -> minY << endl;
            cout << "Color: " << auxPointer -> color << endl;
            cout << "#==============================#" << endl;
            cout << endl;

            if (auxPointer -> adjVector -> size() > 0) { // != NULL
                cout << "List of adjacents:" << endl;

                for(auto elements : *auxPointer -> adjVector) {
                    //elements -> updateColor(elements,"#4287f5");
                    cout << "ID: " << elements -> id << endl;
                    cout << "Name: " << elements -> name << endl;
                    cout << "Max X: " << elements -> maxX << endl;
                    cout << "Max Y: " << elements -> maxY << endl;
                    cout << "Min X: " << elements -> minX << endl;
                    cout << "Min X: " << elements -> minY << endl;
                    cout << "Color: " << elements -> color << endl;
                    cout << "#==============================#" << endl;
                    cout << endl;
                }

                cout << "The adjacents ends here!" << endl;
                cout << endl;
            }
            auxPointer = auxPointer -> nextCntry;
        }
    }
    else
    {
        cout << "The list is empty." << endl;
    }
}