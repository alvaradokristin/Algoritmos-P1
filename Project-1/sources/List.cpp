//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"
#include "../headers/List.h"

using namespace headers;
using namespace std;

typedef Country *pointerCntry;

List::List() {first = NULL; }

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

void List::create(vector<string> pCountriesList){

    string id,name,dimensions,style;

    for (int indexParser = 0; indexParser < pCountriesList.size();indexParser++){
        id = get_id(pCountriesList.at(indexParser));
        name = get_name(pCountriesList.at(indexParser));
        dimensions = get_dimentions(pCountriesList.at(indexParser));
        style = get_color(pCountriesList.at(indexParser));
        addEnd(id,name,dimensions,style);
    }

}

string List::get_color(string pCountry) {
    string buffer;
    bool pass = false;
    int counter = 0;
    for (int index = 0; index < pCountry.length(); index++) {
        if (pCountry[index - 3] == 'l' and pCountry[index - 2] == ':' and pCountry[index - 1] == '#') {
            pass = true;
        } else if (pass == true and pCountry[index] == ';') {
            pass = false;
        }
        if (pass == true) {
            buffer += pCountry[index];
        }
    }
    return buffer;
}

string List::get_id(string pCountry){
    string buffer;
    bool pass = false;
    bool counter = true;
    for (int indexParser = 0; indexParser < pCountry.length(); indexParser++){
        if ( pCountry[indexParser-4] == 'i' and pCountry[indexParser-3] == 'd' and pCountry[indexParser-2] == '=' and pCountry[indexParser-1] == '"'){
            pass = true;
        }else if (pass == true and pCountry[indexParser] == '"'){
            counter = false;
            pass = false;
        }
        if (pass == true and counter == true){
            buffer += pCountry[indexParser];
        }
    }
    return buffer;
}

string List::get_name(string pCountry){
    string buffer;
    bool pass = false;
    int counter = 0;
    for (int index = 0; index < pCountry.length(); index++) {
        if (pCountry[index - 4] == 'm'  and pCountry[index - 3] == 'e' and pCountry[index - 2] == '=' and pCountry[index - 1] == '"') {
            pass = true;
        } else if (pass == true and pCountry[index] == '"') {
            pass = false;
        }
        if (pass == true) {
            buffer += pCountry[index];
        }
    }
    return buffer;
}

string List::get_dimentions(string pCountry){
    string buffer;
    bool pass = false;
    int counter = 0;
    for (int index = 0; index < pCountry.length(); index++) {
        if (pCountry[index - 3] == 'd'  and pCountry[index - 2] == '=' and pCountry[index - 1] == '"' and pCountry[index] == 'm') {
            pass = true;
        } else if (pass == true and pCountry[index] == '"') {
            pass = false;
        }
        if (pass == true) {
            buffer += pCountry[index];
        }
    }
    return buffer;
}

// This method will add a new Country at the beginning of the list
void List::addBeginning(string pId, string pName, string pDimensions, string pStyle) {
    if (!isListEmpty()) {
        first = new Country(pId, pName, pDimensions, pStyle, first);
        first -> nextCntry -> prevCntry = first;
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
        auxPointer -> nextCntry -> prevCntry = auxPointer;
    }
    else {
        first = new Country(pId, pName, pDimensions, pStyle);
    }
}

// This method will remove the first country on the list
void List::removeFirst() {
    if (!isListEmpty()){
        pointerCntry auxPointer = first;
        if (first -> nextCntry != NULL) {
            first = first -> nextCntry;
            first -> prevCntry = NULL;
        }
        else {
            first = NULL;
        }
        delete auxPointer;
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
            temporalPointer -> prevCntry = NULL;
        }
        else {
            first = NULL;
        }
        delete temporalPointer;
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
            if (auxPointer -> nextCntry -> nextCntry) {
                auxPointer -> nextCntry = auxPointer -> nextCntry -> nextCntry;
                auxPointer -> nextCntry -> prevCntry = auxPointer;
            }
            else {
                auxPointer -> nextCntry = NULL;
            }
        }
        else if (pPosition == 1) {
            first = first -> nextCntry;
            first -> prevCntry = NULL;
        }
        else {
            cout << "The position provided is not valid." << endl;
        }
        delete temporalPointer;
    }
    else {
        cout << "The list is empty." << endl;
    }
}

