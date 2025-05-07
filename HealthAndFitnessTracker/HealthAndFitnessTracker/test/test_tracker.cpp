#include <gtest/gtest.h>
#include "../include/fitnessManager.h"

// testing a function to calculate BMR
TEST(BMRTest, MaleBMR){
    User testUser;
    testUser.isMale = true;
    testUser.currWeight = 70.0;
    testUser.height = 175.0;
    testUser.age = 25;
    // calculate the true result for male
    double expectedBMR = (10 * testUser.currWeight) + (6.25 * testUser.height) - (5 * testUser.age) + 5;
    EXPECT_EQ(calculateBMR(testUser), expectedBMR);
}

TEST(BMRTest, FemaleBMR){
    User testUser;
    testUser.isMale = false;
    testUser.currWeight = 60.0;
    testUser.height = 160.0;
    testUser.age = 30;
    double expectedBMR = (10 * testUser.currWeight) + (6.25 * testUser.height) - (5 * testUser.age) - 161;
    // calculte the true result for female
    EXPECT_EQ(calculateBMR(testUser), expectedBMR);
}

