#include "ListIterator.h"
#include "IndexedList.h"
#include <stdexcept>

ListIterator::ListIterator(const IndexedList &list) : list(list) {
    currentIndex = list.headIndex;
}

void ListIterator::first() {
    currentIndex = list.headIndex;
}

void ListIterator::next() {
    if (valid()) {
        currentIndex = list.nextIndexArray[currentIndex];
    } else {
        throw std::out_of_range("Invalid pos");
    }
}

bool ListIterator::valid() const {
    if (currentIndex != -1) {
        return true;
    }
    return false;
}

TElem ListIterator::getCurrent() const {
    if (valid()) {
        return list.elemsArray[currentIndex];
    } else {
        throw std::out_of_range("Invalid pos");
    }
}
