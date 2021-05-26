/*
 * bookCommand.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#include <iostream>
#include "bookCommand.h"

//constructs bookCommand, creates command
bookCommand::bookCommand(std::istream &inStream, std::ostream &outStream) :
        in(inStream), out(outStream) {
    // other code, if any, goes here
}

//displays string input to the user
void bookCommand::display(std::string input) {
    bookCommand::out << input << std::endl;
}

//prompts the user to enter input and reads the input
std::string bookCommand::readInput(std::string prompt) {
    out << prompt << std::endl;
    std::string userInput;
    getline(in, userInput);
    return userInput;
}
