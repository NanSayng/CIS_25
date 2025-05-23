//
//  fitnessTracker.cpp
//  Fitness_Tracker(OOP ver)
//
//  Created by Nan Sayng on 5/15/25.
//
#include "../include/fitnessTracker.h"
using namespace std;

void FitnessTracker::displayMenu(){
    cout << setfill(' ') << setw(15) << "Main Menu" << endl;
        cout << setfill('-') << setw(21) << '-' << endl;
        cout << "1.\tAdd Meal\n";
        cout << "2.\tAdd Workout\n";
        cout << "3.\tTrack Meals\n";
        cout << "4.\tTrack Workouts\n";
        cout << "5.\tRemove Meals\n";
        cout << "6.\tRemove Workouts\n";
        cout << "7.\tView Progress\n";
        cout << "8.\tExit\n";
        cout << setfill('-') << setw(21) << '-' << endl;
}

int FitnessTracker::getMenuOption(){
    string input;
    int choice;
    while(true){
        cout << "Enter your choice [1-8]: ";
        cin >> input;
        try {
            if(input.empty() || !validMenuOption(input)){
                throw invalid_argument("Invalid menu option.");
            }
            choice = stoi(input);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter a number between 1 and 8.\n";
        }
    }
    return choice;
}

void FitnessTracker::addMeal(){
    string name, caloriesStr;
    while(true){
        cout << "\nEnter meal name: ";
        getline(cin, name);
        if(name.empty() || !validName(name)){
            cout << "Invalid meal name.\n";
        }else{
            break;
        }
    }
    double calories;
    while(true){
        cout << "Enter calories: ";
        cin >> caloriesStr;
        try{
            calories = stod(caloriesStr);
            if(calories <= 0){
                cout << "Invalid calories.\n";
            }else{
                break;
            }
        }catch(const invalid_argument& e){
            cout << "Invalid calories.\n";
        }catch(const out_of_range& e){
            cout << "Number too large. Please enter a smaller value.\n";
        }
    }
    Meal newMeal(name, calories);
    meals.push_back(newMeal);
    cout << "\nMeal added: " << name << " (" << calories << " kcal)\n";
    string input;
    while(true){
        cout << "Do you want to add another meal? (y/n): ";
        cin >> input;
        if(input.empty() || !validYesOrNo(input)){
            cout << "Invalid input.\n";
        }else{
            break;
        }
    }
    if(input == "y" || input == "Y"){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        addMeal();
    }
    cout << endl;
}

