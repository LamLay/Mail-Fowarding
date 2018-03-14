/*************************************************************************
 * 
 * File Name:       Address.h
 * Name:            Lam Lay
 * Course:          CPTR 142
 * Date:            January 31, 2018
 * 
 */
 
#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
using namespace std;


class Address {
    public:
        Address() {
            name = "Removed";
            oldAddress = "Removed";
            newAddress = "Removed";
        }    
            
        Address (string newName, string oldAddress1, string newAddress1) {
             name = newName;
             oldAddress = oldAddress1;
             newAddress = newAddress1;
        }
        
        // copy constructor
        // Address(const Address & arg) {
        //     name = arg.getName();
        //     oldAddress = arg.getOldAddress();
        //     newAddress = arg.getNewAddress();
        // }
        
        string getName() {
            return name;
        }
            
        string getOldAddress() {
            return oldAddress;
        }
        
        string getNewAddress() {
            return newAddress;
        }
        
    private: 
        string name;
        string oldAddress;
        string newAddress;
    
};

#endif //ADDRESS_H       