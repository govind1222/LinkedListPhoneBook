/*
 * phoneBook.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include "phoneBookEntry.h"
#include "orderedLinkedList.h"

//stores the list containing phoneBookEntry objects
//also defines useful methods for modifying/adding/erasing objects
class phoneBook {
public:
    typedef orderedLinkedList<phoneBookEntry> phoneBookEntryList;
    phoneBookEntryList entries;
    typedef phoneBookEntryList::iterator iterator;

    phoneBook() {

    }

    void insert(const phoneBookEntry &entry);

    void insert(const std::string &name, const std::string &number,
                const std::string &email);

    void insert(const std::string &name, const std::string &number);

    bool erase(std::string name);

    bool find(std::string name);

    void print() const;

    void print(std::ostream &out) const;

    void debug(std::ostream &out) const;

    std::size_t size() const {
        return entries.size();
    }

    iterator begin() {
        return entries.begin();
    }

    iterator end() {
        return entries.end();
    }
};

#endif  /* PHONEBOOK_H_ */
