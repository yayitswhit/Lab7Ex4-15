//
//  main.cpp
//  Lab7Ex4-15
//
//  Created by Gilbert W. Sanborn Jr on 2/16/23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main() {
    int amtToWithdraw;
    double accountBalance;
    double serviceCharge;
    ifstream inFile;
    ofstream outFile;
    
    //enter withdrawal amount from the user
    cout << "Enter the withdrawal amount: ";
    cin >> amtToWithdraw;
    
    
    //open data file to read in
    inFile.open("/Users/whitsanborn/Documents/Gateway/Programming with Object Oriented C++/Lab7Ex4-15/Ch4_Ex15_Data.txt");
    
    //open data file to output
    outFile.open("/Users/whitsanborn/Documents/Gateway/Programming with Object Oriented C++/Lab7Ex4-15/outData.txt");

    //read in account balance from data file
    //if withdrawal amount is greater than 500 inform user that 500 is the max amount
    inFile >> accountBalance;
    if(amtToWithdraw > 500) {
        cout << "The maximum amount that can be withdrawan is $500" << endl;
        return 0;
    }
    
    if(accountBalance <= 0) {
        cout << "You don't have enough money in your account." << endl;
        return 0;
    }
    
    if(amtToWithdraw > 300) {
        serviceCharge = .04 * (amtToWithdraw - 300);
    }
    
    //get response from user
    string response;
    double insufficientServiceCharge;

    cin >> response;
    if(amtToWithdraw > accountBalance) {
        cout << "Insufficient funds. You will be charged $25 to continue" << endl;
    }
    if(response == "Y" || response == "y" || response == "Yes" || response == "yes") {
        insufficientServiceCharge = 25;
        }
    else if(response == "N" || response == "n" || response == "No" || response == "no") {
        return 0;
        }

    cout << insufficientServiceCharge << endl;
    double totalDebits;
    totalDebits = amtToWithdraw + serviceCharge + insufficientServiceCharge;
    
    cout << "total debits: " << totalDebits << endl;
    cout << setw(35) << setfill('.') << left << "Dispense the amount" << totalDebits << endl;
    
    double acctBalanceAfterWthdraw;
    acctBalanceAfterWthdraw = accountBalance - amtToWithdraw;
    cout << "Account balance before withdraw: " << accountBalance;
    cout << "Account balance after withdraw" << acctBalanceAfterWthdraw << endl;
    cout << "Total service charges: " << serviceCharge + insufficientServiceCharge << endl;
    inFile.close();
    outFile.close();
    
    return 0;
}
