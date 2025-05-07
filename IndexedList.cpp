#include "IndexedList.h"

#include <ranges>
#include <stdexcept>
#include <exception>
#include <iostream>

#include "ListIterator.h"

using namespace std;

IndexedList::IndexedList() {
    capacity = 2;
    elemsArray = new int[capacity];
    nextIndexArray = new int[capacity];
    headIndex = -1;
    for (int i = 1; i < capacity - 1; i++) {
        nextIndexArray[i] = i + 1;
    }
    nextIndexArray[capacity] = -1;
    sizeForElemsArray = 0;
    firstEmpty = -1;
}

int IndexedList::size() const {
    int count = 0;
    int currentIndex = headIndex;

    while (currentIndex != -1) {
        count++;
        currentIndex = nextIndexArray[currentIndex];
    }
    return count;
}


bool IndexedList::isEmpty() const {
    if (headIndex == -1) {
        return true;
    } else {
        return false;
    }
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

    if (currentIndex == -1) {
        throw std::out_of_range("IndexedList::getElement");
    }

    return elemsArray[currentIndex];
}

TElem IndexedList::setElement(int pos, TElem e) {
    if (pos < 0) {
        throw std::out_of_range("Invalid position");
    }

    int currentPos = 0;
    int currentIndex = headIndex;

    while (nextIndexArray[currentIndex] != -1 && currentPos < pos) {
        currentPos++;
        currentIndex = nextIndexArray[currentIndex];
    }

    if (currentIndex == -1) {
        throw std::out_of_range("Invalid position");
    }

    TElem oldValue = elemsArray[currentIndex];
    elemsArray[currentIndex] = e;
    return oldValue;
}

void IndexedList::addToEnd(TElem e) {
    if (firstEmpty == -1) {
        resizeUp();
    }

    int newElem = firstEmpty;
    firstEmpty = nextIndexArray[firstEmpty];
    elemsArray[newElem] = e;
    nextIndexArray[newElem] = -1;

    if (headIndex == -1) {
        headIndex = newElem;
    } else {
        int currentIndex = headIndex;

        while (nextIndexArray[currentIndex] != -1) {
            currentIndex = nextIndexArray[currentIndex];
        }

        nextIndexArray[currentIndex] = newElem;
    }
}

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0) {
        throw std::out_of_range("Invalid position");
    }

    if (firstEmpty == -1) {
        resizeUp();
    }
    int newElem = firstEmpty;
    firstEmpty = nextIndexArray[firstEmpty];
    elemsArray[newElem] = e;
    nextIndexArray[newElem] = -1;

    if (pos == 0) {
        if (headIndex == -1) {
            headIndex = newElem;
        } else {
            nextIndexArray[newElem] = headIndex;
            headIndex = newElem;
        }
    } else {
        int currentPos = 0;
        int currentIndex = headIndex;

        while (currentIndex != -1 && currentPos < pos - 1) {
            currentPos++;
            currentIndex = nextIndexArray[currentIndex];
        }

        if (currentIndex != -1) {
            nextIndexArray[newElem] = nextIndexArray[currentIndex];
            nextIndexArray[currentIndex] = newElem;
        } else {
            throw std::out_of_range("Invalid position");
        }
    }
}

TElem IndexedList::remove(int pos) {
    //laurentiu
    if (pos < 0) {
        throw exception();
    }

    int currentIndex = headIndex;
    int previousIndex = -1;
    int currentPos = 0;

    while (currentIndex != -1 && currentPos < pos) {
        previousIndex = currentIndex;
        currentIndex = nextIndexArray[currentIndex];
        currentPos++;
    }

    if (currentIndex == -1) {
        throw exception();
    }

    TElem removedElem = elemsArray[currentIndex];

    if (previousIndex == -1) {
        headIndex = nextIndexArray[currentIndex];
    } else {
        nextIndexArray[previousIndex] = nextIndexArray[currentIndex];
    }

    nextIndexArray[currentIndex] = firstEmpty;
    firstEmpty = currentIndex;

    return removedElem;
}

int IndexedList::search(TElem e) const {
    //laurentiu
    int currentIndex = headIndex;
    bool found = false;
    int pos = 0;
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

IndexedList::~IndexedList() {
    //laurentiu
    delete[] nextIndexArray;
    delete[] elemsArray;
}

void IndexedList::resizeUp() {
    int newCap = capacity * 2;
    TElem *newElemsArray = new int[newCap];
    int *newNextIndexArray = new int[newCap];

    for (int i = 0; i < capacity; i++) {
        newElemsArray[i] = elemsArray[i];
        newNextIndexArray[i] = nextIndexArray[i];
    }

    for (int i = capacity; i < newCap - 1; i++) {
        newNextIndexArray[i] = i + 1;
    }

    newNextIndexArray[newCap - 1] = -1;

    delete[] elemsArray;
    delete[] nextIndexArray;

    elemsArray = newElemsArray;
    nextIndexArray = newNextIndexArray;
    firstEmpty = capacity;
    capacity = newCap;
}

void IndexedList::resizeDown() {
}

void IndexedList::debugPrint() const {
    std::cout << "HEAD: " << headIndex << "\n";
    int idx = headIndex;
    while (idx != -1) {
        std::cout << "[" << idx << "] " << elemsArray[idx] << " → ";
        idx = nextIndexArray[idx];
    }
    std::cout << "NULL\n";
}
