#include <exception>

#include "IndexedList.h"

#include <stdexcept>

#include "ListIterator.h"

IndexedList::IndexedList() {
    capacity = 2;
    sizeForElemsArray = 0; //
    elemsArray = new TElem[capacity];
    nextIndexArray = new int[capacity];
    headIndex = 0;
    firstEmpty = 0;
}

int IndexedList::size() const {
    return sizeForElemsArray;
    //or iterate
}


bool IndexedList::isEmpty() const {
    //TODO - Implementation
    return false;
}

TElem IndexedList::getElement(int pos) const {
    if (pos < 0 || pos >= capacity) {
        throw std::out_of_range("IndexedList::getElement");
    }
    int count = 0;
    int currentIndex = headIndex;
    for (int i = 0; i < pos; i++) {

    }
}

TElem IndexedList::setElement(int pos, TElem e) {
    //TODO - Implementation
    return NULL_TELEM;
}

void IndexedList::addToEnd(TElem e) {
    //TODO - Implementation
}

void IndexedList::addToPosition(int pos, TElem e) {
    //TODO - Implementation
}

TElem IndexedList::remove(int pos) {
    //TODO - Implementation
    return NULL_TELEM;
}

int IndexedList::search(TElem e) const {
    //TODO - Implementation
    return 0;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() {
    //TODO - Implementation
}
