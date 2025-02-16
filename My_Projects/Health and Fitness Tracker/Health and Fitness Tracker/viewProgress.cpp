#include "viewProgress.hpp"
#include "getUserInfo.hpp"
#include "displayMainMenu.hpp"
#include "getMenuOption.hpp"
#include "addMeal.hpp"
#include "utils/validateChar.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

void viewProgress(User&user){
    double totalCalConsumed = 0,
    totalCalBurned = 0,
    netCalories;
    // calculate the total calories consumed
    for(double calorie: user.meals.calories){
        totalCalConsumed += calorie;
    }
    // calculate the total calories burned
    for(double calorie: user.workouts.calories){
        totalCalBurned += calorie;
    }
    // calculate the net calories (consumed - burned)
    netCalories = totalCalConsumed - totalCalBurned;
    cout << endl;
    // progress title
    cout << setfill('-') << setw(15) << "Progress" << setfill('-') << setw(7) << '-' << endl;
    // if no calories added or burned, ask user to add
    if(totalCalConsumed == 0 && totalCalBurned == 0){
        cout << "You haven't logged any meals or workouts yet.\n";
        cout << "Start adding meals and workouts to track your progress!\n\n";
        displayMainMenu(user);
    }else{
        // if there's calories added, show the progress and their calories status
        cout << "\nTotal calories consumed: " << round(totalCalConsumed) << " kcal\n";
        cout << "Total calories burned: " << totalCalBurned << " kcal\n";
        // change to positive sign for display
        cout << "Net calories: " << abs(netCalories) << " kcal\n";
        cout << "Daily calorie intake goal: " << user.dailyCalorieIntake << " kcal\n";
        // display calorie status based on net calories and daily calorie intake goal
        if(netCalories < user.dailyCalorieIntake){
            cout << "You are in a calorie deficit. You are consuming fewer calories than your goal, which may lead to weight loss.\n\n";
        }else if(netCalories > user.dailyCalorieIntake){
            cout << "You are in a calorie surplus. You are exceeding your daily calories intake, which may lead to weight gain.\n\n";
        } else{
            cout << "Your calories are balanced. You're maintaining your current weight.\n";
        }
        string input;
        while(true){
            // after showing progress, ask user if they want to return to main menu
            cout << "Would you like to return to main menu? (y/n): ";
            cin >> input;
            // check if input is empty or invalid
            if(input.empty() || !validateChar(input)){
                cout << "Invalid input.\n";
            }else {
                break;
            }
        }
        if(input == "Y" || input == "y"){
            displayMainMenu(user);
        }else{
            // if no exit the program
            cout << "Exiting the progream. Have a good day!\n";
            exit(0);
        }
    }
}
