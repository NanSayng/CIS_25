#include <gtest/gtest.h>
#include <fstream>
#include <string>
#include <map>
#include <unordered_map>
#include "../include/passenger.hpp"
#include "../include/fileIO.hpp"
#include "../include/seat.hpp"
using namespace std;

TEST(ReadingFileTest, LoadSinglePassenger){
    // create unordered_map for testing
    unordered_map<string, unique_ptr<Passenger>> savedPassengers;
    unordered_map<string, unique_ptr<Passenger>> loadedPassengers;
    // create test passenger
    Passenger testPassenger("James", 22, "5103055789", "A123456", SeatClass::First, "1A");
    savedPassengers[testPassenger.passportNumber] = make_unique<Passenger>(testPassenger);
    // write the test passenger to binary test file
    string testFile = "test_passengers.dat";
    fstream file(testFile, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the passengers file.\n";
        return;
    }
    // write to test file
    for(const auto& passengerPair : savedPassengers){
        file.write(reinterpret_cast<char*>(passengerPair.second.get()), sizeof(Passenger));
    }
    file.close();

    loadFromPassengersFile(testFile, loadedPassengers);
    // check the result
    ASSERT_EQ(loadedPassengers.size(), 1);
    auto& p = loadedPassengers["A123456"];
    
    EXPECT_STREQ(p->name, "James");
    EXPECT_EQ(p->age, 22);
    EXPECT_STREQ(p->contact, "5103055789");
    EXPECT_STREQ(p->passportNumber, "A123456");
    EXPECT_EQ(p->seatClass, SeatClass::First);
    EXPECT_STREQ(p->seatNumber, "1A");
}





