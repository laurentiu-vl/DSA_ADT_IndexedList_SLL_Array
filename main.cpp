#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main(){
    testAll();
    testOp1();
    //testOp2();
    testOp3();
    testAllExtended();

    cout<<"Finished LI Tests!"<<endl;
}