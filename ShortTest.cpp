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
    IndexedList list = IndexedList();
    IndexedList list2 = IndexedList();

    list.addToEnd(1);
    list.addToEnd(2);
    list2.addToEnd(1);
    list2.addToEnd(2);

    assert((list == list2) == true);

    std::cout<<"t1"<<std::endl;

}

void testOp1() {
    IndexedList list = IndexedList();
    IndexedList list2 = IndexedList();

    list.addToEnd(1);
    list.addToEnd(3);
    list2.addToEnd(2);
    list2.addToEnd(2);

    assert((list == list2) == false);
    std::cout<<"t2"<<std::endl;
}

void testOp3() {
    IndexedList list = IndexedList();
    IndexedList list2 = IndexedList();

    list.addToEnd(1);
    list.addToEnd(2);
    list.addToEnd(3);
    list2.addToEnd(1);
    list2.addToEnd(2);

    assert((list == list2) == false);
    std::cout<<"t3"<<std::endl;
}