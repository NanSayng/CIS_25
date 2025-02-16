#include "trackMeals.hpp"
#include "getUserInfo.hpp"
#include "addMeal.hpp"
#include "displayMainMenu.hpp"
#include "utils/validateChar.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

void trackMeals(User& user){
    // string inputs used for user to get input value
    string input1, input2;
    // if user have added meals, display the added meals
    if(!user.meals.meal.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Meals\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.meals.meal); i++){
            cout << i + 1 << ".\t" << user.meals.meal[i] << " (" << user.meals.calories[i] << " kcal)\n";
        }
        while(true){
            // ask if they want to add another meal
            cout << "\nWould you like to add another meal? (y/n): ";
            cin >> input1;
            // check if input is valid
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input1 == "Y" || input1 == "y"){
            addMeal(user);
        }else
            displayMainMenu(user);
    }else{
        // if no meals to diplay, ask user if they want to add meals
        cout << "You haven't add any meals yet.\n";
        while(true){
            cout << "Would you like to add meals? (y/n): ";
            cin >> input2;
            // check if input is valid
            if(input2.empty() || !validateChar(input2)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        // if yes call add meals function
        if(input2 == "Y" || input2 == "y"){
            addMeal(user);
        }else
            displayMainMenu(user);
    }
}
