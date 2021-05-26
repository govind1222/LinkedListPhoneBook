/*
 * linkedList.h
 *
 * Implementation of a double linked list.
 *
 * We have the ability to get the first and last entries and navigate
 * through the entries in the linked list.
 *
 * There are actually three classes here:
 *
 * listNode<DataType>
 *
 * listNodeIterator<DataType>
 
 * and
 *
 * linkedList<DataType>
 *
 * The listNodeIterator is the iterator for the new linked list class. 
 * 
 */
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//#include "memoryLeak.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstddef>
#include <iterator>

// forward declaration of the template class linkedList
template<class DataType>
class linkedList;

// forward declaration of iterator
template<class DataType>
class linkedListIterator;

// listNode class
template<class DataType>
class listNode {
    // make DoubleLinkedList<DataType> a friend class
    friend class linkedList<DataType>;

    friend class linkedListIterator<DataType>;
    //friend class DoubleLinkedList<DataType>;
private:
    // contains the actual data
    DataType dataType;
    // pointer to the next item in the list or nullptr
    // if at the end
    listNode<DataType> *pNext;
    // pointer to the previous item in the list or nullptr
    // if at the start
    listNode<DataType> *pPrevious;
public:
    // default constructor
    listNode();

    // constructor with data
    listNode(const DataType &newItem);

protected:
    // get the next node
    listNode *next() const {
        return pNext;
    }

    // get the previous node
    listNode *previous() const {
        return pPrevious;
    }

    // return the data stored in the node as a const
    const DataType &data() const {
        return dataType;
    }

    // return the data stored in the node
    DataType &data() {
        return dataType;
    }

    // update the next node
    void next(listNode *nextNode) {
        pNext = nextNode;
    }

    // update the previous node
    void previous(listNode *previousNode) {
        pPrevious = previousNode;
    }
};

// the linkedListIterator is the iterator for class linkedList.
//
// most of this code has been provided for you. 
// the exceptions are the operator--() operator--(int) member functions and
// and the operator== and operator!= member functions. 
template<class DataType>
class linkedListIterator {
    typedef DataType value_type;
    typedef DataType &reference;
    typedef const DataType &const_reference;
    typedef DataType *pointer;
    typedef const DataType *const_pointer;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;
    typedef linkedListIterator iterator;
    typedef const linkedListIterator const_iterator;

    friend class linkedList<DataType>;

private:
    listNode<DataType> *current;
public:
    linkedListIterator(listNode<DataType> *current) :
            current(current) {
    }

    virtual ~linkedListIterator() {
    }

    reference operator*() {
        assert(current != nullptr);
        return current->data();
    }

    const_reference operator*() const {
        assert(current != nullptr);
        return current->data();
    }

    pointer operator->() {
        assert(current != nullptr);
        return &(current->data());
    }

    const_pointer operator->() const {
        assert(current != nullptr);
        return &(current->data());
    }

    iterator operator++() {
        if (current != nullptr) {
            current = current->next();
        }
        return *this;
    }

    iterator operator++(int) {
        iterator it = *this;
        if (current != nullptr) {
            current = current->next();
        }
        return it;
    }

    // you need to implement the following - they can be inlined if you want
    iterator operator--() {
        if (current != nullptr) {
            current = current->previous();
        }
        return *this;
    }

    iterator operator--(int) {
        iterator it = *this;
        if (current != nullptr) {
            current = current->previous();
        }
        return it;
    }

    bool operator==(const_iterator &other) const {
        return (current == other.current);
    }

    bool operator!=(const_iterator &other) const {
        return (current != other.current);
    }

};

// linkedList class
template<class DataType>
class linkedList {
public:
// 		typedef DataType 								value_type;
// 		typedef DataType& 								reference;
// 		typedef const DataType& 						const_reference;
// 		typedef DataType* 								pointer;
// 		typedef const DataType* 						const_pointer;
// 		typedef std::bidirectional_iterator_tag	        iterator_category;
// 		typedef std::ptrdiff_t 							difference_type;
// 		typedef std::size_t								size_type;
    typedef linkedListIterator<DataType> iterator;
    typedef const linkedListIterator<DataType> const_iterator;

private:
    // your instance data goes here. Things like the pointers to the first and last nodes
    //  as well as the count of nodes
    listNode<DataType> *firstNode;
    listNode<DataType> *lastNode;

public:
    int length = 0;
    // default constructor
    linkedList() {
        firstNode = nullptr;
        lastNode = nullptr;
    }

