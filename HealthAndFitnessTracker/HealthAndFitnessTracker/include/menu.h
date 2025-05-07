#pragma once
#include "user.h"
#include "input_validation.h"
#include <iomanip>
using namespace std;

struct User; // forward declaration

// display main menu options
void displayMainMenu(User& user);
// to show user's progress and their calories status based on their logged meal, workouts and daily calories goal
void viewProgress(User& user);
// to exit the program
void exitProgram(User& user);
