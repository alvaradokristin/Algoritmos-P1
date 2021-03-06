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
        friend class Dynamic;
        friend class Program;

    public:
        List();
        void create(vector<string> pCountriesList);
        string get_color(string pCountry);
        string get_id(string pCountry);
        string get_name(string pCountry);
        string get_dimentions(string pCountry);
        void addBeginning(string pId, string pName, string pDimensions, string pStyle);
        void addEnd(string pId, string pName, string pDimensions, string pStyle);
        Country *getposition(int pPos);
        bool isListEmpty();
        void printList();
        void moveToBeginning(Country *pCurrentCntry);
        void moveBefore(Country *pCurrentCntry, Country *pBeforeThis);
        int listLength();
        void searchAdjacents();
        bool validateRep(pointerCntry pCntry, pointerCntry pNewCntry);

    //private:
        pointerCntry first;
        pointerCntry last;
    };
}

#endif //PROJECT_1_LIST_H

// This is an example to see if list is working
    /*string d1 = "m 1228.7,654.7 0,-0.3 0.2,-0.5 0,-0.1 0.1,-0.5 -0.3,-0.3 -0.2,0 -0.2,-0.3 -0.3,0.3 0.3,0.5 -0.1,0.3 -0.1,0.4 0.1,0.4 0.2,0.2 0.3,-0.1 z";
    string d2 = "m 1909.1,646.4 -0.2,-0.2 -0.1,-0.4 -0.3,0 -0.3,0.1 0.2,0.6 0.2,0 0.5,-0.1 z m -35.6,0.8 -0.1,-0.2 -0.5,-0.4 -1.9,-1.3 -0.4,-0.1 -0.1,0.1 -0.1,0.3 0.1,0.2 0.5,0.1 0,0.1 0.3,0.2 0.7,0.2 0.4,0.3 0.1,0.5 0.3,0.1 0.3,0.1 0.4,-0.2 z m 32,-6.6 0,-0.1 0.2,-0.3 -0.2,-0.1 -0.5,-0.1 -0.7,0.1 -0.3,0.2 -0.2,0.3 -0.2,0 0,0.2 0.1,0.4 0.2,-0.1 0.2,0.1 0.5,-0.5 0.3,0 0.1,0 0.5,-0.1 z m -24.4,-2.3 -0.1,-0.2 -0.2,-0.1 -0.9,-0.7 -0.5,-0.2 -0.5,0 -0.1,0.5 0,0.3 0.6,0 0.4,0.2 0,0.6 0.2,0.2 0,0.5 1.2,0.9 0.7,0.4 0.7,0.1 0.4,0.2 0.5,-0.1 0.5,0.2 0.4,-0.1 -0.4,-0.3 0,-0.4 -0.5,-1.3 -0.3,-0.3 -0.5,0.1 -0.5,-0.2 -0.4,0 -0.7,-0.3 z m -0.4,-4.9 -0.6,-1.6 -0.2,-0.1 0.1,0.6 0.1,0.4 -0.1,0.5 -0.1,0.6 0.2,0.2 0.2,-0.2 0.4,0.5 0,-0.2 0,-0.7 z m -9.8,-2.2 -0.3,-0.1 -0.4,0.3 -0.1,0.3 -0.1,0.7 0,0.4 0.3,0.7 0.3,0.5 0.3,0.3 0.2,0.2 0.9,0.1 1.7,0.1 0.9,0.4 0.9,0.2 0.4,-0.1 0.5,-0.2 0.1,-0.1 -0.1,-0.6 -0.2,-0.3 -0.4,-0.2 -0.2,-0.6 -0.5,-0.4 -0.9,-0.7 -1.6,0 -0.6,0.1 -1.1,-1 z m 2.6,-1.8 -0.5,0.2 0,0.3 0.4,0.1 0.4,0.2 0.1,0.3 0,0 0.2,-0.1 0.4,0.2 0.2,-0.3 -0.4,-0.5 -0.4,-0.3 -0.1,0 -0.3,-0.1 z m -5.6,0.8 0.3,-0.2 0,-0.4 -0.3,0 -0.1,-0.2 -0.2,0 -0.3,0.2 -0.2,0.3 0.1,0.2 0.4,0 0.2,0.1 0.1,0 z m -8.4,-2.3 -0.1,-0.2 -0.3,-0.2 -0.2,0 -0.5,0.1 0.1,0.1 0.6,0.3 0.3,0.1 0.1,-0.2 z m 3.1,0.4 0.3,-0.2 -0.1,-0.2 -0.1,-0.5 -0.4,0.7 0.1,0.2 0.2,0 z m -0.5,-0.9 0,-0.2 0,-0.2 -0.2,-0.1 0.4,-0.3 -0.1,-0.1 -0.6,-0.2 -0.2,0.2 -0.2,0.1 -0.1,0.1 -0.1,0.1 -0.1,0.5 0.2,0.4 0.4,0.2 0.6,-0.5 z m -4,0.2 -0.3,-0.4 0.1,-0.5 0.2,-0.1 0.2,-0.5 -0.1,-0.4 -0.2,0.1 -0.7,0.6 -0.1,0.3 0.6,0.8 0.3,0.2 0,-0.1 z m 13,-1.3 -0.2,-0.4 0,-0.2 -0.3,-0.2 -0.2,0.1 -0.1,0.3 0.1,0.2 0.4,0.3 0.3,-0.1 z m 6,-1.2 -0.2,0 -0.1,0.1 -0.2,0 -0.3,0 -0.1,0.2 0.6,1.1 -0.3,0.5 0.4,2.2 0.4,1.2 0.8,0.8 0,0.2 0.8,0.5 0.6,1.3 0.2,0.1 0.1,-0.2 0,-0.6 -0.5,-1.1 0.1,-0.8 -0.2,-0.3 0,-0.3 -0.2,-0.8 -0.6,-0.7 -0.3,-0.1 -0.2,-0.3 0.2,-0.6 0.2,-0.2 0.1,-0.3 -1.3,-1.9 z m -16.6,-0.5 -0.6,-0.2 -0.2,-0.3 0,-1 -0.6,-0.3 -0.3,0.2 -0.6,0.7 -0.2,0.4 -0.5,0.3 -0.1,0.3 0,0.4 0.4,0.1 0.3,-0.4 0.9,-0.1 0.3,0.1 0,0.4 0.1,0.7 0.3,0.3 0.5,0.2 0.4,0.6 0.1,-0.3 0.2,0 0.2,-0.4 -0.3,-1.2 -0.3,-0.5 z m -6.5,-0.4 0.1,-0.5 -0.1,-0.9 -0.2,0.1 0,0.2 -0.1,0.4 0.2,0.8 0.1,-0.1 z m 3.2,-0.4 0.2,-0.2 0,-0.4 0,-0.5 -0.2,-0.4 -0.2,-0.2 -0.5,0.1 -0.4,0.5 0,0.5 0.4,0.6 0.6,0 0.1,0 z m -2.6,-1.2 0.2,-0.3 0.5,-0.7 0.1,-0.3 -0.5,-0.2 -0.4,-0.5 -0.4,-0.2 -0.3,0.4 0,0.4 0.5,0.6 -0.1,0.4 0.2,0.1 0.1,0.4 0.1,-0.1 z m 17.5,3.9 -0.1,-0.5 -0.3,-0.4 0.4,-0.5 -2.2,-1.9 -0.3,-0.2 -0.4,-0.1 -0.5,-0.4 -0.5,-0.1 -0.5,-0.4 -0.2,-0.3 -0.6,-0.4 -0.6,-0.8 -1.5,-0.3 0.1,0.2 0.4,0.4 0.1,0.7 0.5,0.4 0.5,0.6 0.2,0.1 0.2,0.2 0.4,0.5 0.8,0.4 0.8,0.6 0.3,0.1 0.3,0.3 1.5,0.7 0.5,0.7 0.7,0.5 0,-0.1 z m -21.8,-9.2 0.2,-0.3 -0.7,-0.5 -0.2,0.3 -0.2,0.5 0.4,0.2 0.5,-0.2 z m 9.1,1.5 -0.1,-0.1 -0.3,0 -0.4,-0.2 -0.7,-0.8 -0.2,-0.3 -0.2,-1 -0.4,-0.4 -1.4,-0.8 -0.8,-0.8 -0.7,-0.2 -0.2,0.2 0,0.5 0.2,0.3 1,0.9 1.1,1.7 1,1 0.8,0.1 0.4,0 0,0.1 0.1,0.2 0.5,0.2 0.5,-0.4 -0.2,-0.2 z";

    List myList;

    myList.addBeginning("YT", "Mayotte", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("SB", "Solomon Is.", d2, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT2", "Mayotte2", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT3", "Mayotte3", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT4", "Mayotte4", d1, "fill:#f2f2f2;fill-rule:evenodd");

    myList.searchAdjacents();

     myList.first->adjVector->at(2)->updateColor("#252525");

    myList.printList();*/

// Another test:
    /*myList.addBeginning("YT", "Mayotte", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("SB", "Solomon Is.", d2, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT2", "Mayotte2", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT3", "Mayotte3", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT4", "Mayotte4", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT5", "Mayotte5", d1, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT6", "Mayotte6", d2, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT7", "Mayotte7", d2, "fill:#f2f2f2;fill-rule:evenodd");
    myList.addEnd("YT8", "Mayotte8", d2, "fill:#f2f2f2;fill-rule:evenodd");

    myList.printList();

    cout << "Let's move some countries" << endl;
    pointerCntry  temp = myList.first -> nextCntry -> nextCntry -> nextCntry -> nextCntry -> nextCntry; // YT5
    pointerCntry  temp2 = myList.first -> nextCntry -> nextCntry -> nextCntry -> nextCntry; // YT4
    pointerCntry  tempBefore = myList.first -> nextCntry;

    myList.moveBefore(temp, tempBefore);
    myList.moveBefore(temp2, tempBefore);
    //myList.moveBefore(temp2, myList.first);
    myList.moveBefore(myList.first, temp2);

    //myList.searchAdjacents();

    myList.printList();*/