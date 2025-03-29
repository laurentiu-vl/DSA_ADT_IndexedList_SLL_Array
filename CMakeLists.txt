cmake_minimum_required(VERSION 3.30)
project(DSA_ADT_IndexedList_SLL_Array)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA_ADT_IndexedList_SLL_Array main.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
