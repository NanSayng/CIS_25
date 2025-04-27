#include "cancelBooking.hpp"

void cancelBooking(){
    string name, passportNum, input;
    // get valid name
    while(true){
        cout << "Enter passenger name: ";
        cin >> name;
        if(name.empty() || !isValidName(name)){
            cout << "Invalid name.\n";
        }else{
            break;
        }
    }
    // get valid passport number
    while(true){
        cout << "Enter passport number: ";
        cin >> passportNum;
        if(passportNum.empty() || !isValidPassNum(passportNum)){
            cout << "Invalid passport number. Enter length of 6 to 9.\n";
        }else{
            break;
        }
    }
    auto it = passengers.find(passportNum);
    if(it != passengers.end() && name == (*it).second->name){
        cout << "Booking found: Seat " << (*it).second->seatNumber << endl;
        // check user input
        while(true){
            cout << "Are you sure you want to cancel this booking? (y/n): ";
            cin >> input;
            if(input.empty() || !isValidChar(input)){
                cout << "Invalid input.\n";
            }else{
                break;
            }
        }
        if(input == "y" || input == "Y"){
            for(auto& seatPair : seats){
                if(seatPair.second->seatNumber == (*it).second->seatNumber){
                    seatPair.second->isBooked = 0;
                    // upgrade seats file
                    saveToSeatsFile();
                    // remove passenger from unordered_map
                    passengers.erase(passportNum);
                    // upgrade passengers file
                    saveToPassengersFile(passengers);
                    break;
                }
            }
            cout << "\nBooking for " << name << " has been cancelled successfully.\n";
        }else{
            int choice;
            do{
                string seatsFile = "seats.txt";
                displayMenu();
                choice = getValidChoice();
                switch(choice){
                    case 1:
                        viewFlightSeats(seatsFile);
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
    }else if(it != passengers.end() && name != (*it).second->name){
        cout << "Name and passport number doesn't match.\n";
    }else{
        cout << "No booking found under that name and passport number.\n";
    }
};
