#include <iostream>
#include <iomanip>
#include "validateStreetInput.hpp"
#include "validateCityInput.hpp"
using namespace std;

struct Address{
    string street;
    string city;
    int zipCode;
};

struct Customer{
    Address address;
};

int main(){
    Customer customer;
    // get street
    while(true){
        cout << "Enter the street name: ";
        getline(cin, customer.address.street);
        if(customer.address.street.empty() || !validateStreet(customer.address.street)){
            cout << "Invalid street.\n";
        }else{
            break;
        }
    }
    // get city
    while(true){
        cout << "Enter the city name: ";
        getline(cin, customer.address.city);
        if(customer.address.city.empty() || !validateCity(customer.address.city)){
            cout << "Invalid city.\n";
        }else{
            break;
        }
    }
    // get 5 digit zipCode
    while(true){
        cout << "Enter the zipCode: ";
        cin >> customer.address.zipCode;
        if(cin.fail() || customer.address.zipCode < 10000 || customer.address.zipCode > 99999){
            cout << "Invalid zipCode. Please enter 5 digit zipcode.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            break;
        }
    }
    // display
    cout << "\nCustomer address:\n";
    cout << setfill('-') << setw(20) << '-' << endl;
    cout << "Street: " << customer.address.street << endl;
    cout << "City: " << customer.address.city << endl;
    cout << "ZipCode: " << customer.address.zipCode << endl;
    
    return 0;
}