void FitnessTracker::addWorkout(){
    string name, caloriesStr;
    while(true){
        cout << "Enter workout name: ";
        getline(cin, name);
        if(name.empty() || !validName(name)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    while(true){
        cout << "Enter calories: ";
        cin >> caloriesStr;
        if(caloriesStr.empty() || !validCalories(caloriesStr)){
            cout << "Invalid calories.\n";
        }else{
            break;
        }
    }
    double calories = stod(caloriesStr);
    Workout newWorkout(name, calories);
    workouts.push_back(newWorkout);
    cout << "\nWorkout added: " << name << " (" << calories << " kcal)\n";
    string input;
    while(true){
        cout << "Do you want to add another workout? (y/n): ";
        cin >> input;
        if(input.empty() || !validYesOrNo(input)){
            cout << "Invalid input.\n";
        }else{
            break;
        }
    }
    if(input == "y" || input == "Y"){
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        addWorkout();
    }
}

void FitnessTracker::trackMeals(){
    if(!meals.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Meals\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(meals); i++){
            cout << i + 1 << ".\t" << meals[i].getName() << " (" << meals[i].getCalories() << " kcal)\n";
        }
        string input1;
            while(true){
                cout << "\nWould you like to add meals? (y/n): ";
                cin >> input1;
                if(input1.empty() || !validYesOrNo(input1)){
                    cout << "Invalid input.\n";
                }else{
                    break;
                }
            }
            if(input1 == "y" || input1 == "Y"){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addMeal();
            }
        }else{
        cout << "\nYou haven't add any meals yet.\n";
        string input2; // for y and n
        while(true){
            cout << "Would you like to add meals? (y/n): ";
            cin >> input2;
            if(input2.empty() || !validYesOrNo(input2)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input2 == "y" || input2 == "Y"){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            addMeal();
        }
    }
    cout << endl;
}

void FitnessTracker::trackWorkouts(){
    if(!workouts.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(workouts); i++){
            cout << i + 1 << ".\t" << workouts[i].getName() << " (" << workouts[i].getCalories() << " kcal)\n";
        }
        string input1;
            while(true){
                cout << "\nWould you like to add workouts? (y/n): ";
                cin >> input1;
                if(input1.empty() || !validYesOrNo(input1)){
                    cout << "Invalid input.\n";
                }else{
                    break;
                }
            }
            if(input1 == "y" || input1 == "Y"){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addWorkout();
            }
        }else{
        cout << "\nYou haven't add any workouts yet.\n";
        string input2; // for y and n
        while(true){
            cout << "Would you like to add workouts? (y/n): ";
            cin >> input2;
            if(input2.empty() || !validYesOrNo(input2)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input2 == "y" || input2 == "Y"){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            addWorkout();
        }
    }
    cout << endl;
}

void FitnessTracker::removeMeal(){
    int mealIndex;
    if(!meals.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Meals\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(meals); i++){
            cout << i + 1 << ".\t" << meals[i].getName() << " (" << meals[i].getCalories() << " kcal)\n";
        }
        int input1;
        while(true){
            cout << "\nEnter the meal number to remove: ";
            cin >> input1;
            if(cin.fail() || input1 <= 0){
                cout << "Invalid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if(input1 > size(meals)){
                cout << "There's only " << size(meals) << " meals addded.\n";
            }else{
                break;
            }
        }
        mealIndex = input1 - 1;
        string removedMeal = meals[mealIndex].getName();
        meals.erase(meals.begin() + mealIndex);
        cout << endl;
        cout << removedMeal << " has been removed.\n\n";
        if(meals.empty()){
            cout << "There's not meal left.\n";
            string input2;
            while(true){
                cout << "Would you like to add a meal? (y/n): ";
                cin.clear();
                cin >> input2;
                if(input2.empty() || !validYesOrNo(input2)){
                    cout << "Invalid input.\n";
                }else{
                    break;
                }
            }
            if(input2 == "y" || input2 == "Y"){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addMeal();
            }
        }
    }else{
        cout << "There's no meal to be removed.\n";
        string input3;
        while(true){
            cout << "Would you like to add a meal? (y/n): ";
            cin >> input3;
            if(input3.empty() || !validYesOrNo(input3)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input3 == "Y" || input3 == "y"){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            addMeal();
        }
    }
}

void FitnessTracker::removeWorkout(){
    int workoutIndex;
    if(!workouts.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(workouts); i++){
            cout << i + 1 << ".\t" << workouts[i].getName() << " (" << workouts[i].getCalories() << " kcal)\n";
        }
        int input1;
        while(true){
            cout << "\nEnter the workout number to remove: ";
            cin >> input1;
            if(cin.fail() || input1 <= 0){
                cout << "Invalid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else if(input1 > size(workouts)){
                cout << "There's only " << size(workouts) << " meals addded.\n";
            }else{
                break;
            }
        }
        workoutIndex = input1 - 1;
        string removedWorkout = workouts[workoutIndex].getName();
        workouts.erase(workouts.begin() + workoutIndex);
        cout << endl;
        cout << removedWorkout << " has been removed.\n\n";
        if(workouts.empty()){
            cout << "There's not workout left.\n";
            string input2;
            while(true){
                cout << "Would you like to add a workout? (y/n): ";
                cin.clear();
                cin >> input2;
                if(input2.empty() || !validYesOrNo(input2)){
                    cout << "Invalid input.\n";
                }else{
                    break;
                }
            }
            if(input2 == "y" || input2 == "Y"){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addWorkout();
            }
        }
    }else{
        cout << "There's no workout to be removed.\n";
        string input3;
        while(true){
            cout << "Would you like to add a workout? (y/n): ";
            cin >> input3;
            if(input3.empty() || !validYesOrNo(input3)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input3 == "Y" || input3 == "y"){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            addWorkout();
        }
    }
}

void FitnessTracker::viewProgress(const double& dailyCal){
    double totalCalConsumed = 0,
    totalCalBurned = 0,
    netCalories;
    // calculate the total calories consumed
    for(const auto& meal: meals){
        totalCalConsumed += meal.getCalories();
    }
    // calculate the total calories burned
    for(const auto& workout: workouts){
        totalCalBurned += workout.getCalories();
    }
    // calculate the net calories (consumed - burned)
    netCalories = totalCalConsumed - totalCalBurned;
    cout << endl;
    // progress title
    cout << setfill('-') << setw(15) << "Progress" << setfill('-') << setw(7) << '-' << endl;
    // if no calories added or burned, ask user to add
    if(totalCalConsumed == 0 && totalCalBurned == 0){
        cout << "You haven't logged any meals or workouts yet.\n";
        cout << "Start adding meals and workouts to track your progress!\n\n";
    }else{
        // if there's calories added, show the progress
        cout << "\nTotal calories consumed: " << round(totalCalConsumed) << " kcal\n";
        cout << "Total calories burned: " << totalCalBurned << " kcal\n";
        // change to positive sign for display
        cout << "Net calories: " << abs(netCalories) << " kcal\n";
        cout << "Daily calorie intake goal: " << dailyCal << " kcal\n";
        // display calorie status based on net calories and daily calorie intake goal
        if(netCalories < dailyCal){
            cout << "You are in a calorie deficit. You are consuming fewer calories than your goal, which may lead to weight loss.\n\n";
        }else if(netCalories > dailyCal){
            cout << "You are in a calorie surplus. You are exceeding your daily calories intake, which may lead to weight gain.\n\n";
        }else{
            cout << "Your calories are balanced. You're maintaining your current weight.\n";
        }
    }
}

void FitnessTracker::exitProgram(){
    string input;
    while(true){
        cout << "\nAre you sure you want to exit? (y/n): ";
        cin >> input;
        if(input.empty() || !validYesOrNo(input)){
            cout << "Invalid input.\n";
        }else{
            break;
        }
    }
    if(input == "y" || input == "Y"){
        cout << "\nI hope you have a wonderful day. Bye!\n";
        exit(0);
    }
    cout << endl;
}

void FitnessTracker::runProgram(){
    user.getUserInfo();
    double dailyCal = user.calculateDailyCalorie(user.calculateBMR());
    int choice;
    do{
        displayMenu();
        choice = getMenuOption();
        switch(choice){
            case 1:
                addMeal();
                break;
            case 2:
                addWorkout();
                break;
            case 3:
                trackMeals();
                break;
            case 4:
                trackWorkouts();
                break;
            case 5:
                removeMeal();
                break;
            case 6:
                removeWorkout();
                break;
            case 7:
                viewProgress(dailyCal);
                break;
            case 8:
                exitProgram();
                break;
        }
    }while(true);
}





