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
using namespace std;
static void assert(bool test) {
    if (!test) throw "assert";
}
void testC() {
    //cr�er un tableau de 150 �l�ments
    int array[150] = {};
    //le remplir de carr� successif
    for (int i = 0; i < 150; i++) {
        array[i] = i * i;
    }
    //l'afficher � l'envers
    for (int i = 149; i >= 0; i--) {
        cout << std::to_string(array[i]) << "\n";
    }
}
int main(){
    /*testVec();
    testStr();
    testArray();
    testLinkedList();*/
    //testBinaryTree();
    //testC();
    //testFloatArray();
    testStringTree();
}