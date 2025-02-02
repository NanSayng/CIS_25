#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

// prototypes
double convertCurr(int, double[], double); // covert the currency to target currency
double applyPromotion(const double[], double, int); // apply 10% promotion

int main(){
    int originIndex, finalIndex;
    double amount, convertedCurr; // double type for more precised currency
    double targetArr[4];
    string curr[] = {"GBP", "EUR", "USD", "JPY"};
    
    // array storing each currency rate {GBP[], EUR[], USD[], JPY[]). Double type for precision in rate
    const double rate[4][4] = {{1.00, 1.20, 1.24, 192.30}, // Currency rate from gpy, eur, usd, jpy to each currecy
        {0.84, 1.00, 1.04, 160.81},
        {0.81, 0.96, 1.00, 155.18},
        {0.0052, 0.0062, 0.0064, 1.00}};
    
    // get the user's inputs
    cout << "1. British Pound\n2. Euro\n3. U.S. Dollar\n4. Japanese Yen\n\n";
    do {
        cout << "Enter the number of currency to convert from: ";
        cin >> originIndex;
        if(originIndex < 1 || originIndex > 4)
            cout << "Invalid number!\n";
    } while (originIndex < 1 || originIndex > 4);
    do {
        cout << "Enter the number of currency to convert to: ";
        cin >> finalIndex;
        if(finalIndex < 1 || finalIndex > 4)
            cout << "Invalid number!\n";
    } while (finalIndex < 1 || finalIndex > 4);
    // get the correct currecy amount
    do {
        cout << "Enter the amount: ";
        cin >> amount;
        if(amount < 0)
            cout << "Invalid currency!\n";
    } while (amount < 0);
    
    // target the correct rate array
    for(int i = 0; i < 4; i++){
        targetArr[i] = rate[originIndex - 1][i];
    }
    
    // applied 10% promotion if there's any
    srand(time(nullptr));
    bool isPromotion = rand() % 2; // 50% chance to get promotion
    if(isPromotion) {
        cout << "\nBlack Friday promotion applied by 10%! New rate: " << targetArr[finalIndex - 1] * 1.10 << endl;
        convertedCurr = applyPromotion(targetArr, amount, finalIndex);
    }
    else
        convertedCurr = convertCurr(finalIndex, targetArr, amount);
    
    // display the output in 2 decimal place
    cout << fixed << setprecision(2) << endl;;
    cout << setfill(' ') << setw(24) << "Currency Converter\n";
    cout << setfill('-') << setw(30) << '-' << endl;
    cout << left << setfill(' ') << setw(13) << curr[originIndex - 1] << "--->";
    cout << right << setfill(' ') << setw(13) << curr[finalIndex - 1] << endl;
    cout << left << setfill(' ') << setw(13) << amount << "--->";
    cout << right << setfill(' ') << setw(13) << convertedCurr << endl;
    cout << setfill('-') << setw(30) << '-' << endl;
    return 0;
}

double convertCurr(int finalIndex, double rate[], double amnt){
    amnt *= rate[finalIndex - 1];
    return amnt;
}

double applyPromotion(const double rate[], double amount, int finalIndex){
    double *newRate = const_cast<double*>(&rate[finalIndex - 1]);
    *newRate *= 1.10; // Increase the rate by 10%
    return amount * *newRate; // New converted currency
}

