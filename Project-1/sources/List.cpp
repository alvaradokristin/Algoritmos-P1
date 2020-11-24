//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include "../headers/Country.h"
#include "../headers/List.h"

using namespace headers;
using namespace std;

typedef Country *pointerCntry;

List::List() {first = nullptr; last = nullptr; }

bool List::isListEmpty() { return first == nullptr ;}

int List::listLength()
{
    int counter = 0;

    pointerCntry auxPointer;
    auxPointer = first;

    if (!isListEmpty()) {
        while (auxPointer != nullptr) {
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
        if (pCountry[index] == 'f' and pCountry[index + 1] == 'i' and pCountry[index+2] == 'l' and pCountry[index+3] == 'l') {
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

Country *List::getposition(int pPos){
    Country *temp = first;
    int counter = 0;
    while (temp != nullptr){
        if (counter == pPos){
            return temp;
        }
        temp = temp->nextCntry;
        counter++;
    }
    return nullptr;
}

// This method will add a new Country at the beginning of the list
void List::addBeginning(string pId, string pName, string pDimensions, string pStyle) {
    if (!isListEmpty()) {
        first = new Country(pId, pName, pDimensions, pStyle, first);
        first -> nextCntry -> prevCntry = first;
    }
    else {
        first = new Country(pId, pName, pDimensions, pStyle);
        last = first;
    }
}

// This method will add a new Country at the end fo the list
void List::addEnd(string pId, string pName, string pDimensions, string pStyle) {
    if (!isListEmpty()) {
        pointerCntry auxPointer = first;
        while (auxPointer -> nextCntry != nullptr) {
            auxPointer = auxPointer -> nextCntry;
        }
        auxPointer -> nextCntry = new Country(pId, pName, pDimensions, pStyle);
        auxPointer -> nextCntry -> prevCntry = auxPointer;
        last = auxPointer -> nextCntry;
    }
    else {
        first = new Country(pId, pName, pDimensions, pStyle);
        last = first;
    }
}

//This method will make the country that you want, the first country of the list
void List::moveToBeginning(Country *pCurrentCntry) {
    pointerCntry tempPointer = pCurrentCntry -> nextCntry;

    if (!isListEmpty()) {
        if ((listLength() > 2) && (pCurrentCntry != first)) {
            if (tempPointer != nullptr) {
                tempPointer -> prevCntry = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry -> nextCntry = tempPointer;
                pCurrentCntry -> nextCntry = first;
                pCurrentCntry -> nextCntry -> prevCntry = pCurrentCntry;
                pCurrentCntry -> prevCntry = nullptr;
                first = pCurrentCntry;
            }
            else if (tempPointer == nullptr) {
                last = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry -> nextCntry = nullptr;
                pCurrentCntry -> nextCntry = first;
                first -> prevCntry = pCurrentCntry;
                first = pCurrentCntry;
                first -> prevCntry = nullptr;
            }
        }
        else if ((pCurrentCntry == first) || (listLength() == 1)){
            cout << "This country is already at the beginning" << endl;
        }
        else { // The list length is 2 and the second country will become first
            pCurrentCntry -> nextCntry = first;
            first -> prevCntry = pCurrentCntry;
            first -> nextCntry = nullptr;
            pCurrentCntry -> prevCntry = nullptr;
            last - first;
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
            if ((pCurrentCntry -> nextCntry != nullptr) && (pBeforeThis != first) && (pCurrentCntry != first)) {
                pCurrentCntry -> prevCntry -> nextCntry = pCurrentCntry -> nextCntry;
                pCurrentCntry -> nextCntry -> prevCntry = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry = pBeforeThis -> prevCntry;
                pBeforeThis -> prevCntry -> nextCntry = pCurrentCntry;
                pBeforeThis -> prevCntry = pCurrentCntry;
                pCurrentCntry -> nextCntry = pBeforeThis;
            }
            else if (((pBeforeThis == first) || (listLength() == 2)) && (pCurrentCntry != first)) {
                moveToBeginning(pCurrentCntry);
            }
            else if ((pCurrentCntry -> nextCntry == nullptr) && ((pCurrentCntry != first))) {
                last = pCurrentCntry -> prevCntry;
                pCurrentCntry -> prevCntry -> nextCntry = nullptr;
                pBeforeThis -> prevCntry -> nextCntry = pCurrentCntry;
                pCurrentCntry -> nextCntry = pBeforeThis;
                pCurrentCntry -> prevCntry = pBeforeThis -> prevCntry;
                pBeforeThis -> prevCntry = pCurrentCntry;
            }
            else if (pCurrentCntry == first) {
                first = pCurrentCntry -> nextCntry;
                first -> prevCntry = nullptr;
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
    bool isFound = false;

    for (int elementsLts = 0; elementsLts < listLength(); elementsLts++) {

        pointerCntry cntryList = first;

        for (int secElementLts = 0; secElementLts < listLength(); secElementLts++) {
            if (elementsLts != secElementLts) {

                if ((((cntryList -> maxY <= cntry -> maxY) && (cntryList -> maxY >= cntry -> minY)) || ((cntryList -> minY <= cntry -> maxY) && (cntryList -> minY >= cntry -> minY))) &&
                        (((cntryList -> maxX <= cntry -> maxX) && (cntryList -> maxX >= cntry -> minX)) || ((cntryList -> minX <= cntry -> maxX) && (cntryList -> minX >= cntry -> minX)))) {

                    isFound = validateRep(cntry, cntryList);
                    if (!isFound) {
                        cntry -> adjVector -> push_back(cntryList);
                    }
                    isFound = validateRep(cntryList, cntry);
                    if (!isFound) {
                        cntryList -> adjVector -> push_back(cntry);
                    }
                }
            }

            cntryList = cntryList -> nextCntry;
        }

        cntry = cntry->nextCntry;
    }
}

// This funtion will validate that we are not adding duplicates to the adjacents vectors
bool List::validateRep(pointerCntry pCntry, pointerCntry pNewCntry) {
    bool isFound = false;

    if (pCntry -> adjVector->size() > 0) {
        for (auto adjCntry : *pCntry -> adjVector) {
            if (adjCntry == pNewCntry) {
                isFound = true;
                break;
            }
        }
    }
    else {
        return false;
    }
    return isFound;
}

// This method will print the list
void List::printList() {
    pointerCntry auxPointer = first;
    bool all = true;

    if (!isListEmpty()) {
        while (auxPointer) {
            if (all) { // auxPointer->id == "CF"
                cout << "ID: " << auxPointer->id << endl;
                cout << "Name: " << auxPointer->name << endl;
                cout << "Max X: " << auxPointer->maxX << endl;
                cout << "Min X: " << auxPointer->minX << endl;
                cout << "Max Y: " << auxPointer->maxY << endl;
                cout << "Min Y: " << auxPointer->minY << endl;
                cout << "Color: " << auxPointer->color << endl;
                cout << "Num Adj: " << auxPointer->adjVector->size() << endl;
                cout << "#==============================#" << endl;
                cout << endl;

                /*if (auxPointer->adjVector->size() > 0) { //-> size() > 0
                    cout << "====================================List of adjacents:===================================="
                         << endl;

                    for (auto elements : *auxPointer->adjVector) {
                        cout << "ID: " << elements->id << endl;
                        cout << "Name: " << elements->name << endl;
                        cout << "Max X: " << elements->maxX << endl;
                        cout << "Min X: " << elements->minX << endl;
                        cout << "Max Y: " << elements->maxY << endl;
                        cout << "Min Y: " << elements->minY << endl;
                        cout << "Color: " << elements->color << endl;
                        cout << "#==============================#" << endl;
                        cout << endl;
                    }

                    cout
                            << "====================================The adjacents ends here!===================================="
                            << endl;
                    cout << endl;
                }*/
            }
            auxPointer = auxPointer -> nextCntry;
        }
    }
    else {
        cout << "The list is empty." << endl;
    }
}