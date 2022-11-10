#pragma once
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
static void testStr() {
    IntArray mitsu(3);
    mitsu.set(0, 2);
    mitsu.set(1, 4);
    mitsu.set(2, 8);
    //assert(mitsu.get(1) == 4);
    mitsu.resize(1);
    mitsu.resize(3);
    //assert(mitsu.get(1) == 0);

    char yottsu[] = "v3";
    char itsutsu[] = "despair";
    int test = Countc(yottsu, '3');
    Strcpy3(yottsu, itsutsu);
}