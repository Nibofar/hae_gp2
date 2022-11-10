#pragma once
#include <string>
template<typename Type>
class BinaryTree {
public:
	Type key;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	BinaryTree(Type val) {
		key = val;
	}
	int size() {
		int sz = 1;
		if (left) sz += left->size();
		if (right) sz += right->size();
		return sz;
	}
	BinaryTree* insert(Type val) {
		if (val < key) {
			if (left) left = left->insert(val);
			else left = new BinaryTree(val);
		}
		else {
			if (right) right = right->insert(val);
			else right = new BinaryTree(val);
		}
		return this;
	};
	BinaryTree* remove(Type val) {
		if (key == val) {
			auto oldLeft = left;
			auto oldRight = right;
			delete this;
			if (!right && !left) return nullptr;
			else if (!oldRight)	return oldRight;
			else if (!oldLeft) return oldLeft;
			else while (left) {
				auto temp = left->key;
				left = left->remove(temp);
				right = right->insert(temp);
			}
			return right;
		}
		else if (left && (key <= val)) left = left->remove(val);
		else if (right && key >= val) right = right->remove(val);
		return this;
	};
	BinaryTree* search(Type val) {
		
	}
	void print();
};
template<>
void BinaryTree<string>::print() {
	if (left) left->print();
	cout << key << " ";
	if (right) right->print();
}
template<typename Type>
void BinaryTree<Type>::print() {
	if (left) left->print();
	cout << key << " ";
	if (right) right->print();
}
template<typename Type>
class BinaryTreeController {
	BinaryTree<Type>* trunk = nullptr;
	int size() {
		if (!trunk) return 0;
		return trunk->size();
	}
	void insert(Type val){
		if (!trunk) trunk = new BinaryTree(val);
		else trunk->insert(val);
	}
	void remove(Type val) {
		trunk = trunk->remove(val);
	}
	void print() {
		if (trunk) {
			trunk->print();
			cout << "\n";
		}
		else cout << "[]\n";
	}
};
typedef BinaryTreeController<int> ti;
typedef BinaryTreeController<float> tf;
typedef BinaryTreeController<string> ts;
static void testTree(){
	BinaryTree<int> bti(66);
	BinaryTree<std::string> bts("sapin");
	bti.insert(4);
	bti.insert(16);
	bti.insert(8);
	bti.insert(70);
	bti.print();
	bti.remove(16);
	bti.print();
	int here = 0;
}