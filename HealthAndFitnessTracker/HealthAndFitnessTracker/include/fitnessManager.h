#pragma once
#include <iostream>
#include <iomanip>
#include "user.h"
#include "input_validation.h"
#include "menu.h"
struct User; // forward declaration

// to add workouts to the array
void addWorkout(User& user);
// to remove workout and calorie from the array
void removeWorkouts(User& user);
// to show what workouts and calories user had added
void trackWorkouts(User& user);
// calculate BMR based on the user's gender
double calculateBMR(User& user);
// calculate calories based on user's activity level and goal
double calculateDailyCalorie(User& user, int activeLevel);
