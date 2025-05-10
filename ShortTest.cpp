#include <assert.h>
#include <exception>

#include "ShortTest.h"

#include <iostream>
#include <ostream>

#include "IndexedList.h"
#include "ListIterator.h"

void testAll() {
    IndexedList list = IndexedList();
    assert(list.isEmpty());
    list.addToEnd(1);
    assert(list.size() == 1);
    list.addToPosition(0,2);
    assert(list.size() == 2);
    ListIterator it = list.iterator();
    assert(it.valid());
    it.next();
    assert(it.getCurrent() == 1);
    it.first();
    assert(it.getCurrent() == 2);
    assert(list.search(1) == 1);
    assert(list.setElement(1,3) == 1);
    assert(list.getElement(1) == 3);
    assert(list.remove(0) == 2);
    assert(list.size() == 1);
}

void testOp() {
    IndexedList list10 = IndexedList();
    IndexedList list11 = IndexedList();

    list10.addToEnd(1);
    list10.addToEnd(2);
    list11.addToEnd(1);
    list11.addToEnd(2);

    assert((list10 == list11) == true);

    std::cout<<"t"<<std::endl;

}

void testOp1() {
    IndexedList list20 = IndexedList();
    IndexedList list21 = IndexedList();

    list20.addToEnd(1);
    list20.addToEnd(3);
    list21.addToEnd(2);
    list21.addToEnd(2);

    assert((list20 == list21) == false);
    std::cout<<"t1"<<std::endl;
}

void testOp3() {
    IndexedList list30 = IndexedList();
    IndexedList list31 = IndexedList();

    list30.addToEnd(1);
    list30.addToEnd(2);
    list30.addToEnd(3);
    list31.addToEnd(1);
    list31.addToEnd(2);

    assert((list30 == list31) == false);
    std::cout<<"t3"<<std::endl;
}