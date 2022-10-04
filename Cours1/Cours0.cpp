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
struct arrayInt {
    void get(int idx) {

    }
    void set(int idx) {

    }
};
struct truc {
    float maVariable;
    float foo(){}
};
void foo(truc t);
void foo(truc* t);
void foo(truc& t);
int main()
{
    /*vec3 sapin;

    vec3 v0(6, 7, 2);
    vec3 v1(7, 7, 3);

    v1.add(v0);
    v1.addRef(v0);
    v1.addPtr(&v0);*/

    /*vec4 v0(2, 7, 1, 3);
    vec4 v1(7, 7, 3, 9);

    v1.add(v0);
    v1.sub(v0);
    v1.mul(v0);
    v1.div(v0);
    v1.incr(v0);*/
    int here = 0;
}
