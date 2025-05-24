#include <gtest/gtest.h>
#include "../include/validateUserInputs.hpp"

TEST(ValidationTests, ValidName){
    EXPECT_TRUE(isValidName("Nan"));
    EXPECT_TRUE(isValidName("Nan Sayng"));
}

TEST(ValidationTests, InvalidName){
    EXPECT_FALSE(isValidName(""));
    EXPECT_FALSE(isValidName("Nan!&"));
}

TEST(ValidationTests, ValidContact){
    EXPECT_TRUE(isValidContact("5103055789"));
    EXPECT_TRUE(isValidContact("5104283488"));
}

TEST(ValidationTests, InvalidContact){
    EXPECT_FALSE(isValidContact("3235643234")); // doesn't start with 510
    EXPECT_FALSE(isValidContact("5103055")); // shorter than 10 digits
    EXPECT_FALSE(isValidContact("5103098434793")); // longer than 10 digits
    EXPECT_FALSE(isValidContact("5103@55789")); // contain character
}

TEST(ValidationTests, ValidPassportNum){
    EXPECT_TRUE(isValidPassNum("A123456"));
    EXPECT_TRUE(isValidPassNum("B228372"));
}

TEST(ValidationTests, InvalidPassportNum){
    EXPECT_FALSE(isValidPassNum("1234566")); // doens't start with alphabet
    EXPECT_FALSE(isValidPassNum("123jjk*")); // contain characters
    EXPECT_FALSE(isValidPassNum("A1234")); // doens't follow w 6 digits
}

TEST(ValidationTests, ValidSeatNum){
    EXPECT_TRUE(isValidSeatNum("5A"));
    EXPECT_TRUE(isValidSeatNum("3C"));
}

TEST(ValidationTests, InvalidSeatNum){
    EXPECT_FALSE(isValidSeatNum("D1")); // seat number not existed
    EXPECT_FALSE(isValidSeatNum("33"));
    EXPECT_FALSE(isValidSeatNum("jj"));
}

TEST(ValidationTests, ValidChar){
    EXPECT_TRUE(isValidChar("Y"));
    EXPECT_TRUE(isValidChar("y"));
    EXPECT_TRUE(isValidChar("N"));
    EXPECT_TRUE(isValidChar("n"));
}

TEST(ValidationTests, InvalidChar){
    EXPECT_FALSE(isValidChar("a"));
    EXPECT_FALSE(isValidChar("1"));
    EXPECT_FALSE(isValidChar("%"));
    EXPECT_FALSE(isValidChar(" "));
    EXPECT_FALSE(isValidChar("yes"));
    EXPECT_FALSE(isValidChar(""));
}

TEST(ValidationTests, ValidChoice) {
    EXPECT_TRUE(isValidChoice("1"));
    EXPECT_TRUE(isValidChoice("2"));
    EXPECT_TRUE(isValidChoice("3"));
    EXPECT_TRUE(isValidChoice("4"));
    EXPECT_TRUE(isValidChoice("5"));
}

TEST(ValidationTests, InvalidChoice) {
    EXPECT_FALSE(isValidChoice("0"));
    EXPECT_FALSE(isValidChoice("6"));
    EXPECT_FALSE(isValidChoice("10"));
    EXPECT_FALSE(isValidChoice("a"));
    EXPECT_FALSE(isValidChoice(""));
    EXPECT_FALSE(isValidChoice(" 2"));
    EXPECT_FALSE(isValidChoice("2 "));
    EXPECT_FALSE(isValidChoice("03"));
}










