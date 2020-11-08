//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include <chrono>

#include "../headers/Timer.h"

using namespace tmr;
using namespace std;
using namespace std::chrono;

Timer::Timer() {
    //This will create the new object
}

void Timer::startTimer(){
    start = high_resolution_clock::now();
}

void Timer::stopTimer() {
    finish = high_resolution_clock::now();
}

void Timer::printTime() {
    elapsed = finish - start;
    cout << "Execution time with " << ": " << elapsed.count() << " msseconds" << endl;
}

// This is an example of the timer:
/*Timer myTimer;
myTimer.startTimer();
// Operation that need to be measured
myTimer.stopTimer();
myTimer.printTime();*/