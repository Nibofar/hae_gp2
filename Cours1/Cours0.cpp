#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
struct vec2 {
    float x = 0;
    float y = 0;
    vec2(){}
    vec2(float _x, float _y) {
        x = _x;
        y = _y;
    }
    void add(vec2 v) {
        x += v.x;
        y += v.y;
    }
    void addRef(vec2& v) {
        x += v.x;
        y += v.y;
    }
    void addPtr(vec2* v) {
        x += v->x;
        //x += (*v).x;
        y += v->y;
    }
};
struct vec3 : public vec2 {
    float z = 0;
    vec3(){}
    vec3(float _x, float _y, float _z) : vec2(_x, _y) {
        z = _z;
    }
    void add(vec3 v) {
        vec2::add(v);
        z += v.z;
    }
    void addRef(vec3& v) {
        vec2::addRef(v);
        z += v.z;
    }
    void addPtr(vec3* v) {
        vec2::addPtr(v);
        z += v->z;
    }
};
struct vec4 {
    float w = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    vec4(){}
    vec4(float _w, float _x, float _y, float _z) {
        w = _w;
        x = _x;
        y = _y;
        z = _z;
    }
    vec4 add(const vec4& v) {
        return vec4(w + v.w, x + v.w, y + v.y, z + v.z);
    }
    vec4 sub(const vec4& v) {
        return vec4(w - v.w, x - v.w, y - v.y, z - v.z);
    }
    vec4 mul(const vec4& v) {
        return vec4(w * v.w, x * v.x, y * v.y, z * v.z);
    }
    vec4 div(const vec4& v) {
        return vec4(w / v.w, x / v.x, y / v.y, z / v.z);
    }
    void incr(const vec4& v) {
        w += v.w;
        x += v.x;
        y += v.y;
        z += v.z;
    }
};
struct truc {
    float maVariable;
    float foo(){}
};
void foo(truc t);
void foo(truc* t);
void foo(truc& t);
class IntArray {
public:
    IntArray(int maxSize) {
        data = new int[maxSize];
        //data = (int*) malloc(maxSize*sizeof(int));
        size = maxSize;
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
        //alloue data
        //change la taille réelle
    }
    void resize(int nuSize) {
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
    ~IntArray() {
        delete[] data;
        size = 0;
    }
    //invariant : mon tableau est trié
    void insertOrderInferior(int val) {
        //agrandir de 1
        resize(getSize() + 1);
        //trouver l'endroit d'insertion
        int idx = searchOrderInferior(val);
        //décaller de 1 vers la droite à l'endroit d'insertion
        for (int i = getSize() - 1; i > idx; i--) {
            set(i, get(i - 1));
        }
        //insérer la nouvelle valeur
        set(idx, val);
    }
    int get(int idx) {
        if (idx < 0) throw "out of bound exception, bound cannont be less than 0";
        if (idx > size) throw "out of bound exception, bound cannont be more than " + size;
        return(data[idx]);
    }
    int getSize() {
        return size;
    }
    void set(int idx, int value) {
        if (idx < 0) throw "out of bound exception, bound cannont be less than 0";
        if (idx > size) throw "out of bound exception, bound cannont be more than " + size;
        data[idx] = value;
    }
protected:
    int* data = nullptr;
    int size = 0;
};
static void assert(bool test) {
    if (!test) throw "assert";
}
/*['s'][][][][][0] <- fin de chaîne de caractère
\0 ~= '0'
0
char => int sur 8 bit*/
int Strlen(const char* str) {
    int idx = 0;
    while (str[idx] != 0) idx++;
    return idx;
}
int Strlen2(const char* str) {
    const char* start = str;
    while (str != 0) str++;
    return str - start;
}
int Strlen3(const char* str) {
    const char* start = str;
    while (*str) str++;
    return str - start;
}
int Countc(const char* str, char c) {
    int size = Strlen(str);
    int nbr = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] == c) nbr++;
    }
    return nbr;
}
void Strcpy(char* dst, const char* src) {
    while (*src) {
        *dst = *src;
        dst++;
        src++;
    }
}
void Strcpy2(char* dst, const char* src) {
    int idx = 0;
    while (src[idx]) {
        dst[idx] = src[idx];
        idx++;
    }
}
void Strcpy3(char* dst, const char* src) {
    int size = Strlen(src);
    for (int i = 0; i < size; i++) dst[i] = src[i];
}
int main()
{
    /*vec3 sapin;

    vec3 v0(6, 7, 2);
    vec3 v1(7, 7, 3);

    v1.add(v0);
    v1.addRef(v0);
    v1.addPtr(&v0);

    vec4 v0(2, 7, 1, 3);
    vec4 v1(7, 7, 3, 9);
    vec4 test;
    test = v1.add(v0);
    if (test.w != 9) throw "fail";
    test = v1.sub(v0);
    if (test.w != 5) throw "fail";
    test = v1.mul(v0);
    if (test.w != 14) throw "fail";
    test = v1.div(v0);
    if (test.w != 3.5f) throw "fail";
    v1.incr(v0);
    if (v1.w != 9) throw "fail";

    vec4* r0 = new vec4();
    vec4* r1 = new vec4();
    vec4* r2 = nullptr;
    vec4* r3 = new vec4[16];
    r3[4].incr(vec4(666, 0, 0, 0));
    auto r34 = r3[4];
    auto r34bis = *(r3 + 4);

    IntArray mitsu(3);
    mitsu.set(0, 2);
    mitsu.set(1, 4);
    mitsu.set(2, 8);
    assert(mitsu.get(1) == 4);
    mitsu.resize(1);
    mitsu.resize(3);
    assert(mitsu.get(1) == 0);

    char yottsu[] = "v3";
    char itsutsu[] = "despair";
    int test = Countc(yottsu, '3');
    Strcpy3(yottsu, itsutsu);*/

    IntArray muttsu(8);
    for (int i = 0; i < 8; i++) {
        muttsu.set(i, i * i);
    }
    muttsu.insertOrderInferior(21); // order sur A par le prédicat f : a[i] < a[i+1]

    int here = 0;
}