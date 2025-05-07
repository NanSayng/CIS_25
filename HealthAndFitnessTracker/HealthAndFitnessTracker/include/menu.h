#pragma once
#include "user.h"
#include "inputValidation.h"
#include "getUserInfo.h"
#include <iostream>
#include <iomanip>

// display main menu options
void displayMainMenu();
// to show user's progress and their calories status based on their logged meal, workouts and daily calories goal
void viewProgress(User& user);
// to exit the program
void exitProgram(User& user);
