//
// Created by Kris on 11/7/2020.
//

#include <iostream>
#include <time.h>
#include <chrono>

#include "../headers/Timer.h"

using namespace tmr;
using namespace std;
using namespace std::chrono;

Timer::Timer() {
    cout << "New Timer created!" << endl;
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