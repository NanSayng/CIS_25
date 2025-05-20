#include <gtest/gtest.h>
#include "validInput.hpp"

TEST(UserInputTest, ValidName) {
    EXPECT_TRUE(validName("John Doe"));
    EXPECT_TRUE(validName("Alice"));
}

TEST(UserInputTest, InvalidName) {
    EXPECT_FALSE(validName("John123"));
    EXPECT_FALSE(validName("Anna-Marie"));
    EXPECT_FALSE(validName("@lice"));
}

TEST(UserInputTest, ValidGender) {
    EXPECT_TRUE(validGender("M"));
    EXPECT_TRUE(validGender("f"));
}

TEST(UserInputTest, InvalidGender) {
    EXPECT_FALSE(validGender("Male"));
    EXPECT_FALSE(validGender("x"));
    EXPECT_FALSE(validGender("1"));
}

TEST(UserInputTest, ValidCalories) {
    EXPECT_TRUE(validCalories("0"));
    EXPECT_TRUE(validCalories("123"));
    EXPECT_TRUE(validCalories("45.67"));
}

TEST(UserInputTest, InvalidCalories) {
    EXPECT_FALSE(validCalories("-50"));
    EXPECT_FALSE(validCalories("abc"));
    EXPECT_FALSE(validCalories("12.34.56"));
}

TEST(UserInputTest, ValidHeight) {
    EXPECT_TRUE(validHeight("160"));
    EXPECT_TRUE(validHeight("5.7"));
}

TEST(UserInputTest, InvalidHeight) {
    EXPECT_FALSE(validHeight("-170"));
    EXPECT_FALSE(validHeight("six"));
    EXPECT_FALSE(validHeight("1.2.3"));
}

TEST(UserInputTest, ValidWeight) {
    EXPECT_TRUE(validWeight("70"));
    EXPECT_TRUE(validWeight("55.5"));
}

TEST(UserInputTest, InvalidWeight) {
    EXPECT_FALSE(validWeight("-60"));
    EXPECT_FALSE(validWeight("heavy"));
    EXPECT_FALSE(validWeight("60kg"));
}

TEST(UserInputTest, ValidMenuOption) {
    EXPECT_TRUE(validMenuOption("1"));
    EXPECT_TRUE(validMenuOption("8"));
}

TEST(UserInputTest, InvalidMenuOption) {
    EXPECT_FALSE(validMenuOption("0"));
    EXPECT_FALSE(validMenuOption("9"));
    EXPECT_FALSE(validMenuOption("a"));
}

TEST(UserInputTest, ValidYesOrNo) {
    EXPECT_TRUE(validYesOrNo("Y"));
    EXPECT_TRUE(validYesOrNo("n"));
}

TEST(UserInputTest, InvalidYesOrNo) {
    EXPECT_FALSE(validYesOrNo("yes"));
    EXPECT_FALSE(validYesOrNo("no"));
    EXPECT_FALSE(validYesOrNo("maybe"));
}