//This method will make the country that you want, the first country of the list
void List::moveToBeginning(Country *pCurrentCntry) {
    pointerCntry tempPointer = pCurrentCntry -> nextCntry;

    if (!isListEmpty()) {
        if ((listLength() > 2) && (pCurrentCntry != first)) {
            if (tempPointer != NULL) {
                tempPointer -> prevCntry = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry -> nextCntry = tempPointer;
                pCurrentCntry -> nextCntry = first;
                pCurrentCntry -> nextCntry -> prevCntry = pCurrentCntry;
                pCurrentCntry -> prevCntry = NULL;
                first = pCurrentCntry;
            }
            else if (tempPointer == NULL) {
                pCurrentCntry -> prevCntry -> nextCntry = NULL;
                pCurrentCntry -> nextCntry = first;
                first -> prevCntry = pCurrentCntry;
                first = pCurrentCntry;
                first -> prevCntry = NULL;
            }
        }
        else if ((pCurrentCntry == first) || (listLength() == 1)){
            cout << "This country is already at the beginning" << endl;
        }
        else { // The list length is 2 and the second country will become first
            pCurrentCntry -> nextCntry = first;
            first -> prevCntry = pCurrentCntry;
            first -> nextCntry = NULL;
            pCurrentCntry -> prevCntry = NULL;
            first = pCurrentCntry;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}

// This method will move the country you want besides the country you need (before that country)
void List::moveBefore(Country *pCurrentCntry, Country *pBeforeThis) {

    if (!isListEmpty()) {
        if ((pCurrentCntry != pBeforeThis) && (pCurrentCntry -> nextCntry != pBeforeThis)) {
            if ((pCurrentCntry -> nextCntry != NULL) && (pBeforeThis != first) && (pCurrentCntry != first)) {
                pCurrentCntry -> prevCntry -> nextCntry = pCurrentCntry -> nextCntry;
                pCurrentCntry -> nextCntry -> prevCntry = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry = pBeforeThis -> prevCntry;
                pBeforeThis -> prevCntry -> nextCntry = pCurrentCntry;
                pBeforeThis -> prevCntry = pCurrentCntry;
                pCurrentCntry -> nextCntry = pBeforeThis;
            }
            else if ((pBeforeThis == first) || (listLength() == 2) && (pCurrentCntry != first)) {
                moveToBeginning(pCurrentCntry);
            }
            else if ((pCurrentCntry -> nextCntry == NULL) && ((pCurrentCntry != first))) {
                pCurrentCntry -> prevCntry -> nextCntry = NULL;
                pBeforeThis -> prevCntry -> nextCntry = pCurrentCntry;
                pCurrentCntry -> nextCntry = pBeforeThis;
                pCurrentCntry -> prevCntry = pBeforeThis -> prevCntry;
                pBeforeThis -> prevCntry = pCurrentCntry;
            }
            else if (pCurrentCntry == first) {
                first = pCurrentCntry -> nextCntry;
                first -> prevCntry = NULL;
                pCurrentCntry -> nextCntry = pBeforeThis;
                pBeforeThis -> prevCntry -> nextCntry = pCurrentCntry;
                pCurrentCntry -> prevCntry = pBeforeThis -> prevCntry;
                pBeforeThis -> prevCntry = pCurrentCntry;
            }
        }
        else {
            cout << "The country is already at the correct position" << endl;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}

// This method will move the country to the end of the list
/*void List::moveToEnd(Country *pCurrentCntry) {

}*/

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