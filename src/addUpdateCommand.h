/*
 * addUpdateCommand.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#ifndef ADDUPDATECOMMAND_H_
#define ADDUPDATECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"
#include <string>

//class addUpdateCommand responsible for adding/updating entries to phone book
class addUpdateCommand : public bookCommand {
public:
    addUpdateCommand(phoneBook &bookIn, std::istream &inStream,
                     std::ostream &outStream);

    virtual ~addUpdateCommand() {
    }

    virtual void execute() override;

private:
    phoneBook &book;
};

#endif /* ADDUPDATECOMMAND_H_ */

