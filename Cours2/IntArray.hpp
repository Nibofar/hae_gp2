#pragma once
#include <iostream>
#include <cstdlib>
class IntArray {
public:
    IntArray(int maxSize);
    void resize(int nuSize);
    ~IntArray();
    //invariant : mon tableau est trié
    void insertOrderInferior(int val);
    int searchOrderInferior(int val);
    //cette fonction casse l'invariant en inserant une sentence
    void shift(int idx);
    void sort();
    static int compare(const void* arg1, const void* arg2);
    bool isSorted();
    int get(int idx);
    int getSize();
    void set(int idx, int value);
protected:
    int* data = nullptr;
    int size = 0;
};
static void testArray() {
    IntArray muttsu(5);
    muttsu.set(0, 8);
    muttsu.set(1, 2);
    muttsu.set(2, 13);
    muttsu.set(3, 9);
    muttsu.set(4, 1);
    muttsu.sort();
    /*muttsu.insertOrderInferior(21); // order sur A par le prédicat f : a[i] < a[i+1]
    muttsu.insertOrderInferior(-4);
    muttsu.insertOrderInferior(54);*/
    //assert(muttsu.isSorted());
}