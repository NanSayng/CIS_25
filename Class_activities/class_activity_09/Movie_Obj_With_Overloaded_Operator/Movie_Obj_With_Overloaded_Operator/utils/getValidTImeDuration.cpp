#include "getValidTImeDuration.hpp"

void getValidTimeDuration(short& hr, short& min, short& sec){
    while(true){
        cout << "Enter the movie durations (hr min sec): ";
        cin >> hr >> min >> sec;
        if(cin.fail() || hr < 0 || min < 0 || sec < 0){
            cout << "Invalid time.\n";
        }else{
            break;
        }
    }
}
