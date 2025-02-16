#include "getUserInfo.hpp"
#include "getValidName.hpp"
#include "getValidAge.hpp"
#include "getValidHeight.hpp"
#include "getValidCurrWeight.hpp"
#include "getValidGoalWeight.hpp"
#include "getValidGoal.hpp"
#include "getValidGender.hpp"
#include "getValidActiveLevel.hpp"
#include "calculateDailyCalorie.hpp"
#include <string>
#include <vector>
using namespace std;

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
    user.dailyCalorieIntake = calculateDailyCalorie(user);
}
