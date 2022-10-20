#pragma once
#include <cstdint>
#include <cstdlib>
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
	void ensure(int len) {
		if (allocSize <= len) {
			int toAlloc = std::max<int>(allocSize * 1.5, len);
			data = (int64_t*)realloc(data, toAlloc * sizeof(int64_t));
			allocSize = toAlloc;
			setZero(cursor, allocSize);
		}
	}
	void push_back(int64_t val) {
		ensure(cursor + 1);
		data[cursor] = val;
		cursor++;
	}
	void push_front(int64_t val) {

	}
	void shift(int idx) {
		if (idx >= allocSize) return;


	}
	void insert(int idx, int64_t val) {

	}
	void set_unsafe(int pos, int64_t elem) {

	}
	void set(int idx, int val) {
		if (idx < 0 || idx > allocSize) return;
		data[idx] = val;
	}
	void multiSet() {

	}
protected:
	void setZero(int start, int end) {
		if (start >= end) return;
		data[start] = 0;
		setZero(start + 1, end);
	}
};
static void testInt64Array() {
	Int64Array test(5);

}