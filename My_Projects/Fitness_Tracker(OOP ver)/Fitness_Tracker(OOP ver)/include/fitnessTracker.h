//
//  fitnessTracker.h
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#pragma once
#include "user.h"
#include "entry.h"
#include "meal.h"
#include "workout.h"
#include <iostream>
#include <iomanip>
#include <cctype> // for converting to lower case

class FitnessTracker{
private:
    User user;
    vector<Meal> meals;
    vector<Workout> workouts;
public:
    FitnessTracker() {}; // default
    void displayMenu();
    int getMenuOption();
    void runProgram();
    
    // menu functions;
    void addMeal();
    void addWorkout();
    void trackMeals();
    void trackWorkouts();
    void removeMeal();
    void removeWorkout();
    void viewProgress(const double& dailyCal);
    void exitProgram();
};
