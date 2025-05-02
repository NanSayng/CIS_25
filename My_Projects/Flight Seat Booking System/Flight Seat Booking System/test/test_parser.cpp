#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include "../include/passenger.hpp"
#include "../include/fileIO.hpp"
using namespace std;

TEST(ReadingFileTest, LoadSinglePassenger){
    // create test passenger
    Passenger testPassenger("James", 22, "5103055789", "A123456", SeatClass::First, "1A");
    // write the test passenger to binary test file
    string testFile = "test_passengers.dat";
    fstream file(testFile, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    // write to test file
    file.write(reinterpret_cast<char*>(&testPassenger), sizeof(Passenger));
    file.close();
    // create unordered_map for testing
    unordered_map<string, unique_ptr<Passenger>> loadedPassengers;
    loadFromPassengersFile(testFile, loadedPassengers);
    // check the result
    for(auto& test : loadedPassengers){
        EXPECT_EQ(test.second->name, "James");
        EXPECT_EQ(test.second->age, 22);
        EXPECT_EQ(test.second->contact, "5103055789");
        EXPECT_EQ(test.second->passportNumber, "A123456");
        EXPECT_EQ(test.second->SeatClass, SeatClass::First);
        EXPECT_EQ(test.second->seatNum, "1A");
    }
}




