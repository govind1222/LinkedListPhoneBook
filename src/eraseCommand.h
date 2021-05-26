/*
 * eraseCommand.h
 *
 *  Created on: Oct 3, 2019
 *      Author: gxp180015
 */

#ifndef ERASECOMMAND_H_
#define ERASECOMMAND_H_

#include "bookCommand.h"
#include "phoneBook.h"

//responsible for erasing entries from the phone book
class eraseCommand : public bookCommand {
public:
    eraseCommand(phoneBook &bookIn, std::istream &inStream,
                 std::ostream &outStream);

    virtual ~eraseCommand() {

    }

    virtual void execute() override;

private:
    phoneBook &book;
};

#endif /* ERASECOMMAND_H_ */
