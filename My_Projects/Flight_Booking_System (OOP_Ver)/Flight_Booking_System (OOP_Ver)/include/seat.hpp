#pragma once
#include <string>
using namespace std;

enum class SeatClass {First, Business, Economy};

// base class
class Seat {
protected:
    string seatNumber;
    bool isBooked;
    SeatClass seatClass;

public:
    Seat(SeatClass seatClass, const string& seatNumber, bool isBooked);
    
    // setter
    void setSeatNumber(const string& newSeatNumber);
    void setSeatClass(SeatClass newSeatClass);
    void setBookingStatus(bool booked);
    
    // getter
    bool getBookingStatus() const;
    SeatClass getSeatClass() const;
    string getSeatNumber() const;
    
    // Polymorphism
    virtual string getSeatInfo() const;
    virtual ~Seat() {}
};

// inheritance classes of Seat
class FirstClassSeat : public Seat {
public:
    FirstClassSeat(const string& num);
    string getSeatInfo() const override;
};

class BusinessClassSeat : public Seat {
public:
    BusinessClassSeat(const string& num);
    string getSeatInfo() const override;
};

class EconomyClassSeat : public Seat {
public:
    EconomyClassSeat(const string& num);
    string getSeatInfo() const override;
};


