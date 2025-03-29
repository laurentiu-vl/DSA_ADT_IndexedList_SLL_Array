#pragma once
#include "IndexedList.h"

class ListIterator{
    //DO NOT CHANGE THIS PART
    friend class IndexedList;

    //11. ADT IndexedList – repräsentiert mithilfe einer SLLA

private:
    const IndexedList& list;
    //TODO - Representation

    ListIterator(const IndexedList& lista);
public:
    void first();
    void next();
    bool valid() const;
    TElem getCurrent() const;

};
