#include "displayMainMenu.hpp"
#include "getUserInfo.hpp"
#include "getMenuOption.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void displayMainMenu(User& user){
    cout << setfill(' ') << setw(15) << "Main Menu" << endl;
    cout << setfill('-') << setw(21) << '-' << endl;
    cout << "1.\tAdd Meal\n";
    cout << "2.\tAdd Workout\n";
    cout << "3.\tTrack Meals\n";
    cout << "4.\tTrack Workouts\n";
    cout << "5.\tRemove Meals\n";
    cout << "6.\tRemove Workouts\n";
    cout << "7.\tView Progress\n";
    cout << "8.\tExit\n";
    cout << setfill('-') << setw(21) << '-' << endl;
    getMenuOption(user);
}
