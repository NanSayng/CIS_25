#include "addMeal.hpp"
#include "getUserInfo.hpp"
#include "validateString.hpp"
#include "displayMainMenu.hpp"
#include "getMenuOption.hpp"
#include "utils/validateChar.hpp"
#include "utils/validateDouble.hpp"
#include <algorithm>
#include <iostream>
using namespace std;

void addMeal(User& user){
    string mealName, calories, input;
    // get valid meal name
    do{
        while(true){
            cout << "\nEnter meal name: ";
            cin.ignore();
            getline(cin,mealName);
            // check if meal name input is valid
            if(mealName.empty() || !validateString(mealName)){
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
        user.meals.meal.push_back(mealName);
        user.meals.calories.push_back(stod(calories));
        cout << "Meal added: " << mealName << " (" << calories << " calories)\n";
        // ask user if they want to add another meal
        while(true){
            cout << "Do you want to add another meal? (y/n): ";
            cin >> input;
            // check if the answer is valid
            if(input.empty() || !validateChar(input)){
                cout << "Invalid input.\n";
            }else
                break;
        }
    } while(input == "y" || input == "Y"); // if say yes continue adding workouts
    // if no diplay main menu again
    cout << endl;
    displayMainMenu(user);
}
