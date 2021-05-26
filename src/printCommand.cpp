/*
 * printCommand.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#include <iostream>
#include "printCommand.h"
#include "phoneBook.h"

//creates printCommand object
printCommand::printCommand(phoneBook &bookIn, std::istream &inStream,
                           std::ostream &outStream) :
        bookCommand(inStream, outStream), book(bookIn) {

}

//calls phoneBook print function, outputs contents of vector containing phoneBookEntry objects
void printCommand::execute() {
    book.print(out);
}
