#pragma once
#include <cstdlib>
#include <functional>
class FloatArray {
public:
    FloatArray(int nb) {
        data =(float*) malloc(nb * sizeof(float));
        allocSize = nb;
        for (int i = 0; i < allocSize; i++) data[i] = 0;
    }
    ~FloatArray() {
        free(data);
    }
    void resize(int sz) {
        if (sz < allocSize) return;
        data = (float*)realloc(data, sz * sizeof(float));
        for (int i = allocSize; i < sz; i++) data[i] = 0;
        allocSize = sz;
    }
    void setSize(int nuSize) {
        current = nuSize;
    }
    float get(int idx) {
        if (idx < 0) throw "out of bound exception";
        if (idx > current) throw "out of bound exception";
        return(data[idx]);
    }
    void set(int idx, float value) {
        if (idx < 0) throw "out of bound exception";
        if (idx >= current) throw "out of bound exception";
        data[idx] = value;
    }
    void iter(std::function<void(float)> f) {
        for (int i = 0; i < size(); i++) {
            f(data[i]);
        }
    }
    void pushFirst(float val) {
        resize(allocSize + 1);
        for (int i = size(); i > 0; i--) {
            data[i] = data[i - 1];
        }
        data[0] = val;
        current++;
    }
    void pushBack(float val) {
        resize(allocSize + 1);
        data[current] = val;
        current++;
    }
    int size() {
        return current;
    }
protected:
    float* data = nullptr;
    int allocSize = 0;
    int current = 0;
};
void testFloatArray(){
    FloatArray array(5);
    array.setSize(5);
    array.set(0, 3.5f);
    array.set(1, 2.7f);
    array.set(2, 5.4f);
    array.set(3, 1.1f);
    array.set(4, 3.9f);
    array.pushBack(7.3f);
    array.pushFirst(2.3f);
    auto printFonction = [](float val) {
        printf("%f ", val);
    };
    array.iter(printFonction);
    float totalSum = 0;
    auto sumFonction = [&totalSum](float val) {
        totalSum += val;
    };
    array.iter(sumFonction);
    printf("%f", totalSum);

}