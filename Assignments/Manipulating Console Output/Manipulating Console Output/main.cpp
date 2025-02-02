#include <iostream>
#include <iomanip>  // for I/O manipulators
#include <string>
using namespace std;

// Prototypes
int getNameWidth(string[], int); // get maximum width for names column
int getBalWidth(double[], int);  // get maximum width for balance column

int main(){
    string title = "Daily Report"; // Title
    string headers[] = {"ID", "Name", "Balance"}; // Column headers
    string name[] = {"Alice", "Bob", "Charlie", "Nan Sayng"}; // Names
    double balance[] = {1000.00, 530.25, 2040.50, 145.2}; // Balances
    int id[] = {1,2,3, 4}; // IDs
    // Set max column widths for each column
    int idMaxSize = 5;
    int nameMaxSize = getNameWidth(name, sizeof(name) / sizeof(name[0]));
    int balMaxSize = getBalWidth(balance, sizeof(balance) / sizeof(balance[0]));
    
    int sizes[] = {idMaxSize, nameMaxSize, balMaxSize + 1}; // add one for '$'
    int totalWidth = idMaxSize + nameMaxSize + balMaxSize + 6; // Total width for the whole report
    int titleSize = ((totalWidth - title.length()) / 2) + title.length(); // For space before title
    
    // Title
    cout << setfill(' ') << setw(titleSize) << title << endl;
    
    // Headers
    for(int i = 0; i < sizeof(headers) / sizeof(headers[0]); i++){
        cout << left << setfill(' ') << setw(sizes[i]) << headers[i] << "   ";
    }
    cout << endl;
    
    // Divider
    for(int i = 0; i < 3; i++){
        cout << setfill('-') << setw(sizes[i]) << '-' << "   ";
    }
    cout << endl;
    
    // Data rows
    for(int i = 0; i < sizeof(id) / sizeof(id[0]); i++){
        cout << right << setfill('0') << setw(idMaxSize) << id[i] << "   ";
        cout << left << setfill(' ') << setw(nameMaxSize) << name[i] << "   ";
        cout << fixed << setprecision(2);
        cout << left << "$" << setfill(' ') << setw(balMaxSize) << balance[i] << endl;
    }
    cout << endl;
    return 0;
}

int getNameWidth(string name[], int size){
    int maxWidth = 0;
    for(int i = 0; i < size; i++){
        if(name[i].length() > maxWidth)
            maxWidth = name[i].length();
    }
    return maxWidth;
}

int getBalWidth (double bal[], int size){
    int maxWidth = 0;
    for(int i = 0; i < size; i++){
        string balStr = to_string(bal[i]);
        balStr = balStr.substr(0, balStr.find('.') + 3);
        if(balStr.length() > maxWidth)
            maxWidth = balStr.length();
    }
    return maxWidth;
}
