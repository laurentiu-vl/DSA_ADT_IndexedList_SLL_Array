#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <assert.h>

ListIterator::ListIterator(const IndexedList &list) : list(list) {
    currentIndex = 0;
}

void ListIterator::first() {
    //TODO - Implementation
}

void ListIterator::next() {
    //TODO - Implementation
}

bool ListIterator::valid() const {
    if (currentIndex >= 0 && currentIndex < list.size()
            && list.elemsArray[currentIndex] != -1) {
        return true;
    }
    return false;
}

TElem ListIterator::getCurrent() const {
    if (valid()) {
        return list.elemsArray[currentIndex];
    }
    throw std::out_of_range("Iterator out of range");
}
