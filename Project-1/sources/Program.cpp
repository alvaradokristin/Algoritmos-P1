//
// Created by Kris on 11/23/2020.
//

#include <windows.h>
#include "../headers/Program.h"
#include "../headers/DynamicAlgorithm.h"
#include "DynamicAlgorithm.cpp"
#include "../headers/DivideConquer.h"
#include "DivideConquer.cpp"
#include "Read_XML.cpp"

using namespace headers;
using namespace std;

void Program::start() {

    int numOfColors;
    bool isValid = false;

    cout << "\n#================== Hello! ==================#\n\n";
    cout << "Please provide the number of colors that you want to use to paint the map:";
    cin >> numOfColors;

    if ((numOfColors < 3) || (numOfColors > 11)) {
        while (!isValid) {
            cout << "Please provide a number between 3 and 11:";
            cin >> numOfColors;

            if (numOfColors >= 3 && numOfColors <= 11) {
                isValid = true;
            }
        }
    }

    string filename = "D:\\OneDrive\\Escritorio\\world.svg";

    // This will read the SVG file on the previous path
    Readfile *readDP = new Readfile(filename);
    Readfile *readDC = new Readfile(filename);

    // This will get the file
    string textDP = readDP -> getFile();
    string textDC = readDC -> getFile();

    // This will create the vectors with all the necessary information on the file
    vector<string> vectorDPAll = readDP -> getData(textDP);
    vector<string> vectorDCAll = readDC -> getData(textDC);

    // The list for each algorithm are created here
    List newListDC;
    List newListDynamic;

    // This will populate the list with the information on the vectors
    newListDynamic.create(vectorDPAll);
    newListDC.create(vectorDCAll);

    // This will create the adjacents vectors for each country
    newListDC.searchAdjacents();
    newListDynamic.searchAdjacents();

    cout << "\n----------- Painting the maps with " << numOfColors << " colors -----------\n" << endl;

    // This will create the algorithms objects and start the algorithms
    cout << "Dynamic Programming started..." << endl;
    Dynamic dp(numOfColors,vectorDPAll,filename,readDP->encabezado); // dp -> Dynamic Programming
    dp.DynamicAlgoritm(newListDynamic,0);
    cout << "...Dynamic Programming finished\n" << endl;

    Sleep(2000);

    cout << "Divide and Conquer started..." << endl;
    DivideConquer dc(numOfColors, filename, readDC->encabezado, vectorDCAll); // dc -> Divide and Conquer
    dc.start(newListDC.first);
    cout << "...Divide and Conquer finished\n" << endl;

    Sleep(2000);

    // This will print the information based on the algorithms
    cout << "Dynamic Programming - Final Data:" << endl;
    cout << "Number of countries painted in white: " << dp.CountriesBlanc << endl;
    dp.timerDC.printTime();

    cout << "\n================================================\n" << endl;

    cout << "Divide and Conquer - Final Data:" << endl;
    cout << "Number of countries painted in white: " << dc.whiteCountries << endl;
    dc.timerDC.printTime();
}