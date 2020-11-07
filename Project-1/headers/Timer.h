//
// Created by Kris on 11/7/2020.
//

#ifndef PROJECT_1_TIMER_H
#define PROJECT_1_TIMER_H

#endif //PROJECT_1_TIMER_H

using namespace std;
using namespace std::chrono;

namespace tmr {
    /*
     * This is the class Timer, to measure the execution time of the different algorithms
     * */
    class Timer {
    public:
        Timer();
        void startTimer();
        void stopTimer();
        void printTime();

    private:
        high_resolution_clock::time_point start;
        high_resolution_clock::time_point  finish;
        duration<double, milli> elapsed;
    };
}