/*************************************************************************
 * 
 * File Name:       ForwardAddress.h
 * Name:            Lam Lay
 * Course:          CPTR 142
 * Date:            January 31, 2018
 * 
 */
 
#ifndef FORWARDADDRESS_H
#define FORWARDADDRESS_H
#include <string>
#include "Address.h"
using namespace std;

class ForwardAddress {
    public:    
        void addAddress (string name, string oldAddress, string newAddress);
        void removeAddress (string name, string oldAddress, string newAddress);
        void mailAddress (string name, string address);
        
    private:
        Address* ptr = new Address[100];
        int numberOfEntry = 0;
};     

#endif //FORWARDADDRESS_H  