#pragma once
#include <iostream>
#include <vector>
#include <regex>
#include "fitnessManager.h"
#include "mealManager.h"
using namespace std;

// to store user's meals and their calories
struct Meals{
    vector<string> meal;
    vector<double> calories;
};
// to stroe user's workouts and their calories
struct Workouts{
    vector<string> workout;
    vector<double> calories;
};
// to store user's information needed for the whole program
struct User{
    string name;
    int age;
    bool isMale;
    double height;
    double currWeight;
    double goalWeight;
    int goal;
    int activeLevel;
    double dailyCalorieIntake;
    Meals meals;
    Workouts workouts;
};

void getUserInfo(User& user);

// get user's menu option, and run the corresponding based on option
void getMenuOption(User& user);
// to get user's activity level
int getValidActiveLevel();
// get user's age
int getValidAge();
// get user's current weight
double getValidCurrWeight();
// get user's gender
bool getValidGender();
// get user's fitness goal
int getValidGoal();
// get user's goal weight
double getValidGoalWeight();
// ask user's height
double getValidHeight();
// get user's name
string getValidName();