    // copy constructor
    linkedList(const linkedList &other) {
        firstNode = nullptr;
        lastNode = nullptr;
        length = 0;
        copyList(other);
    }

    // assignment operator
    const linkedList &operator=(const linkedList &other) {
        if (this != &other) {
            copyList(other);
        }
        return *this;
    }

    // destructor
    virtual ~linkedList() {
        while (!empty()) {
            pop_front();
        }
    }

    void copyList(const linkedList &other) {
        length = 0;
        firstNode = nullptr;
        lastNode = nullptr;

        listNode<DataType> *current = other.firstNode;
        while (current != nullptr) {
            push_back(current->data());
            current = current->next();
        }
    }

    // return the number of nodes in the list
    std::size_t size() const {
        return length;
    }

    // return true if the list is empty
    bool empty() const {
        return length == 0;
    }

    // display the contents of the list to std::cout
    void print() const {
        print(std::cout);
    }

    // display the contents of the list to the ostream&
    void print(std::ostream &out) const;

    // iterators
    iterator begin() {
        return iterator(firstNode);
    }

    const_iterator begin() const {
        return iterator(firstNode);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator end() const {
        return iterator(nullptr);
    }

    // dump the contends in debug format to passed in
    // ostream - usage to cout would be:
    //   list.debug(std::cout);
    void debug(std::ostream &out) const;

public:
    // add an item to the front of the list
    virtual void push_front(const DataType &newItem);

    // add an item to the back of the list
    virtual void push_back(const DataType &newItem);

    // remove an item from the front of the list
    virtual void pop_front();

    // remove an item from the back of the list
    virtual void pop_back();

    // insert newItem before the node specified by the iterator
    virtual void insert_before(iterator iter, const DataType &newItem);

    // insert newItem after the node specified by the iterator
    virtual void insert_after(iterator iter, const DataType &newItem);

    // find the node and return the iterator for that element.
    // Return end() if not found
    virtual iterator find(const DataType &existingItem);

    // remove the node equal to currentItem
    virtual bool erase(const DataType &currentItem);

    // remove the node by address existingNode
    virtual iterator erase(iterator iter);

    // return the iterator for the last node
    virtual iterator back() {
        return linkedListIterator<DataType>(lastNode);
    }

    virtual const_iterator back() const {
        return linkedListIterator<DataType>(lastNode);
    }

    virtual listNode<DataType> *head() {
        return firstNode;
    }

    virtual listNode<DataType> *tail() {
        return lastNode;
    }

protected:
private:
    // any helper functions you need should either be protected or private
};

// the constructors for the listNode class are included here
// default constructor
template<class DataType>
listNode<DataType>::listNode() :
        dataType(), pNext(nullptr), pPrevious(nullptr) {
}

// constructor with data
template<class DataType>
listNode<DataType>::listNode(const DataType &newItem) :
        dataType(newItem), pNext(nullptr), pPrevious(nullptr) {
}

// note the code for the debug() function is included
// display a debug version of the list
template<class DataType>
void linkedList<DataType>::debug(std::ostream &out) const {
    const unsigned int ADDRWIDTH = 10;
    out << "START DEBUG" << std::endl;
    out << "first  =" << std::setw(ADDRWIDTH) << firstNode;
    out << ", last=" << std::setw(ADDRWIDTH) << lastNode;
    out << ", # nodes=" << size() << std::endl;
    unsigned int count = 1;

    for (auto current = firstNode; current != nullptr; current =
                                                               current->next()) {
        out << "node " << std::setw(2) << count;
        out << "=" << std::setw(ADDRWIDTH) << current;
        out << ", next=" << std::setw(ADDRWIDTH) << current->next();
        out << ", previous=" << std::setw(ADDRWIDTH) << current->previous();
        out << ", value=" << current->data() << std::endl;
        count++;
    }
    out << "END DEBUG" << std::endl;
}

template<class DataType>
void linkedList<DataType>::print(std::ostream &out) const {
    for (auto current = firstNode; current != nullptr; current =
                                                               current->next()) {
        out << current->data() << std::endl;
    }
}

// I have included a few function headers and bodies here where the syntax is odd
// Your implementation of non-inlined member functions needs to go there.
// default constructor

// this is one where the C++ syntax gets very odd. Since we are returning back an iterator we
// need to qualify it with the class it is in (linkedList<DataType>::iterator and we 
// have to include the typename so the C++ compiler knows this is a typename and not some other
// template class usage. 
// find the node and return the address to the node. Return
// nullptr if not found
template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::find(
        const DataType &existingItem) {
    iterator curNode = begin();
    bool done = false;
    while (!done && curNode != end()) {
        if (curNode.current->data() == existingItem) {
            done = true;
        } else {
            ++curNode;
        }
    }
    return curNode;
}

// remove the node equal to currentItem
template<class DataType>
bool linkedList<DataType>::erase(const DataType &currentItem) {

    iterator iter = find(currentItem);
    if (iter.current == nullptr) {
        return false;
    }
    listNode<DataType> *curNode = iter.current;
    listNode<DataType> *sucNode = curNode->next();
    listNode<DataType> *predNode = curNode->previous();
    if (sucNode != nullptr) {
        sucNode->previous(predNode);
    }

    if (predNode != nullptr) {
        predNode->next(sucNode);
    }

    if (curNode == firstNode) { // Removed head
        firstNode = sucNode;
    }

    if (curNode == lastNode) { // Removed tail
        lastNode = predNode;
    }
    length--;
    if (empty()) {
        firstNode = nullptr;
        lastNode = nullptr;
    }

    return true;
}

// remove the node by iterator
template<class DataType>
typename linkedList<DataType>::iterator linkedList<DataType>::erase(
        linkedList<DataType>::iterator iter) {
    if (iter == end()) {
        return end();
    }
    listNode<DataType> *curNode = iter.current;
    listNode<DataType> *sucNode = curNode->next();
    listNode<DataType> *predNode = curNode->previous();
    iterator newIter = iter++;
    if (sucNode != nullptr) {
        sucNode->previous(predNode);
    }

    if (predNode != nullptr) {
        predNode->next(sucNode);
    }

    if (curNode == firstNode) { // Removed head
        firstNode = sucNode;
    }

    if (curNode == lastNode) { // Removed tail
        lastNode = predNode;
    }
    length--;

    if (empty()) {
        firstNode = nullptr;
        lastNode = nullptr;
    }
    return newIter;
}

// other member functions go here. 
template<class DataType>
void linkedList<DataType>::push_front(const DataType &newItem) {
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if (empty()) {
        firstNode = newNode;
        lastNode = newNode;
    } else {
        newNode->next(firstNode);
        firstNode->previous(newNode);
        firstNode = newNode;
    }
    length++;
}

template<class DataType>
void linkedList<DataType>::push_back(const DataType &newItem) {
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if (empty()) {
        firstNode = newNode;
        lastNode = newNode;
    } else {
        lastNode->next(newNode);
        newNode->previous(lastNode);
        lastNode = newNode;
    }
    length++;
}

template<class DataType>
void linkedList<DataType>::pop_front() {
    if (empty()) {
        return;
    }
    listNode<DataType> *sucNode = firstNode->next();
    listNode<DataType> *predNode = nullptr;
    if (sucNode != nullptr) {
        sucNode->previous(predNode);
    }
    firstNode = sucNode;
    length--;
    if (empty()) {
        firstNode = nullptr;
        lastNode = nullptr;
    }
}

template<class DataType>
void linkedList<DataType>::pop_back() {
    if (empty()) {
        return;
    }
    listNode<DataType> *sucNode = nullptr;
    listNode<DataType> *predNode = lastNode->previous();
    if (predNode != nullptr) {
        predNode->next(sucNode);
    }
    lastNode = predNode;
    length--;
    if (empty()) {
        firstNode = nullptr;
        lastNode = nullptr;
    }
}

template<class DataType>
void linkedList<DataType>::insert_before(iterator iter,
                                         const DataType &newItem) {
    listNode<DataType> *curNode = iter.current;
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if (empty()) {
        firstNode = newNode;
        lastNode = newNode;
        length++;
    } else if (curNode == firstNode) { //adding before the head is the same as push_front
        push_front(newItem);
    } else {
        iter--;
        insert_after(iter, newItem); //insert_before is the same as insert_after previous node
    }
}

template<class DataType>
void linkedList<DataType>::insert_after(iterator iter,
                                        const DataType &newItem) {
    listNode<DataType> *curNode = iter.current;
    listNode<DataType> *newNode = new listNode<DataType>(newItem);
    if (empty()) {
        firstNode = newNode;
        lastNode = newNode;
    } else if (curNode == lastNode) {
        lastNode->next(newNode);
        newNode->previous(lastNode);
        lastNode = newNode;
    } else {
        listNode<DataType> *sucNode = curNode->next();
        newNode->next(sucNode);
        newNode->previous(curNode);
        curNode->next(newNode);
        sucNode->previous(newNode);
    }
    length++;
}

// all of your member function need to be before the #endif
#endif /* DOUBLELINKEDLIST_H_ */
