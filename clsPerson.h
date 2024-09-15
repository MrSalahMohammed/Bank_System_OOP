#pragma once

#include <iostream>
#include <string>
using namespace std;

class clsPerson {

private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:

    clsPerson(string FirstName, string LastName, string Email, string Phone) {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;

    }

    void SetFirstName(string FirstName) {

        _FirstName = FirstName;

    }

    string FirstName() {
        return _FirstName;
    }

    void SetLastName(string LastName) {

        _LastName = LastName;

    }

    string LastName() {
        return _LastName;
    }

    void SetEmail(string Email) {

        _Email = Email;

    }

    string Email() {
        return _Email;
    }

    void SetPhoneNumber(string PhoneNumber) {

        _Phone = PhoneNumber;

    }

    string PhoneNumber() {
        return _Phone;
    }

    string FullName() {
        return _FirstName + " " + _LastName;
    }

};
