//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include <chrono>

#include "../headers/Timer.h"

using namespace headers;
using namespace std;
using namespace std::chrono;

Timer::Timer() {
    //This will create the new object
}

void Timer::startTimer(){
    start = high_resolution_clock::now();
}

void Timer::timeStamp() {
    point = high_resolution_clock::now();
    elapsed = point - start;
}

void Timer::printTime() {
    cout << "Execution time: " << (elapsed.count() / 1000) << " seconds" << endl;
}