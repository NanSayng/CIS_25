#include "calculateBMR.hpp"
#include "getUserInfo.hpp"

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
