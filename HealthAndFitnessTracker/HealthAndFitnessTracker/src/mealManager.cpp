#include "../include/mealManager.h"
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
