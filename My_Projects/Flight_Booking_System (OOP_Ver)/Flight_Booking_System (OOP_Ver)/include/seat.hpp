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
    virtual ~Seat() {}
};

class FirstClassSeat : public Seat {
public:
    FirstClassSeat(const string& num) : Seat(SeatClass::First, num, false) {}
};

class BusinessClassSeat : public Seat {
public:
    BusinessClassSeat(const string& num) : Seat(SeatClass::Business, num, false) {}
};

class EconomyClassSeat : public Seat {
public:
    EconomyClassSeat(const string& num) : Seat(SeatClass::Economy, num, false) {}
};


