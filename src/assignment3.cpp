/*
 * assignment1.cpp
 *
 *  Created on: Nov 1, 2019
 *      Author: gxp180015
 */

#include <iostream>
#include <string>
#include "linkedList.h"
#include "orderedLinkedList.h"
#include "phoneBookEntry.h"
#include "phoneBook.h"
#include "menuList.h"
#include "addUpdateCommand.h"
#include "eraseCommand.h"
#include "printCommand.h"

int main() {
    std::istream &instream = std::cin;
    std::ostream &outstream = std::cout;
    phoneBook book;
    menuList menu("Phone book menu:");

    //creating commands
    addUpdateCommand addUpdate(book, instream, outstream);
    eraseCommand erase(book, instream, outstream);
    printCommand print(book, instream, outstream);

    //building menuItems
    menuItem addUpdateItem('a', "add/update", addUpdate);
    menuItem eraseItem('e', "erase", erase);
    menuItem printItem('p', "print", print);

    //building itemList
    menu.add(addUpdateItem);
    menu.add(eraseItem);
    menu.add(printItem);

    std::cout << "Starting the Phone Book\n" << std::endl;
    menu.start();
    return 0;

}
