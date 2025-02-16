#include "trackWorkouts.hpp"
#include "getUserInfo.hpp"
#include "addWorkout.hpp"
#include "displayMainMenu.hpp"
#include "utils/validateChar.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void trackWorkouts(User& user){
    // string inputs used for user to get input value
    string input1, input2;
    // if user have added workouts, display the added workouts
    if(!user.workouts.workout.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.workouts.workout); i++){
            cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
        }
        while(true){
            // ask if they want to add another one
            cout << "\nWould you like to add another workout? (y/n): ";
            cin >> input1;
            // check if input is valid
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        // if yes, call addworkout function
        if(input1 == "Y" || input1 == "y"){
            addWorkout(user);
        }else
            displayMainMenu(user);
    }else{
        // if there's no workouts to display, ask user if they want to add
        cout << "You haven't add any workouts yet.\n";
        while(true){
            cout << "Would you like to add workout? (y/n): ";
            cin >> input2;
            // check if input is valid
            if(input2.empty() || !validateChar(input2)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        // if yes call addworkout function
        if(input2 == "Y" || input2 == "y"){
            addWorkout(user);
        }else
            displayMainMenu(user);
    }
}
