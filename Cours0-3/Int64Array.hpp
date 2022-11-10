#pragma once
#include <cstdint>
#include <cstdlib>
#include "Lib.hpp"
class Int64Array {
public:
	int64_t* data = nullptr;
	int allocSize = 0;
	int cursor = 0;
	Int64Array(int _allocSize) {
		if (_allocSize <= 0) _allocSize = 16;
		data = (int64_t*)malloc(_allocSize * sizeof(int64_t));
		setZero(0, _allocSize);
		cursor = 0;
		allocSize = _allocSize;
	}
	~Int64Array() {
		free(data);
		data = nullptr;
	}
	int size() {
		return cursor;
	}
	void ensure(int len);
	void push_back(int64_t val) {
		ensure(cursor + 1);
		data[cursor] = val;
		cursor++;
	}
	void push_front(int64_t val) {
		ensure(allocSize + 1);
		shift(cursor, 0);
		set(0, val);
		cursor++;
	}
	void shift(int idx, int obj) {
		if (idx <= obj) return;
		data[idx] = data[idx - 1];
		shift(idx - 1, obj);
	}
	void shiftLeft(int idx) {
		if (idx < 0 || idx > cursor + 1) return;
		data[idx] = data[idx + 1];
		shiftLeft(idx++);
	}
	/*void shiftRec(int idx) {
		if (idx >= allocSize || idx < 0) return;
		ensure(allocSize + 1);
		shiftLoop(idx);
	}
	void shiftLoop(int idx) {
		if (!data[idx]) return;
		data[allocSize - idx]= data[allocSize - idx - 1];
		shiftLoop(idx++);
		return;
	}*/
	void print(int start = 0);
	void insert(int idx, int64_t val) {
		ensure(allocSize + 1);
		shift(cursor, idx);
		data[idx] = val;
		cursor++;
	}
	void set_unsafe(int pos, int64_t elem) {
		data[pos] = elem;
	}
	void set(int idx, int val) {
		if (idx < 0 || idx > allocSize) return;
		data[idx] = val;
	}
	/*void fillWithRandom(int nbElem) {
		if (nbElem <= 0) return;
		push_front(Lib::rand() * Lib::rand() * Lib::rand() * Lib::rand());
		fillWithRandom(nbElem - 1);
	}*/
	int searchPosition(int64_t elem, int idx = 0) { //renvoyer la position d’insertion
		if (idx > cursor) return -1;
		if (data[idx] == elem) return idx;
		return searchPosition(elem, idx++);
	}
	int64_t get() {

	}
	void removeFirst() {
		shiftLeft(0);
	}
	void removeOne() {
		shiftLeft(1);
	}
	void removeAt(int elem) {
		int temp = searchPosition(elem);
		if (temp >= 0) shiftLeft(temp);
	}
	int findOrderedPos(int64_t elem) {
		return -1;
	}
	void addOneElementIsASortedArray(int pos, Int64Array& in) {

	}
	static Int64Array* sort(Int64Array& ref) {
		if (ref.size() == 0) return new Int64Array(1);
		auto res = new Int64Array(ref.size());
		ref.addOneElementIsASortedArray(0, *res);
		return res;
	}
	static int compare(const void* a, const void* b) {
		int64_t c = *(int64_t*)a - *(int64_t*)b;
		if (c < 0) return -1;
		else if (c > 0) return 1;
		else return 0;
	}
	void stdQsort() {
		qsort(data, cursor, sizeof(int64_t), compare);
	}
	int bsearchRec(int64_t target, int start, int end) {
		if (start < 0 || end < 0 || start > cursor || end > cursor || start > end) return -1;
		int mid = (start + end) / 2;
		if (end == start && mid != target) return -1;
		if (data[mid] == target) return mid;
		else if (data[mid] < target) return bsearchRec(target, start, mid - 1);
		else return bsearchRec(target, mid + 1, end);
	}
	int linearSearch(int64_t target, int start, int end) {
		if (start < 0 || end < 0 || start > cursor || end > cursor || start > end) return -1;
		for (int i = start; i < end; i++) {
			if (data[i] == target) return i;
		}
		return -1;
	}
protected:
	void setZero(int start, int end) {
		if (start >= end) return;
		data[start] = 0;
		setZero(start + 1, end);
	}
};
static void testInt64Array() {
	Int64Array test(1);
	test.push_front(14);
	test.push_front(7);
	test.push_front(16);
	test.push_front(3);
	test.insert(3, 2);
	test.print();
	test.stdQsort();
	test.print();
	int idx = test.bsearchRec(3, 0, test.size());
	int here = 0;
}
/*static void testChrono() {
	auto st0 = Lib::getTimeStamp();
	int sz = 256;
	Int64Array t2(sz);
	t2.fillWithRandom(sz);
	Int64Array::insertionSort(t2);
	auto st1 = Lib::getTimeStamp();
	cout << to_string(st1 - st0) << "s \n";
	
	auto st20 = Lib::getTimeStamp();
	Int64Array t3(sz);
	t2.fillWithRandom(sz);
	t2.stdQsort()
	auto st2 = Lib::getTimeStamp();
	cout << to_string(st2 - st20) << "s \n";

	auto timing
}*/