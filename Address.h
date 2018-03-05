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
using namespace std;

class Address {
    public:
        void addAddress (string newAddress);
        void removeAddress ();
        void mailAddress ();
        void quit();
    
    private:
        string name;
        string address;
};

#endif //ADDRESS_H       