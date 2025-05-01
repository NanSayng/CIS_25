#include "../include/display.hpp"

void displayMenu(){
    cout << "\n--- Welcome to Nan's Airline ---\n\n";
    cout << "1.\tView flight seats\n";
    cout << "2.\tBook a seat\n";
    cout << "3.\tCancel booking\n";
    cout << "4.\tView passengers list\n";
    cout << "5.\tExit\n";
}

void viewFlightSeats(){
    cout << "\nAvailable Seats: \n";
    cout << "\nFirst Class: \n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::First){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "\nBusiness Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::Business){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
    cout << "\nEconomy Class:\n";
    for(const auto& seatPair : seats){
        if(seatPair.second->seatClass == SeatClass::Economy){
            if(!seatPair.second->isBooked){
                cout << "[" << seatPair.first << "] Available  ";
            }else{
                cout << "[" << seatPair.first << "] Booked  ";
            }
        }
    }
    cout << endl;
}

void viewPassengersList(){
    int num = 1;
    cout << "\nPassengers list: \n";
    if(!passengers.empty()){
        for(auto& passengerPair: passengers){
            // dereference unique_ptr to access each Passenger object
            auto& passenger = *passengerPair.second;
            // display passenger information
            cout << num << ". " << passenger.name << " | Age: " << passenger.age << " | Phone: " << passenger.contact << " | Passport: " << passenger.passportNumber << " | Seat: " << passenger.seatNumber ;
            if(passenger.seatClass == SeatClass::First){
                cout << " (First class)\n";
            }else if(passenger.seatClass == SeatClass::Business){
                cout << " (Business class)\n";
            }else{
                cout << " (Economy class)\n";
            }
            num++;
        }
    }else{
        cout << "There's no passengers to view.\n";
    }
}

void exitProgram(){
    string input;
    // get valid input
    while(true){
        cout << "Are you sure you want to exit? (y/n): ";
        cin >> input;
        if(input.empty() || !isValidChar(input)){
            cout << "Invalid input. Please try again.\n";
        }else{
            break;
        }
    }
    if(input == "Y" || input == "y"){
        cout << "I hope you a wonderful day. Bye!\n";
        exit(0);
    }else{
        int choice;
        do{
            string seatsFile = "seats.txt";
            displayMenu();
            // get valid choice
            while(true){
                cout << "Enter your choice (1-5): ";
                cin >> choice;
                string choiceStr = to_string(choice);
                if(choiceStr.empty() || !isValidChoice(choiceStr)){
                    cout << "Invalid choice.\n";
                }else{
                    break;
                }
            }
            switch(choice){
                case 1:
                    viewFlightSeats();
                    break;
                case 2:
                    bookFlightSeat();
                    break;
                case 3:
                    cancelBooking();
                    break;
                case 4:
                    viewPassengersList();
                    break;
                case 5:
                    exitProgram();
                    break;
                default:
                    break;
            }
        }while(choice != 5);
    }
};

