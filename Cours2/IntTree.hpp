#pragma once
class BinaryTree {
public:
	int val = 0;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	BinaryTree* insert(int value);
	BinaryTree* remove(int value);
	void print();
};
static void testBinaryTree() {
	BinaryTree tutu;
	tutu.insert(773);
	tutu.insert(127);
	tutu.print();
	tutu.remove(127);
	tutu.print();
}