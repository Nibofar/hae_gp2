#include <iostream>
#include <string>
#include <unordered_map>
#include "IntArray.hpp"
#include "Vec.hpp"
#include "Str.hpp"
#include "LinkedListInt.hpp"
using namespace std;
static void assert(bool test) {
    if (!test) throw "assert";
}
int main(){
    /*testVec();
    testStr();
    testArray();*/
    testLinkedList();
    int here = 0;
}