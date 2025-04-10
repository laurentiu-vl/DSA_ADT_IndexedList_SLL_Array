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

IndexedList::IndexedList(int capacity, int elemsArray[], int nextIndexArray[],
                                    int headIndex, int size, int firstE) {
    this->capacity = capacity;
    this->elemsArray = elemsArray;
    this->nextIndexArray = nextIndexArray;
    this->headIndex = headIndex;
    this->sizeForElemsArray = size;
    this->firstEmpty = firstE;
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
        if (count + 1 == pos) {
            return elemsArray[currentIndex];
        }
        currentIndex = nextIndexArray[currentIndex];
        count++;
    }
    //return elemsArray[currentIndex];
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
    if (pos < 0 || pos >= sizeForElemsArray) {
        throw std::out_of_range("IndexedList::remove");
    }

    int count = 0;
    TElem foundElem;
    int currentIndex = headIndex;
    int previousIndex = 0;

    //while (currentIndex != -1 && count < pos)
    while (count < pos) {
        // if (currentIndex == pos) {
        //     foundElem = elemsArray[currentIndex];
        // }
        previousIndex = currentIndex;
        currentIndex = nextIndexArray[currentIndex];
        count++;
    }
    foundElem = elemsArray[currentIndex];
    nextIndexArray[previousIndex] = nextIndexArray[currentIndex]; //prev pointeaza
    //la urmatorul de dupa currentIndex?

    nextIndexArray[currentIndex] = firstEmpty;
    firstEmpty = currentIndex;
    sizeForElemsArray--;

    return foundElem;
}

int IndexedList::search(TElem e) const { //laurentiu
    int currentIndex = headIndex;
    bool found = false;
    int pos = 1;
    while (currentIndex != -1 && e != NULL_TELEM) {
        if (e == elemsArray[currentIndex]) {
            found = true;
            break;
        }
        currentIndex = nextIndexArray[currentIndex];
        pos++;
    }
    if (found) {
        return pos;
    }
    return -1;
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() { //laurentiu
    delete[] nextIndexArray;
    delete[] elemsArray;
}

void IndexedList::resizeUp() {

}

void IndexedList::resizeDown() {

}
