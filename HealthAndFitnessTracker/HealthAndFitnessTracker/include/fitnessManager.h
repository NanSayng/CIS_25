#pragma once
#include <iostream>
#include <stdexcept> // for invalid argument
#include "user.h"
#include "inputValidation.h"
#include "menu.h"

// to add workouts to the array
void addWorkout(User& user);
// to remove workout and calorie from the array
void removeWorkouts(User& user);
// to show what workouts and calories user had added
void trackWorkouts(User& user);
// calculate BMR based on the user's gender
double calculateBMR(User& user);
// calculate TDEE based on the user's activity level
double calculateTDEE(double BMR, int activityLevel);
// calculate calories based on user's goal
double calculateDailyCalorie(User& user);

