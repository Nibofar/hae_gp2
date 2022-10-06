#include <iostream>
#include <string>
#include <unordered_map>
#include "IntArray.hpp"
#include "Vec.hpp"
#include "Str.hpp"
using namespace std;
static void assert(bool test) {
    if (!test) throw "assert";
}
int main()
{
    testVec();
    testStr();
    testArray();
    int here = 0;
}