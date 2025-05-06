#include <exception>

#include "IndexedList.h"

#include <ranges>
#include <stdexcept>
#include <exception>

#include "ListIterator.h"

using namespace std;

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
    //return sizeForElemsArray;
    int count = 0;
    int currentIndex = headIndex;

    while(currentIndex != -1) {
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
        if (count + 1 == pos) {
            return elemsArray[currentIndex];
        }
        currentIndex = nextIndexArray[currentIndex];
        count++;
    }
    //return elemsArray[currentIndex];
}

TElem IndexedList::setElement(int pos, TElem e) {
    if (pos < 1) {
        throw std::out_of_range("Invalid position");
    }
    
    int currentPos = 1;
    int currentIndex = headIndex;

    while(nextIndexArray[currentIndex] != -1) {
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

    TElem newElem = firstEmpty;
    firstEmpty = nextIndexArray[firstEmpty];
    elemsArray[newElem] = e;
    nextIndexArray[newElem] = -1;

    if (headIndex == -1) {
        headIndex = newElem;
    } else {
        int currentIndex = headIndex;

        while(nextIndexArray[currentIndex] != -1) {
            currentIndex = nextIndexArray[currentIndex];
        }

        nextIndexArray[currentIndex] = newElem;
    }
}

void IndexedList::addToPosition(int pos, TElem e) {
    // if (pos < 1) {
    //     throw std::out_of_range("Invalid position");
    // }

    if (firstEmpty == -1) {
        resizeUp();
    }

    TElem newElem = firstEmpty;
    firstEmpty = nextIndexArray[firstEmpty];
    elemsArray[newElem] = e;
    nextIndexArray[newElem] = -1;

    if (pos == 1) {
        if (headIndex == -1) {
            headIndex = newElem;
        } else {
            nextIndexArray[newElem] = headIndex;
            headIndex = newElem;
        }
    } else {
        int currentPos = 1;
        int currentIndex = headIndex;

        while(currentIndex != -1 && currentPos < pos - 1) {
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
    int newCap = capacity * 2;
    TElem* newElemsArray = new int[newCap];
    int* newNextIndexArray = new int[newCap]; 

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
