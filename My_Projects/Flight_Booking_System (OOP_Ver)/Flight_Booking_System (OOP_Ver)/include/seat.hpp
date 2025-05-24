#pragma once
#include <string>
using namespace std;

enum class SeatClass {First, Business, Economy};

class Seat {
protected:
    string seatNumber;
    bool isBooked;
    SeatClass seatClass;

public:
    Seat(SeatClass seatClass, const string& seatNumber, bool isBooked)
    : seatClass(seatClass), seatNumber(seatNumber), isBooked(isBooked) {}
    
    // setter
    void setSeatNumber(const string& newSeatNumber) { seatNumber = newSeatNumber; }
    void setSeatClass(SeatClass newSeatClass) { seatClass = newSeatClass; }
    void setBookingStatus(bool booked) { isBooked = booked; }
    // getter
    bool getBookingStatus() const { return isBooked; }
    SeatClass getSeatClass() const { return seatClass; }
    string getSeatNumber() const { return seatNumber; }
    
    // Polymorphism
    virtual string getSeatInfo() const{
        return seatNumber + " First " + (isBooked ? "1" : "0");
    }

    virtual ~Seat() {}
};

class FirstClassSeat : public Seat {
public:
    FirstClassSeat(const string& num) : Seat(SeatClass::First, num, false) {}
    string getSeatInfo() const override{
        return seatNumber + " First " + (isBooked ? "1" : "0");
    }
};

class BusinessClassSeat : public Seat {
public:
    BusinessClassSeat(const string& num) : Seat(SeatClass::Business, num, false) {}
    string getSeatInfo() const override{
        return seatNumber + " Business " + (isBooked ? "1" : "0");
    }
};

class EconomyClassSeat : public Seat {
public:
    EconomyClassSeat(const string& num) : Seat(SeatClass::Economy, num, false) {}
    string getSeatInfo() const override{
        return seatNumber + " Economy " + (isBooked ? "1" : "0");
    }
};


