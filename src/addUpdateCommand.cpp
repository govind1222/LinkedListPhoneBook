/*
 * addUpdateCommand.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#include "addUpdateCommand.h"
#include "bookCommand.h"
#include <iostream>

//constructs addUpdateCommand - builds bookCommand and creates phoneBook objects as well
addUpdateCommand::addUpdateCommand(phoneBook &bookIn, std::istream &inStream,
                                   std::ostream &outStream) :
        bookCommand(inStream, outStream), book(bookIn) {
    // any other code you may need
}

//execute function responsible for asking for user info
//adds a phoneBookEntry, based on information entered by user
void addUpdateCommand::execute() {
    std::string name, number, email;
    std::string prompt = "Enter name to add/update";

    //reads in user info
    name = readInput(prompt);
    prompt = "Enter phone number";
    number = readInput(prompt);
    prompt = "Enter e-mail address";
    email = readInput(prompt);

    phoneBookEntry tempEntry(name, number, email);

    //checks whether to add or update phone book entry
    std::string confirm;
    if (book.find(name)) {
        book.insert(name, number, email);
        confirm = "Updating ";
    } else {
        book.insert(tempEntry);
        confirm = "Adding ";
    }
    confirm += "phone book entry for " + name;
    display(confirm);

}

