#include "addWorkout.hpp"
#include "getUserInfo.hpp"
#include "displayMainMenu.hpp"
#include "getMenuOption.hpp"
#include "validateString.hpp"
#include "utils/validateChar.hpp"
#include "utils/validateDouble.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

void addWorkout(User& user){
    string workoutName, calories, input;
    // get valid meal name
    do{
        while(true){
            cout << "Enter workout name: ";
            cin.ignore();
            getline(cin,workoutName);
            // check if meal name input is valid
            if(workoutName.empty() || !validateString(workoutName)){
                cout << "Invalid meal name.\n";
            } else{
                break;
            }
        }
        // get valid meal calories
        while(true){
            cout << "Enter calories: ";
            cin >> calories;
            // check if calories input is invalid or empty
            if(calories.empty() || !validateDouble(calories)){
                cout << "Invalid calorie input.\n";
            }else
                break;
        }
        
        // add meal and calories to user's vector arrays
        user.workouts.workout.push_back(workoutName);
        user.workouts.calories.push_back(stod(calories));
        cout << "Workout added: " << workoutName << " (" << calories << " calories)\n";
        // ask user if they want to add another meal
        while(true){
            cout << "Do you want to add another workout? (y/n): ";
            cin >> input;
            // check if the answer is valid
            if(input.empty() || !validateChar(input)){
                cout << "Invalid answer.\n";
            }else
                break;
        }
    } while(input == "Y" || input == "y"); // if say yes continue adding meals
    // if no diplay main menu again
    displayMainMenu(user);
}
