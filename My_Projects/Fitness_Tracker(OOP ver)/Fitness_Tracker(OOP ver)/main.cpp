#include <iostream>
#include "./include/fitnessTracker.h"
using namespace std;

int main(){
    // title
    cout << setfill(' ') << setw(50) << "Welcome to Nan's Health and Fitness Tracker\n";
    cout << setfill('-') << setw(57) << '-' << endl;
    FitnessTracker fitnessTracker;
    fitnessTracker.runProgram();
    return 0;
}
