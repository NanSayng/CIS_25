#include "../include/fitnessManager.h"
using namespace std;

void addWorkout(User& user){
    string workoutName, calories, input;
    // get valid meal name
    do{
        while(true){
            cout << "Enter workout name: ";
            cin.ignore();
            getline(cin,workoutName);
            // check if meal name input is valid
            if(workoutName.empty() || !validateString(workoutName)){
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
        user.workouts.workout.push_back(workoutName);
        user.workouts.calories.push_back(stod(calories));
        cout << "Workout added: " << workoutName << " (" << calories << " calories)\n";
        // ask user if they want to add another meal
        while(true){
            cout << "Do you want to add another workout? (y/n): ";
            cin >> input;
            // check if the answer is valid
            if(input.empty() || !validateChar(input)){
                cout << "Invalid answer.\n";
            }else
                break;
        }
    } while(input == "Y" || input == "y"); // if say yes continue adding meals
    // if no diplay main menu again
    displayMainMenu();
    getMenuOption(user);
}

void removeWorkouts(User& user){
    int index;
    // if there's not workout to be removed yet, ask user if they want to add one
    if(user.workouts.workout.empty()){
        cout << "There's no workout to be removed.\n";
        string input1;
        while(true){
            cout << "Would you like to add a workout? (y/n): ";
            cin >> input1;
            // check if user input is valid y or n
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        if(input1 == "y" || input1 == "Y"){
            addWorkout(user);
        }else{
            displayMainMenu();
            getMenuOption(user);
        }
    }else{
        // display added workouts
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.workouts.workout); i++){
            cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
        }
        string input2;
        while(true){
            // ask user which workout they want to remove
            cout << "\nEnter the workout number to remove: ";
            cin >> input2;
            // check if the meal number is valid
            if(input2.empty() || !validateInt(input2) || input2 == "0"){
                cout << "Invalid input.\n";
            }else if(stoi(input2) > size(user.workouts.workout)){
                cout << "There's only " << size(user.workouts.workout) << "workouts added.\n";
            }else{
                break;
            }
        }
        // get the index of workout that user want to remove
        index = stoi(input2) - 1;
        string removedWorkout = user.workouts.workout[index];
        user.workouts.workout.erase(user.workouts.workout.begin() + index);
        user.workouts.calories.erase(user.workouts.calories.begin() + index);
        cout << endl;
        cout << removedWorkout << " has been removed.\n";
        // if workouts become empty, ask user if they want to add workouts
        if(user.workouts.workout.empty()){
            cout << "There's no workout left.\n";
            string input3;
            while(true){
                cout << "Would you like to add a workout? (y/n): ";
                cin >> input3;
                // check if user input is valid y or n
                if(input3.empty() || !validateChar(input3)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input3 == "y" || input3 == "Y"){
                addWorkout(user);
            }else{
                displayMainMenu();
                getMenuOption(user);
            }
        }else{
            // show updated workouts after removing
            cout << "\n" << setfill(' ') << setw(20) << "Updated Workouts\n";
            cout << setfill('-') << setw(30) << '-' << endl;
            for(int i = 0; i < size(user.workouts.workout); i++){
                cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
            }
            string input4;
            while(true){
                // ask if they want to remove another one
                cout << "Would you like to remove another workout? (y/n): ";
                cin >> input4;
                // check if user input is valid y or n
                if(input4.empty() || !validateChar(input4)){
                    cout << "Invalid input.\n";
                }else
                    break;
            }
            if(input4 == "Y" || input4 == "y"){
                removeWorkouts(user);
            }else{
                displayMainMenu();
                getMenuOption(user);
            }
        }
    }
}

void trackWorkouts(User& user){
    // string inputs used for user to get input value
    string input1, input2;
    // if user have added workouts, display the added workouts
    if(!user.workouts.workout.empty()){
        cout << "\n" << setfill(' ') << setw(20) << "Added Workouts\n";
        cout << setfill('-') << setw(30) << '-' << endl;
        for(int i = 0; i < size(user.workouts.workout); i++){
            cout << i + 1 << ".\t" << user.workouts.workout[i] << " (" << user.workouts.calories[i] << " kcal)\n";
        }
        while(true){
            // ask if they want to add another one
            cout << "\nWould you like to add another workout? (y/n): ";
            cin >> input1;
            // check if input is valid
            if(input1.empty() || !validateChar(input1)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        // if yes, call addworkout function
        if(input1 == "Y" || input1 == "y"){
            addWorkout(user);
        }else
            displayMainMenu();
        getMenuOption(user);
    }else{
        // if there's no workouts to display, ask user if they want to add
        cout << "You haven't add any workouts yet.\n";
        while(true){
            cout << "Would you like to add workout? (y/n): ";
            cin >> input2;
            // check if input is valid
            if(input2.empty() || !validateChar(input2)){
                cout << "Invalid input.\n";
            }else
                break;
        }
        // if yes call addworkout function
        if(input2 == "Y" || input2 == "y"){
            addWorkout(user);
        }else
            displayMainMenu();
        getMenuOption(user);
    }
}

// to calculate BMR (calories our body needed to function at rest which is different for men and women
double calculateBMR(User& user){
    double BMR;
    if(user.isMale){
        // for male
        BMR = (10 * user.currWeight) + (6.25 * user.height) - (5 * user.age) + 5;
    }else{
        // for female
        BMR = (10 * user.currWeight) + (6.25 * user.height) - (5 * user.age) - 161;
    }
    return BMR;
}

double calculateTDEE(double BMR, int activityLevel){
    double TDEE = -1;
    switch (activityLevel) {
        case 1:
            TDEE = BMR * 1.2;
            break;
        case 2:
            TDEE = BMR * 1.375;
            break;
        case 3:
            TDEE = BMR * 1.55;
            break;
        case 4:
            TDEE = BMR * 1.725;
            break;
        default:
            throw invalid_argument("Invalid activity level. Must be 1 to 4.");
            break;
    }
    return TDEE;
}

double calculateDailyCalorie(User& user){
    // calculate TDEE(calories our body burned in a day) based on the user's activity level
    double TDEE, dailyCalorie;
    double BMR = calculateBMR(user);
    TDEE = calculateTDEE(BMR, user.activeLevel);
    cout << "\n---> ";
    // calculate daily calorie intake based on user's goal
    switch (user.goal) {
        // for weight loss,
        case 1:
            dailyCalorie = TDEE * 0.8;
            cout << "To be able to lose weight, your daily calorie intake should be ";
            break;
        // for weight gain
        case 2:
            dailyCalorie = TDEE * 1.2;
            cout << "To be able to gain weight, your daily calorie intake should be ";
            break;
        // for maintaining weight
        case 3:
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

