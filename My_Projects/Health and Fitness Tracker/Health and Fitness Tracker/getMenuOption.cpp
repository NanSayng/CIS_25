#include "getMenuOption.hpp"
#include "addMeal.hpp"
#include "addWorkout.hpp"
#include "trackMeals.hpp"
#include "trackWorkouts.hpp"
#include "removeMeals.hpp"
#include "removeWorkouts.hpp"
#include "viewProgress.hpp"
#include "exitProgram.hpp"
#include "getUserInfo.hpp"
#include <regex>
#include <iostream>
using namespace std;

void getMenuOption(User& user){
    string input;
    int choice;
    // allowed only 1-8 number
    regex reg(R"(^[1-8]$)");
    while(true){
        cout << "Enter your choice [1-8]: ";
        cin >> input;
        // check if choice is invalid or empty
        if(input.empty() || !regex_match(input,reg)){
            cout << "Invalid choice.\n";
        }else{
            break;
        }
    }
    choice = stoi(input);
    // for each options call the corresponding function
    switch (choice) {
        case 1:
            addMeal(user);
            break;
        case 2:
            addWorkout(user);
            break;
        case 3:
            trackMeals(user);
            break;
        case 4:
            trackWorkouts(user);
            break;
        case 5:
            removeMeals(user);
            break;
        case 6:
            removeWorkouts(user);
            break;
        case 7:
            viewProgress(user);
            break;
        case 8:
            exitProgram(user);
            break;
        default:
            break;
    }
}
