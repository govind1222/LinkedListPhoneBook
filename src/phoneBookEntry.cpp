/*
 * phoneBookEntry.cpp
 *
 *  Created on: Nov 2, 2019
 *      Author: gxp180015
 */


#include <iostream>
#include <string>
#include "phoneBookEntry.h"

//default constructor for phoneBookEntry
phoneBookEntry::phoneBookEntry() {
    entryName = "";
    entryPhoneNumber = "";
    entryEmail = "";
}

//constructor for phoneBookEntry - 2 variables
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number) {
    entryName = name;
    entryPhoneNumber = number;
    entryEmail = "";
}

//constructor for phoneBookEntry - 3 variables
phoneBookEntry::phoneBookEntry(const std::string &name, const std::string &number, const std::string &email) {
    entryName = name;
    entryPhoneNumber = number;
    entryEmail = email;
}

//copy constructor
phoneBookEntry::phoneBookEntry(const phoneBookEntry &from) {
    entryName = from.entryName;
    entryPhoneNumber = from.entryPhoneNumber;
    entryEmail = from.entryEmail;
}

bool phoneBookEntry::operator==(const phoneBookEntry &entry) const {
    return entryName == entry.name();
}

bool phoneBookEntry::operator!=(const phoneBookEntry &entry) const {
    return entryName != entry.name();
}

bool phoneBookEntry::operator<(const phoneBookEntry &entry) const {
    return entryName < entry.name();
}

bool phoneBookEntry::operator<=(const phoneBookEntry &entry) const {
    return entryName <= entry.name();
}

bool phoneBookEntry::operator>(const phoneBookEntry &entry) const {
    return entryName > entry.name();
}

bool phoneBookEntry::operator>=(const phoneBookEntry &entry) const {
    return entryName >= entry.name();
}

std::ostream &operator<<(std::ostream &out, const phoneBookEntry &entry) {
    out << std::flush;
    if (entry.name() == "") {
        out << "";
        return out;
    } else {
        out << entry.name();
        if (entry.phoneNumber() != "") {
            out << ", " << entry.phoneNumber();
        }
        if (entry.email() != "") {
            out << ", " << entry.email();
        }
        return out;
    }
}

