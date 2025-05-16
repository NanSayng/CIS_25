//
//  user.cpp
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#include "../include/user.h"
#include <iostream>
using namespace std;

string User::getUsername(){
    while(true){
        cout << "Enter your name: ";
        getline(cin, name);
        if(name.empty() || !validName(name)){
            cout << "Invalid name.\n";
        }
        break;
    }
    return name;
}

int User::getUserAge(){
    while(true){
        cout << "Enter your age: ";
        cin >> age;
        if(cin.fail()){
            cout << "Invalid age.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else if(age <= 10 || age >= 120){
            cout << "Must be between 10 and 120 years old.\n";
        }
        break;
    }
    return age;
}

Gender User::getUserGender(){
    string gen;
    while(true){
        cout << "Enter your gender 'm/M' for Male, 'f/F' for Female: ";
        cin >> gen;
        if(gen.empty() || !validGender(gen)){
            cout << "Invalid input.\n";
        }
    }
    return (gen == "m" || gen == "M") ? Gender::Male : Gender::Female;
}

double User::getUserCurrWeight(){
    while(true){
        cout << "Enter your current weight in kg: ";
        cin >> currentWeight;
        if(cin.fail()){
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else if(currentWeight < 20.0 || currentWeight > 300.0){
            cout << "The weight must be between 20 and 300 kg.\n";
        }
        break;
    }
    return currentWeight;
}

double User::getUserGoalWeight(){
    while(true){
        cout << "Enter your current weight in kg: ";
        cin >> goalWeight;
        if(cin.fail()){
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    }
    return goalWeight;
}

FitnessGoal User::getUserFitnessGoal(){
    int choice;
    cout << "\nWhat is your fitness goal?\n";
    cout << "1. Lose Weight\n";
    cout << "2. Gain Muscle\n";
    cout << "3. Maintain Weight\n";
    while(true){
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 3){
            cout << "Invalid choice.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    }
    return (choice == 1) ? FitnessGoal::LoseWeight : (choice == 2) ? FitnessGoal::GainMuscle : FitnessGoal::MaintainWeight;
}

ActivityLevel User::getUserActivityLevel(){
    int choice;
    cout << "\nHow active are you?\n";
    cout << "1.\tSedentary (little to no exercise)\n";
    cout << "2.\tLightly Active (1-3 days exercise per week)\n";
    cout << "3.\tModerately Active (3-5 days exercise per week)\n";
    cout << "4.\tVery Active (6-7 days exercise per week\n";
    while(true){
        cout << "Enter your active level [1-4]: ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 4){
            cout << "Invalid choice.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        break;
    }
    return (choice == 1)
    ? ActivityLevel::Sedentary
    : (choice == 2)
    ? ActivityLevel::LightlyActive
    : (choice == 3)
    ? ActivityLevel::ModeratelyActive
    : ActivityLevel::VeryActive;
}

void User::getUserInfo(){
    getUsername();
    getUserAge();
    getUserGender();
    getUserCurrWeight();
    getUserGoalWeight();
    getUserFitnessGoal();
    getUserActivityLevel();
}

double User::calculateBMR() const{
    double BMR;
    if(gender == Gender::Male){
        // for male
        BMR = (10 * currentWeight) + (6.25 * height) - (5 * age) + 5;
    }else{
        // for female
        BMR = (10 * currentWeight) + (6.25 * height) - (5 * age) - 161;
    }
    return BMR;
}

double User::calculateDailyCalorie(const double& BMR) const{
    // calculate TDEE(calories our body burned in a day) based on the user's activity level
    double TDEE, dailyCalorie;
    switch (activityLevel) {
        case ActivityLevel::Sedentary:
            TDEE = BMR * 1.2;
            break;
        case ActivityLevel::LightlyActive:
            TDEE = BMR * 1.375;
            break;
        case ActivityLevel::ModeratelyActive:
            TDEE = BMR * 1.55;
            break;
        case ActivityLevel::VeryActive:
            TDEE = BMR * 1.725;
            break;
        default:
            break;
    }
    cout << "\n---> ";
    // calculate daily calorie intake based on user's goal
    switch(fitnessGoal) {
        // for weight loss,
        case FitnessGoal::LoseWeight:
            dailyCalorie = TDEE * 0.8;
            cout << "To be able to lose weight, your daily calorie intake should be ";
            break;
        // for weight gain
        case FitnessGoal::GainMuscle:
            dailyCalorie = TDEE * 1.2;
            cout << "To be able to gain weight, your daily calorie intake should be ";
            break;
        // for maintaining weight
        case FitnessGoal::MaintainWeight:
            dailyCalorie = TDEE;
            cout << "To be able to maintain weight, your daily calorie intake should be ";
            break;
        default:
            break;
    }
    // round daily calorie intake to the nearest whole number
    cout << round(dailyCalorie) << " calories.\n\n";
    return round(dailyCalorie);
}
