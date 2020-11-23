//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_TIMER_H
#define PROJECT_1_TIMER_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

namespace headers {
    /*
     * This is the class Timer, to measure the execution time of the different algorithms
     * */
    class Timer {
    public:
        Timer();
        void startTimer();
        void timeStamp();
        void printTime();
        duration<double, milli> elapsed;

    private:
        high_resolution_clock::time_point start;
        high_resolution_clock::time_point  point;

    };
}

#endif //PROJECT_1_TIMER_H

// This is an example of the timer:
/*Timer myTimer;
myTimer.startTimer();
// Operation that need to be measured
myTimer.timeStamp();
myTimer.printTime();*/