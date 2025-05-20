// These tests were 
#include <gtest/gtest.h>
#include "../include/inputValidation.h"
#include "../include/user.h"
#include "../include/fitnessManager.h"

// ------------------ Validation Tests ------------------

TEST(ValidationTests, ValidateChar) {
    EXPECT_TRUE(validateChar("y"));
    EXPECT_TRUE(validateChar("n"));
    EXPECT_FALSE(validateChar("yes"));
    EXPECT_FALSE(validateChar("1"));
    EXPECT_FALSE(validateChar(""));
}

TEST(ValidationTests, ValidateInt) {
    EXPECT_TRUE(validateInt("25"));
    EXPECT_TRUE(validateInt("0"));
    EXPECT_FALSE(validateInt("-5"));
    EXPECT_FALSE(validateInt("25a"));
    EXPECT_FALSE(validateInt("12 34"));
}

TEST(ValidationTests, ValidateDouble) {
    EXPECT_TRUE(validateDouble("123.45"));
    EXPECT_TRUE(validateDouble("0"));
    EXPECT_FALSE(validateDouble("012.3")); // leading zero
    EXPECT_FALSE(validateDouble("abc"));
    EXPECT_FALSE(validateDouble("-23.1"));
}

TEST(ValidationTests, ValidateString) {
    EXPECT_TRUE(validateString("John"));
    EXPECT_TRUE(validateString("Mary Jane"));
    EXPECT_FALSE(validateString("John123"));
    EXPECT_FALSE(validateString("!@#"));
    EXPECT_FALSE(validateString(""));
}

// ------------------ Meals & Workouts ------------------

TEST(UserDataTests, AddMealsCorrectly) {
    User user;
    user.meals.meal.push_back("Lunch");
    user.meals.calories.push_back(600.0);

    EXPECT_EQ(user.meals.meal.size(), 1);
    EXPECT_EQ(user.meals.meal[0], "Lunch");
    EXPECT_DOUBLE_EQ(user.meals.calories[0], 600.0);
}

TEST(UserDataTests, AddWorkoutsCorrectly) {
    User user;
    user.workouts.workout.push_back("Running");
    user.workouts.calories.push_back(300.0);

    EXPECT_EQ(user.workouts.workout.size(), 1);
    EXPECT_EQ(user.workouts.workout[0], "Running");
    EXPECT_DOUBLE_EQ(user.workouts.calories[0], 300.0);
}

TEST(UserDataTests, RemoveMeals) {
    User user;
    user.meals.meal = { "Breakfast", "Lunch", "Dinner" };
    user.meals.calories = { 300, 500, 700 };

    user.meals.meal.erase(user.meals.meal.begin() + 1); // remove Lunch
    user.meals.calories.erase(user.meals.calories.begin() + 1);

    EXPECT_EQ(user.meals.meal.size(), 2);
    EXPECT_EQ(user.meals.meal[1], "Dinner");
    EXPECT_DOUBLE_EQ(user.meals.calories[1], 700);
}

// ------------------ Fitness Calculations ------------------

TEST(CalculationTests, CalculateBMR_Male) {
    User user = { "John", 25, true, 180.0, 75.0, 70.0, 1, 2 };
    double bmr = calculateBMR(user);
    EXPECT_NEAR(bmr, 1766.0, 20.0);
}

TEST(CalculationTests, CalculateBMR_Female) {
    User user = { "Jane", 30, false, 165.0, 65.0, 60.0, 1, 2 };
    double bmr = calculateBMR(user);
    EXPECT_NEAR(bmr, 1394.0, 20.0);
}

TEST(CalculationTests, CalculateTDEE_Sedentary) {
    double bmr = 1500.0;
    double tdee = calculateTDEE(bmr, 1); // sedentary
    EXPECT_DOUBLE_EQ(tdee, 1500.0 * 1.2);
}

TEST(CalculationTests, CalculateDailyCalorie_LoseWeight) {
    User user = { "Alex", 40, true, 170.0, 85.0, 75.0, 1, 3 }; // lose weight
    double daily = calculateDailyCalorie(user);
    EXPECT_GT(daily, 0);
}

TEST(CalculationTests, CalculateDailyCalorie_GainWeight) {
    User user = { "Max", 22, true, 180.0, 70.0, 80.0, 2, 4 }; // gain weight
    double daily = calculateDailyCalorie(user);
    EXPECT_GT(daily, 0);
}

// ------------------ Edge Case Handling ------------------

TEST(EdgeCases, EmptyNameValidation) {
    EXPECT_FALSE(validateString(""));
    EXPECT_FALSE(validateString("   "));
}

TEST(EdgeCases, NegativeWeightFails) {
    EXPECT_FALSE(validateDouble("-10"));
}

TEST(EdgeCases, SymbolsFailValidation) {
    EXPECT_FALSE(validateInt("$$$"));
    EXPECT_FALSE(validateString("Tom@123"));
    EXPECT_FALSE(validateChar("*"));
}

TEST(EdgeCases, MenuInputRange) {
    EXPECT_FALSE(validateInt("9")); // Assuming valid range is 1–8
    EXPECT_FALSE(validateInt("0"));
    EXPECT_FALSE(validateInt("abc"));
}

// ------------------ User Initialization ------------------

TEST(UserStruct, UserDefaults) {
    User u;
    EXPECT_EQ(u.name, "");
    EXPECT_EQ(u.age, 0);
    EXPECT_FALSE(u.isMale);
    EXPECT_DOUBLE_EQ(u.height, 0.0);
    EXPECT_DOUBLE_EQ(u.currWeight, 0.0);
    EXPECT_EQ(u.goal, 0);
    EXPECT_EQ(u.activeLevel, 0);
    EXPECT_TRUE(u.meals.meal.empty());
    EXPECT_TRUE(u.workouts.workout.empty());
}
