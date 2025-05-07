#include "../include/user.h"

// save user info datas
void getUserInfo(User& user){
    user.name = getValidName();
    user.age = getValidAge();
    user.isMale = getValidGender();
    user.height = getValidHeight();
    user.currWeight = getValidCurrWeight();
    user.goalWeight = getValidGoalWeight();
    user.goal = getValidGoal();
    user.activeLevel = getValidActiveLevel();
    user.dailyCalorieIntake = calculateDailyCalorie(user, user.activeLevel);
}

void getMenuOption(User& user){
    string input;
    int choice;
    // allowed only 1-8 number
    regex reg(R"(^[1-8]$)");
    while(true){
        cout << "Enter your choice [1-8]: ";
        cin >> input;
        // check if choice is invalid or empty
        if(input.empty() || !regex_match(input,reg)){
            cout << "Invalid choice.\n";
        }else{
            break;
        }
    }
    choice = stoi(input);
    // for each options call the corresponding function
    switch (choice) {
        case 1:
            addMeal(user);
            break;
        case 2:
            addWorkout(user);
            break;
        case 3:
            trackMeals(user);
            break;
        case 4:
            trackWorkouts(user);
            break;
        case 5:
            removeMeals(user);
            break;
        case 6:
            removeWorkouts(user);
            break;
        case 7:
            viewProgress(user);
            break;
        case 8:
            exitProgram(user);
            break;
        default:
            break;
    }
}

int getValidActiveLevel(){
    string input;
    int level;
    // allowed only 1 to 4 numbers
    regex reg(R"(^[1-4]$)");
    cout << "\nHow active are you?\n";
    cout << "1.\tSedentary (little to no exercise)\n";
    cout << "2.\tLightly Active (1-3 days exercise per week)\n";
    cout << "3.\tModerately Active (3-5 days exercise per week)\n";
    cout << "4.\tVery Active (6-7 days exercise per week\n";
    while(true){
        cout << "Enter your active level [1-4]: ";
        cin >> input;
        // check if user choice is valid
        if(input.empty() || !regex_match(input,reg)){
            cout << "Invalid choice.\n";
        }else
            break;
    }
    // converting from string to int
    level = stoi(input);
    return level;
}

int getValidAge(){
    string input;
    int age;
    while(true){
        cout << "Enter your age: ";
        getline(cin,input);
        // check if the age input is just number or invalid or zero
        if(input.empty() || !validateInt(input) || input == "0"){
            cout << "Invalid age.\n";
        }else
            break;
    }
    // converting from string to int
    age = stoi(input);
    return age;
}

double getValidCurrWeight(){
    string input;
    double currWeight;
    while(true){
        cout << "Enter your current weight in kg: ";
        cin >> input;
        // check if user input is valid
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid weight.\n";
        }else
            break;
    }
    // converting from string to double
    currWeight = stod(input);
    return currWeight;
}

bool getValidGender(){
    bool isMale = false;
    string input;
    regex validGender(R"(^[mMfF]$)");
    while(true){
        cout << "Enter your gender 'm/M' for Male, 'f/F' for Female: ";
        cin >> input;
        // check if the input is empty or invalid
        if(input.empty() || !regex_match(input,validGender)){
            cout << "Invalid gender.\n";
        } else
            break;
    }
    if(input == "M" || input == "m"){ // if male, assigned isMale = true or else assigned false for female
        isMale = true;
    }
    return isMale;
}

int getValidGoal(){
    string input;
    int goal;
    // to make sure the string only contain 1 to 3
    regex reg(R"(^[1-3]$)");
    cout << "\nWhat is your fitness goal?\n";
    cout << "1. Lose Weight\n";
    cout << "2. Gain Muscle\n";
    cout << "3. Maintain Weight\n";
    while(true){
        cout << "Enter your choice (1-3): ";
        cin >> input;
        // check if user's goal choice is valid
        if(input.empty() || !regex_match(input,reg))
        {
            cout << "Invalid choice.\n";
        }else
            break;
    }
    // converting from string to int
    goal = stoi(input);
    return goal;
}

double getValidGoalWeight(){
    string input;
    double goalWeight;
    // to check if input is only int or double without letters or special char
    while(true){
        cout << "Enter your goal weight in kg: ";
        cin >> input;
        // check if user input is valid or empty
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid weight.\n";
        }else
            break;
    }
    // converting from string to double
    goalWeight = stod(input);
    return goalWeight;
}

double getValidHeight(){
    string input;
    double height;
    while(true){
        cout << "Enter your height in cm: ";
        cin >> input;
        // check if input is invalid or empty
        if(input.empty() || !validateDouble(input)){
            cout << "Invalid height.\n";
        }else{
            break;
        }
    }
    // convert from string to int
    height = stod(input);
    return height;
}

string getValidName(){
    string name;
    while(true){
        cout << "Enter your name: ";
        getline(cin, name);
        // check if it's invalid name or empty
        if(name.empty() || !validateString(name)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    return name;
}
