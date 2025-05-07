#include "ListIterator.h"
#include "IndexedList.h"
#include <stdexcept>

ListIterator::ListIterator(const IndexedList &list) : list(list) {
    //best theta 1, worst theta 1, avg theta 1
    currentIndex = list.headIndex;
}

void ListIterator::first() {
    //best theta 1, worst theta 1, avg theta 1
    currentIndex = list.headIndex;
}

void ListIterator::next() {
    //best theta 1, worst theta 1, avg theta 1
    if (valid()) {
        currentIndex = list.nextIndexArray[currentIndex];
    } else {
        throw std::out_of_range("Invalid pos");
    }
}

bool ListIterator::valid() const {
    //best theta 1, worst theta 1, avg theta 1
    if (currentIndex != -1) {
        return true;
    }
    return false;
}

TElem ListIterator::getCurrent() const {
    //best theta 1, worst theta 1, avg theta 1
    if (valid()) {
        return list.elemsArray[currentIndex];
    } else {
        throw std::out_of_range("Invalid pos");
    }
}
