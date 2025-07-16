#pragma once
#include "IndexedList.h"

class ListIterator{
    //DO NOT CHANGE THIS PART
    friend class IndexedList;

private:
    //TODO - Representation
    /* 11. ADT IndexedList – repräsentiert mithilfe einer SLLA
    */
    const IndexedList& list;

    int currentIndex;

    ListIterator(const IndexedList& lista);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;
};
