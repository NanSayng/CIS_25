#include "calculateDailyCalorie.hpp"
#include "getUserInfo.hpp"
#include "calculateBMR.hpp"
#include <iostream>
using namespace std;

double calculateDailyCalorie(User& user){
    // calculate TDEE(calories our body burned in a day) based on the user's activity level
    double TDEE, dailyCalorie;
    double BMR = calculateBMR(user);
    switch (user.activeLevel) {
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
            break;
    }
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
