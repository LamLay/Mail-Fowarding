/*************************************************************************
 * File Name:       project2.cpp
 * Name:            lam Lay
 * Course:          CPTR 142
 * Date:            January 10, 2018
 * 
 */

#include <iostream>  // for cin and cout
#include <stdlib.h>  // for exit
#include <limits>    // for invalid input
#include "Address.h"
#include "ForwardAddress.h"
using namespace std;

/*====================================================================
 * Main program
 */
int main() {
    string name, address, oldAddress, newAddress;
    ForwardAddress user;
    
     // Loop to collect user input
    while(true) {
        
        // prompt for search term
        string input;
        cout << "****************************" << endl;
        cout << "Options: " << endl;
        cout << "   ADD: Add Address " << endl;
        cout << "   REMOVE: Remove Address " << endl;
        cout << "   MAIL: Mail Address " << endl;
        cout << "   QUIT: Quit the program" << endl;
        cout << "Enter your selection: ";
        getline(cin, input);
        
        
        if (input == "ADD") {
            cout << "What's your name? " << endl;
            getline(cin, name);
            cout << "Enter your old address: " << endl;
            getline(cin, oldAddress);
            cout << "Enter your new address: " << endl;
            getline(cin, newAddress);
            user.addAddress(name, oldAddress, newAddress);
        }
        else if (input == "REMOVE") {
            cout << "What's your name? " << endl;
            getline(cin, name);
            cout << "Enter your old address: " << endl;
            getline(cin, oldAddress);
            cout << "Enter your new address: " << endl;
            getline(cin, newAddress);
            user.removeAddress(name, oldAddress, newAddress);
        }
        else if (input == "MAIL") {
            cout << "What's your name? " << endl;
            getline(cin, name);
            cout << "What's address do you want to mail? " << endl;
            getline(cin, address);
            user.mailAddress(name, address);
        }
        else if (input == "QUIT") {
            cout << "Goodbye." <<endl;
            exit(0);
        }
        else {
            cout << "Invalid choice." << endl;
            exit(0);
        }
    }    
        
    return 0;
}    