/*
 * bookCommand.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#ifndef BOOKCOMMAND_H_
#define BOOKCOMMAND_H_

#include "command.h"
#include <iostream>
#include <string>

//main class for all phoneBook commands, inherits command class
class bookCommand : public command {
public:
    bookCommand(std::istream &inStream, std::ostream &outStream);

    virtual void execute() = 0;

protected:
    std::istream &in;
    std::ostream &out;

    void display(std::string input);

    std::string readInput(std::string prompt);
};

#endif /* BOOKCOMMAND_H_ */
