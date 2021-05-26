/*
 * phoneBookEntry.h
 *
 *  Created on: Nov 2, 2019
 *      Author: gxp180015
 */

#ifndef PHONEBOOKENTRY_H_
#define PHONEBOOKENTRY_H_

#include <iostream>
#include <string>

//stores name, phone number, and email for each phone book entry
class phoneBookEntry {
private:
    std::string entryName;
    std::string entryPhoneNumber;
    std::string entryEmail;
public:
    phoneBookEntry();

    phoneBookEntry(const std::string &name, const std::string &number);

    phoneBookEntry(const std::string &name, const std::string &number,
                   const std::string &email);

    phoneBookEntry(const phoneBookEntry &from);

    //returns name
    std::string name() const {
        return entryName;
    }

    //returns number
    std::string phoneNumber() const {
        return entryPhoneNumber;
    }

    //return email
    std::string email() const {
        return entryEmail;
    }

    //sets number to newNumber
    void phoneNumber(const std::string &newNumber) {
        entryPhoneNumber = newNumber;
    }

    //sets email to newEmail
    void email(const std::string &newEmail) {
        phoneBookEntry::entryEmail = newEmail;
    }

    bool operator==(const phoneBookEntry &entry) const;

    bool operator!=(const phoneBookEntry &entry) const;

    bool operator<(const phoneBookEntry &entry) const;

    bool operator<=(const phoneBookEntry &entry) const;

    bool operator>(const phoneBookEntry &entry) const;

    bool operator>=(const phoneBookEntry &entry) const;

};

std::ostream &operator<<(std::ostream &out, const phoneBookEntry &entry);

#endif  /* PHONEBOOKENTRY_H_ */
