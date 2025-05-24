#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "seat.hpp"
#include "passenger.hpp"
#include "validateUserInputs.hpp"
using namespace std;

class FlightBookingSystem{
private:
    map<string, shared_ptr<Seat>> seats;
    unordered_map<string, unique_ptr<Passenger>> passengers;
    string passengersFile = "passengers.dat";
    string seatsFile = "seats.txt";
public:
    FlightBookingSystem() {}
    void displayMenu();
    int getMenuOption();
    // getter
    map<string, shared_ptr<Seat>>& getSeats() { return seats; }
    unordered_map<string, unique_ptr<Passenger>>& getPassengers() { return passengers; }
    string getPassengersFile() { return passengersFile; }
    string getSeatsFile() { return seatsFile; }
    
    // fileIO
    // read from files
    void loadFromPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers);
    void loadFromSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats);

    // write to files
    void saveToPassengersFile(const string& passengersFile, unordered_map<string, unique_ptr<Passenger>>& passengers);
    void saveToSeatsFile(const string& seatsFile, map<string, shared_ptr<Seat>>& seats);
    // menu
    void bookFlightSeat();
    void cancelBooking();
    void viewFlightSeats();
    void viewPassengersList();
    void exitProgram();
    // run program
    void runProgram();
};
