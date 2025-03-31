#include <exception>

#include "IndexedList.h"

#include <ranges>
#include <stdexcept>

#include "ListIterator.h"

IndexedList::IndexedList() {
    capacity = 2;
    elemsArray = new int[capacity];
    nextIndexArray = new int[capacity];
    headIndex = -1;
    sizeForElemsArray = 0;
    firstEmpty = -1;
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
    while (currentIndex != -1 && count < pos) {
        currentIndex = nextIndexArray[currentIndex];
        count++;
    }
    return elemsArray[currentIndex];
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

TElem IndexedList::remove(int pos) { //laurentiu
    //TODO - Implementation
    return NULL_TELEM;
}

int IndexedList::search(TElem e) const { //laurentiu
    int currentIndex = headIndex;
    bool found = false;
    while (currentIndex != -1 && e != NULL_TELEM) {
        if (e == elemsArray[currentIndex]) {
            found = true;
            break;
        }
        currentIndex = nextIndexArray[currentIndex];
    }
    if (found) {
        return elemsArray[currentIndex];
    }
    return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() { //laurentiu
    //TODO - Implementation
}

void IndexedList::resizeUp() {

}

void IndexedList::resizeDown() {

}
