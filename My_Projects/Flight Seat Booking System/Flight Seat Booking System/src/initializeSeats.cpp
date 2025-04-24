#include "initializeSeats.hpp"

void initializeSeats(){
    for(int i = 1; i <= 5; i++){
        seats[to_string(i) + "A"] = Seat{SeatClass::First, to_string(i) + "A", false};
        seats[to_string(i) + "B"] = Seat{SeatClass::Business, to_string(i) + "B", false};
        seats[to_string(i) + "C"] = Seat{SeatClass::Economy, to_string(i) + "C", false};
    }
}
