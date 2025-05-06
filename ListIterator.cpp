#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>
#include <stdexcept>
#include <iostream>
#include <assert.h>

ListIterator::ListIterator(const IndexedList &list) : list(list) {
    //currentIndex = list.headIndex;
    currentIndex = 2;
}

void ListIterator::first() {
    currentIndex = list.headIndex;
}

void ListIterator::next() {
    if (valid())  {
        currentIndex = list.nextIndexArray[currentIndex];
    }
    throw std::exception("Invalid pos");
}

bool ListIterator::valid() const {
    if (currentIndex >= 0 && currentIndex < list.size()
            && list.nextIndexArray[currentIndex] != -1) {
        return true;
    }
    return false;
}

TElem ListIterator::getCurrent() const {
    if (valid()) {
        return list.elemsArray[list.nextIndexArray[currentIndex]];
    }
    throw std::out_of_range("Iterator out of range");
}
