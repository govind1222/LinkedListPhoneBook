/*
 * orderedLinkedList.h
 *
 * Store the DataType values in sorted order. This ordering
 * is determined by the comparison operators of the DataType
 * class.
 *
 */

#ifndef ORDEREDLINKEDLIST_H_
#define ORDEREDLINKEDLIST_H_

#include <cstddef>

#include "linkedList.h"
#include "phoneBookEntry.h"

template<class DataType>
class orderedLinkedList {
public:
    typedef linkedList<DataType> unorderedLinkedList;
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef std::ptrdiff_t difference_type;
    typedef std::size_t size_type;
    typedef typename unorderedLinkedList::iterator iterator;
    typedef const iterator const_iterator;
private:
    // we are making use of the DoubleLinkedList class
    unorderedLinkedList list;
    //iterator iter;
public:
    // default constructor
    orderedLinkedList() {

    }

    // copy constructor
    orderedLinkedList(const orderedLinkedList &other) {
        list.firstNode = nullptr;
        list.lastNode = nullptr;
        list.length = 0;
        list.copyList(other.list);
    }

    // assignment operator
    const orderedLinkedList &operator=(const orderedLinkedList &other) {
        if (this != &other) {
            list.copyList(other.list);
        }
        return *this;
    }

    // destructor
    virtual ~orderedLinkedList() {
        while (list.length != 0) {
            list.pop_front();
        }
    }

    virtual void copyAll(const orderedLinkedList &other) {
        list.copyList(other.list);
    }

    // iterators
    iterator begin() {
        return list.begin();
    }

    iterator end() {
        return list.end();
    }

    const_iterator begin() const {
        return list.begin();
    }

    const_iterator end() const {
        return list.end();
    }

    // number of items in the list
    virtual std::size_t size() const {
        return list.size();
    }

    // is the list empty (true) or does it have entries (false)
    virtual bool empty() const {
        return size() == 0;
    }

    // print the items in the list
    virtual void print() const {
        print(std::cout);
    }

    // display the contents of the list to the ostream&
    virtual void print(std::ostream &out) const;

    // display debug information on the passed in ostream
    virtual void debug(std::ostream &out) const;

    // find the element and return an interator for it
    virtual iterator find(const DataType &existingItem);

    // remove the node equal to currentItem
    virtual bool erase(const DataType &currentItem);

    // remove the node by address existingNode
    virtual iterator erase(iterator iter);

    // insert the new item into the list (in sorted order)
    // a duplicate entry will be ignored
    virtual void insert(const DataType &newItem);

    // get the last entry
    iterator back() {
        return list.back();
    }

    const_iterator back() const {
        return list.back();
    }
};

// Your implementation code goes here

template<class DataType>
void orderedLinkedList<DataType>::print(std::ostream &out) const {
    list.print(out);
}

template<class DataType>
void orderedLinkedList<DataType>::debug(std::ostream &out) const {
    list.debug(out);
}

template<class DataType>
typename orderedLinkedList<DataType>::iterator orderedLinkedList<DataType>::find(
        const DataType &existingItem) {
    return list.find(existingItem);
}

template<class DataType>
bool orderedLinkedList<DataType>::erase(const DataType &currentItem) {
    return list.erase(currentItem);

}

template<class DataType>
typename orderedLinkedList<DataType>::iterator orderedLinkedList<DataType>::erase(
        iterator iter) {
    return list.erase(iter);
}

template<class DataType>
void orderedLinkedList<DataType>::insert(const DataType &newItem) {

    iterator iter = find(newItem);
    if (iter != nullptr) {
        list.erase(newItem);
        insert(newItem);
        return;
    }
    for (auto iter = begin(); iter != end(); iter++) {
        if (newItem < *iter) {
            list.insert_before(iter, newItem);
            return;
        }
    }
    list.push_back(newItem);
}

#endif /* ORDEREDLINKEDLIST_H_ */
