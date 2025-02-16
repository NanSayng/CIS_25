#include "removeWorkouts.hpp"
#include "getUserInfo.hpp"
#include "addWorkout.hpp"
#include "displayMainMenu.hpp"
#include "utils/validateChar.hpp"
#include "utils/validateInt.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

void removeWorkouts(User& user){
    int index;
    // if there's not workout to be removed yet, ask user if they want to add one
    if(user.workouts.workout.empty()){
        cout << "There's no workout to be removed.\n";
        string input1;
        while(true){
            cout << "Would you like to add a workout? (y/n): ";
            cin >> input1;
            // check if user input is valid y or n
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        if(input1 == "y" || input1 == "Y"){
            addWorkout(user);
        }else{
            displayMainMenu(user);
        }
    }else{
        // display added workouts
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.workouts.workout); i++){
            cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
        }
        string input2;
        while(true){
            // ask user which workout they want to remove
            cout << "\nEnter the workout number to remove: ";
            cin >> input2;
            // check if the meal number is valid
            if(input2.empty() || !validateInt(input2) || input2 == "0"){
                cout << "Invalid input.\n";
            }else if(stoi(input2) > size(user.workouts.workout)){
                cout << "There's only " << size(user.workouts.workout) << "workouts added.\n";
            }else{
                break;
            }
        }
        // get the index of workout that user want to remove
        index = stoi(input2) - 1;
        string removedWorkout = user.workouts.workout[index];
        user.workouts.workout.erase(user.workouts.workout.begin() + index);
        user.workouts.calories.erase(user.workouts.calories.begin() + index);
        cout << endl;
        cout << removedWorkout << " has been removed.\n";
        // if workouts become empty, ask user if they want to add workouts
        if(user.workouts.workout.empty()){
            cout << "There's no workout left.\n";
            string input3;
            while(true){
                cout << "Would you like to add a workout? (y/n): ";
                cin >> input3;
                // check if user input is valid y or n
                if(input3.empty() || !validateChar(input3)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input3 == "y" || input3 == "Y"){
                addWorkout(user);
            }else{
                displayMainMenu(user);
            }
        }else{
            // show updated workouts after removing
            cout << "\n" << setfill(' ') << setw(20) << "Updated Workouts\n";
            cout << setfill('-') << setw(30) << '-' << endl;
            for(int i = 0; i < size(user.workouts.workout); i++){
                cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
            }
            string input4;
            while(true){
                // ask if they want to remove another one
                cout << "Would you like to remove another workout? (y/n): ";
                cin >> input4;
                // check if user input is valid y or n
                if(input4.empty() || !validateChar(input4)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input4 == "Y" || input4 == "y"){
                removeWorkouts(user);
            }else{
                displayMainMenu(user);
            }
        }
    }
}
