#pragma once
#include <string>
#include <vector>
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

