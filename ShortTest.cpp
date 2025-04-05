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

void testLaurentiu() {
    //IndexedList list = IndexedList();
    int capacity = 10;
    int elemsArray[capacity] = {1, 2, 3, 4};
    int next[capacity] = {-1, 3, 4, 1};
    int head = 2;
    int size = 0;
    int firstE = 0;

    IndexedList list2 = IndexedList(capacity, elemsArray, next, head, size, firstE);
    std::cout << list2.search(1) << std::endl;
}