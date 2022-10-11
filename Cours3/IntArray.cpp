#include "IntArray.hpp"
IntArray::IntArray(int maxSize){
    data = new int[maxSize];
    size = maxSize;
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}
int IntArray::get(int idx) {
    if (idx < 0) throw "out of bound exception, bound cannont be less than 0";
    if (idx > size) throw "out of bound exception, bound cannont be more than " + size;
    return(data[idx]);
}
int IntArray::getSize() {
    return size;
}
void IntArray::set(int idx, int value) {
    if (idx < 0) throw "out of bound exception, bound cannont be less than 0";
    if (idx > size) throw "out of bound exception, bound cannont be more than " + size;
    data[idx] = value;
}
void IntArray::resize(int nuSize) {
    if (nuSize == size) return;
    bool grow = nuSize > size;
    auto ndata = new int[nuSize];
    for (int i = 0; i < nuSize; i++) {
        ndata[i] = 0;
    }
    int targetSize = (grow) ? size : nuSize;
    for (int i = 0; i < targetSize; i++) {
        ndata[i] = data[i];
    }
    int* odata = data;
    data = ndata;
    size = nuSize;
    delete[]odata;
}
IntArray::~IntArray() {
    delete[] data;
    size = 0;
}
void IntArray::insertOrderInferior(int val) {
    //trouver l'endroit d'insertion
    int idx = searchOrderInferior(val);
    //agrandir de 1
    resize(getSize() + 1);
    //décaller de 1 vers la droite à l'endroit d'insertion
    shift(idx);
    //insérer la nouvelle valeur
    set(idx, val);
}
int IntArray::searchOrderInferior(int val) {
    int idx = 0;
    while (data[idx] <= val && (idx < size)) {
        idx++;
    }
    return idx;
}
void IntArray::shift(int idx) {
    if (idx >= size || idx < 0) return;
    for (int i = size - 1; i > idx; i--) {
        data[i] = data[i - 1];
    }
    set(idx, 0);
}
void IntArray::sort() {
    qsort(data, size, sizeof(int), compare);
}
int IntArray::compare(const void* arg1, const void* arg2) {
    //return _stricmp(*(char**)arg1, *(char**)arg2);
    int a = *(int*)arg1;
    int b = *(int*)arg2;
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
bool IntArray::isSorted() {
    for (int i = 0; i < size - 1; i++) {
        if (data[i] > data[i + 1]) return false;
    }
    return true;
}