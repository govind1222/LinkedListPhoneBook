/*
 * eraseCommand.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#include "eraseCommand.h"
#include "phoneBook.h"
#include <iostream>

//creates eraseCommand class and bookCommad
eraseCommand::eraseCommand(phoneBook &bookIn, std::istream &inStream,
                           std::ostream &outStream) :
        bookCommand(inStream, outStream), book(bookIn) {

}

//returns true if entry exists, and then deletes entry - else returns false
void eraseCommand::execute() {
    std::string prompt = "Enter name to erase";
    std::string name;
    name = readInput(prompt);
    if (book.erase(name)) {
        display("Phone book entry " + name + " was erased");
    } else {
        display("Phone book entry " + name + " was not erased");
    }
}
