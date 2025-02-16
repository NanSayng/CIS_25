#include "removeMeals.hpp"
#include "getUserInfo.hpp"
#include "addMeal.hpp"
#include "displayMainMenu.hpp"
#include "utils/validateChar.hpp"
#include "utils/validateInt.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

void removeMeals(User& user){
    // index of the array user want to remove
    int index;
    // if meals array empty, ask user if they want to add one
    if(user.meals.meal.empty()){
        cout << "There's no meal to be removed.\n";
        string input1;
        while(true){
            cout << "Would you like to add a meal? (y/n): ";
            cin >> input1;
            // check if user input is valid y or n
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        if(input1 == "y" || input1 == "Y"){
            addMeal(user);
        }else{
            displayMainMenu(user);
        }
    }else{
        // if there's meals, display added meals
        cout << "\n" << setfill(' ') << setw(20) << "Added Meals\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.meals.meal); i++){
            cout << i + 1 << ".\t" << user.meals.meal[i] << " (" << user.meals.calories[i] << " kcal)\n";
        }
        string input2;
        while(true){
            cout << "\nEnter the meal number to remove: ";
            cin >> input2;
            // check if the meal number is valid
            if(input2.empty() || !validateInt(input2) || input2 == "0"){
                cout << "Invalid input.\n";
            }else if(stoi(input2) > size(user.meals.meal)){  // if number exceed the number of meals
                cout << "There's only " << size(user.meals.meal) << " meals added.\n";
            }else{
                break;
            }
        }
        // get the index of meals to remove
        index = stoi(input2) - 1;
        string removedMeal = user.meals.meal[index];
        user.meals.meal.erase(user.meals.meal.begin() + index);
        user.meals.calories.erase(user.meals.calories.begin() + index);
        cout << endl;
        cout << removedMeal << " has been removed.\n";
        // if meals array become empty, ask user if they want to add meals
        if(user.meals.meal.empty()){
            cout << "There's no meal left.\n";
            string input3;
            while(true){
                cout << "Would you like to add a meal? (y/n): ";
                cin >> input3;
                // check if user input is valid y or n
                if(input3.empty() || !validateChar(input3)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input3 == "y" || input3 == "Y"){
                addMeal(user);
            }else{
                displayMainMenu(user);
            }
        }else{
            // if there still meals left, show the updated meals
            cout << "\n" << setfill(' ') << setw(20) << "Updated Meals\n";
            cout << setfill('-') << setw(30) << '-' << endl;
            for(int i = 0; i < size(user.meals.meal); i++){
                cout << i + 1 << ".\t" << user.meals.meal[i] << " (" << user.meals.calories[i] << " kcal)\n";
            }
            string input4;
            while(true){
                // ask user if they want to remove another meal
                cout << "Would you like to remove another meal? (y/n): ";
                cin >> input4;
                // check if user input is valid y or n
                if(input4.empty() || !validateChar(input4)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input4 == "Y" || input4 == "y"){
                removeMeals(user); // if yes, call removeMeals again
            }else{
                displayMainMenu(user);
            }
        }
    }
}
