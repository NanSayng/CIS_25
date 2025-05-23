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
        cout << "Error opening the test passengers file.\n";
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

TEST(ReadingFileTest, LoadSeatsFromFile){
    // create seatsTest.txt file to test
    string testFile = "test_seats.txt";
    fstream file(testFile, ios::out);
    if(!file.is_open()){
        cout << "Error opening the test seats file.\n";
        return;
    }
    file << "1A First 1\n";
    file << "2B Business 0\n";
    file << "4C Economy 0\n";
    file << "3B Business 1\n";
    file.close();
    map<string, shared_ptr<Seat>> loadedSeats;
    loadFromSeatsFile(testFile, loadedSeats);
    // check the result
    ASSERT_EQ(loadedSeats.size(), 4);
    // check seat 1
    auto& seat1 = loadedSeats["1A"];
    EXPECT_EQ(seat1->seatClass, SeatClass::First);
    EXPECT_EQ(seat1->seatNumber, "1A");
    EXPECT_TRUE(seat1->isBooked);
    // check seat 2
    auto& seat2 = loadedSeats["2B"];
    EXPECT_EQ(seat2->seatClass, SeatClass::Business);
    EXPECT_EQ(seat2->seatNumber, "2B");
    EXPECT_FALSE(seat2->isBooked);
    // check seat 3
    auto& seat3 = loadedSeats["4C"];
    EXPECT_EQ(seat3->seatClass, SeatClass::Economy);
    EXPECT_EQ(seat3->seatNumber, "4C");
    EXPECT_FALSE(seat3->isBooked);
    // check seat 4
    auto& seat4 = loadedSeats["3B"];
    EXPECT_EQ(seat4->seatClass, SeatClass::Business);
    EXPECT_EQ(seat4->seatNumber, "3B");
    EXPECT_TRUE(seat4->isBooked);
}

TEST(WritingFileTest, WriteSinglePassenger){
    // sample passegner to write for test
    unordered_map<string, unique_ptr<Passenger>> samplePassengers;
    Passenger testPassenger("Nan", 21, "5103055789", "B123456", SeatClass::First, "3A");
    samplePassengers["B123456"] = make_unique<Passenger>(testPassenger);
    // create sample passenger binary file to test
    string testFile = "testPassengers.dat";
    saveToPassengersFile(testFile, samplePassengers);
    // read and check if it writes correctly
    fstream file(testFile, ios::out | ios::binary);
    if(!file.is_open()){
        cout << "Error opening the test passenger file.\n";
        return;
    }
    Passenger readPassenger;
    while(file.read(reinterpret_cast<char*>(&readPassenger), sizeof(Passenger))){
        EXPECT_EQ(readPassenger.name, "Nan");
        EXPECT_EQ(readPassenger.age, 21);
        EXPECT_EQ(readPassenger.contact, "5103055789");
        EXPECT_EQ(readPassenger.passportNumber, "B123456");
        EXPECT_EQ(readPassenger.seatClass, SeatClass::First);
        EXPECT_EQ(readPassenger.seatNumber, "3A");
    }
    file.close();
}

TEST(WritingFileTest, WriteSeatsFile){
    // sample seats to write for test
    map<string, shared_ptr<Seat>> sampleSeats;
    Seat testSeat(SeatClass::First, "1A", true);
    sampleSeats["1A"] = make_shared<Seat>(testSeat);
    // create sample seat txt file to test
    string testFile = "testSeats.txt";
    fstream file(testFile, ios::out);
    if(!file.is_open()){
        cout << "Error opening test seats file.\n";
        return;
    }
    saveToSeatsFile(testFile, sampleSeats);
    // to check if it works
    string seatClassStr;
    string seatNum;
    bool isBooked;
    while(file >>  seatNum >> seatClassStr >> isBooked){
        EXPECT_EQ(seatNum, "1A");
        EXPECT_EQ(seatClassStr, "First");
        EXPECT_EQ(isBooked, true);
    }
    
    file.close();
    
}



