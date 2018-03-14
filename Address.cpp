/*************************************************************************

 * File Name:       Address.cpp
 * Name:            Lam Lay
 * Course:          CPTR 142
 * Date:            February 28, 2018
 * 
 */
 
  
#include <iostream> // for cin and cout
#include "Address.h"
#include "ForwardAddress.h"
#include <string>
using namespace std;

/*====================================================================
 */

bool findName(string name, Address ptr[]) {
    for (int i = 0; i < 100; i++) {
        if (ptr[i].getName() == name) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool findAddress(string address, Address ptr[]) {
    for (int i = 0; i < 100; i++) {
        if (ptr[i].getOldAddress() == address) {
            return true;
        }
        else {
            return false;
        }
    }
}

int findNameIndex(string name, Address ptr[]) {
    for (int i = 0; i < 100; i++) {
        if (ptr[i].getName() == name) {
            return i;
        }
        else {
            return -1;
        }
    }
}

int findAddressIndex(string address, Address ptr[]) {
    for (int i = 0; i < 100; i++) {
        if (ptr[i].getOldAddress() == address) {
            return i;
        }
        else {
            return -1;
        }
    }
}

// int findNameIndex(string name, Address ptr[]) {
//     bool pass = findName(name, ptr);
//     if (pass == true) 
//         return 
    
// }


void ForwardAddress::addAddress(string name, string oldAddress, string newAddress) {
    bool pass1 = findName(name, ptr);
    bool pass2 = findAddress(oldAddress, ptr);
    if (pass1 == true && pass2 == true) {
        cout << "Entry already exists." << endl;
    }
    else {
        ptr[numberOfEntry] = Address(name, oldAddress, newAddress);
        cout << "old address1 is " << ptr[numberOfEntry].getOldAddress() << endl;
        cout << "new address1 is " << ptr[numberOfEntry].getNewAddress() << endl;
        cout << "Added." << endl;
        numberOfEntry ++;
    }
}

void ForwardAddress::removeAddress (string name, string oldAddress, string newAddress) {
    bool pass1 = findName(name, ptr);
    bool pass2 = findAddress(oldAddress, ptr);
    int i = findNameIndex(name, ptr);
    if (pass1 == true && pass2 == true) {
        cout << "Removed" << endl;
        ptr[i] = Address();
    } 
    else {
        cout << "No such entry" << endl;
    }
}

// void ForwardAddress::mailAddress (string name, string address) {
//     bool pass1 = findName(name, ptr);
//     bool pass2 = findAddress(address, ptr);
//     int i = findNameIndex(name, ptr);

//     if (pass1 == true && pass2 == true) {
//         bool pass3 = findAddress(ptr[i].getNewAddress(), ptr);
//         int j = findAddressIndex(ptr[i].getNewAddress(), ptr);
//         if (pass3 == true) 
//             cout << "Send to " << ptr[j].getNewAddress() << endl; 
//         else     
//             cout << "Send to " << ptr[i].getNewAddress() << endl;    
//     }
//     else 
//         cout << "Send to " << address << endl;    
// }    
  

// void ForwardAddress::mailAddress (string name, string address) {
//     bool pass1 = findName(name, ptr);
//     bool pass2 = findAddress(address, ptr);
//     int j = findAddressIndex(address, ptr);
//     if (pass1 == true && pass2 == true)
//         cout << "Send to " << ptr[j].getNewAddress() << endl;
//     else
//         cout << "Send to " << address << endl;
// }        

void ForwardAddress::mailAddress (string name, string address) {
    bool pass1 = findName(name, ptr);
    bool pass2 = findAddress(address, ptr);
    int i = findAddressIndex(address, ptr);

    if (pass1 == true && pass2 == true) {
        string newOldAddress = ptr[i].getNewAddress();
        cout << "old address1 is " << ptr[i].getNewAddress() << endl;
        cout << "old address2 is " << newOldAddress << endl;
        
        bool pass3 = findAddress(newOldAddress, ptr);
        int j = findAddressIndex(newOldAddress, ptr);
        if (j != -1) {
            cout << "new address is " << ptr[j].getNewAddress() << endl;
            if (pass3 == true) 
                cout << "Send to " << ptr[j].getNewAddress() << endl; 
            else     
                cout << "Send to " << ptr[i].getNewAddress() << endl;   
        }
    }
    else 
        cout << "Send to " << address << endl;    
}    

