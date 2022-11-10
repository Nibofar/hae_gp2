#include <iostream>
#include <string>
#include <unordered_map>
#include "IntArray.hpp"
#include "Vec.hpp"
#include "Str.hpp"
#include "LinkedListInt.hpp"
#include "IntTree.hpp"
#include "FloatArray.hpp"
#include "StringTree.hpp"
#include "Lib.hpp"
#include "Int64Array.hpp"
#include "LinkedList.hpp"
using namespace std;
#include "BinaryTree.hpp"
static void assert(bool test) {
    if (!test) throw "assert";
}
void testC() {
    //créer un tableau de 150 éléments
    int array[150] = {};
    //le remplir de carré successif
    for (int i = 0; i < 150; i++) {
        array[i] = i * i;
    }
    //l'afficher à l'envers
    for (int i = 149; i >= 0; i--) {
        cout << std::to_string(array[i]) << "\n";
    }
}
int main(){
    /*testVec();
    testStr();
    testArray();
    testLinkedList();
    testBinaryTree();
    testC();
    testFloatArray();
    testStringTree();
    Lib::testLib();
    testInt64Array();
    testTemplateList();*/
    testTree();
}