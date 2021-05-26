/*
 * printCommand.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#ifndef PRINTCOMMAND_H_
#define PRINTCOMMAND_H_

#include <iostream>
#include "bookCommand.h"
#include "phoneBook.h"


//responsible for printing contents of phoneBookEntryList
class printCommand : public bookCommand {
public:
    printCommand(phoneBook &bookIn, std::istream &inStream,
                 std::ostream &outStream);

    virtual ~printCommand() {

    }

    virtual void execute() override;

private:
    phoneBook &book;
};

#endif /* PRINTCOMMAND_H_ */
