#pragma once
#include <string>
struct EntryInt {
	int value;
	EntryInt* prev = nullptr;
	EntryInt* next = nullptr;
	~EntryInt() {
		printf("Je suis delete\n");
	}
};

class LinkedListInt {
public:
	EntryInt* root = nullptr;
	void insert(int val);
	void remove(int val);
	void print();
};

static void testLinkedList() {
	LinkedListInt toto;
	toto.insert(666);
	int here0 = 0;
	toto.insert(667);
	toto.print();
	toto.remove(666);
	toto.print();
	int here1 = 0;
}