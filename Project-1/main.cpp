#include <iostream>
#include <time.h>
#include <chrono>

#include "headers/Timer.h"

using namespace tmr;
using namespace std;
using namespace std::chrono;

int main() {
    //std::cout << "Hello, World!" << std::endl;

    // This is an example of the timer:
    Timer myTimer;
    myTimer.startTimer();
    for (int i = 0; i < 100; i++){
        cout << "Hello, World! " << i << endl;
    }
    myTimer.stopTimer();
    myTimer.printTime();

    return 0;
}
