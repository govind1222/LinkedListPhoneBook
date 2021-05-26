/*
 * phoneBook.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#include "phoneBook.h"
#include <vector>
#include <string>

//adds phoneBookEntry to the list
void phoneBook::insert(const phoneBookEntry &entry) {
    entries.insert(entry);
}

//uses function parameters to create phoneBookEntry, then adds to object to list
void phoneBook::insert(const std::string &name, const std::string &number,
                       const std::string &email) {
    phoneBookEntry entry(name, number, email);
    insert(entry);
}

//uses function parameters to create phoneBookEntry without email, then adds to list
void phoneBook::insert(const std::string &name, const std::string &number) {
    phoneBookEntry entry(name, number);
    insert(entry);
}

//erases object with "name" if it exists in the list
bool phoneBook::erase(std::string name) {
    phoneBookEntry temp(name, "", "");
    return entries.erase(temp);
}

//finds object with "name" if it exists in the list
bool phoneBook::find(std::string name) {
    for (iterator iter = entries.begin(); iter != entries.end(); iter++) {
        phoneBookEntry temp = *iter;
        if (temp.name() == name) {
            return true;
        }
    }
    return false;
}

//prints the contents of the list to cout
void phoneBook::print() const {
    print(std::cout);
}

//prints the contents of the list to ostream object out
void phoneBook::print(std::ostream &out) const {
    const int NAME_COLUMN = 31;
    const int NUMBER_COLUMN = 16;
    out << "Name:                          Phone Number:   E-Mail:"
        << std::endl;
    for (iterator iter = entries.begin(); iter != entries.end(); iter++) {
        phoneBookEntry temp = *iter;
        out << std::left << std::setw(NAME_COLUMN)
            << temp.name() << std::setw(NUMBER_COLUMN)
            << temp.phoneNumber()
            << temp.email() << std::endl;
    }
}

//debugs the contents of the list to ostream object out by printing all the contents out
void phoneBook::debug(std::ostream &out) const {
    entries.debug(out);
}

