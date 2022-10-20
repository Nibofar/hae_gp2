#pragma once
class IntTree {
public:
	int value = 0;
	IntTree* left = nullptr;
	IntTree* right = nullptr;
	IntTree* insert(int value);
	IntTree* remove(int value);
	void print();
};
class IntTreeController {
public:
	IntTree* root = nullptr;
	void insert(int val) {
		if (!root) {
			root = new IntTree();
			root->value = val;
		}
		else
			root = root->insert(val);
	}
	void remove(int val) {
		root = root->remove(val);
	}
	void print() {
		if (root)
			root->print();
	}
};
static void testBinaryTree() {
	IntTreeController tutu;
	tutu.print();
	tutu.insert(773);
	tutu.print();
	tutu.insert(127);
	tutu.print();
	tutu.remove(127);
	tutu.print();
	tutu.insert(542);
	tutu.print();
}