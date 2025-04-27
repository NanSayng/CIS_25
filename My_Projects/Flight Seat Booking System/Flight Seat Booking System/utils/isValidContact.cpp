#include "isValidContact.hpp"

bool isValidContact(string& contact){
    // to check if it's just number with exactly 10 digits; no leading zero
    regex reg("^[1-9]\\d{9}$");
    return regex_match(contact, reg);
}
