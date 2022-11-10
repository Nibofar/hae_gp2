#pragma once

template<typename Type>
class BinaryTree {
public:
	Type key;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	BinaryTree(Type val) {
		key = val;
	}
	BinaryTree* insert(Type val) {
		if (val < key) {
			if (left) left = left->insert(val);
			else {
				left = new BinaryTree(val);
				left->key = val;
			}
		}
		else {
			if (right) right = right->insert(val);
			else {
				right = new BinaryTree(val);
				right->key = val;
			}
		}
		return this;
	};
	BinaryTree* remove(Type val) {
		if (key == val) {
			auto oldLeft = left;
			auto oldRight = right;
			if (!oldRight && !oldLeft) {
				delete this;
				return nullptr;
			}
			else if (!oldRight) {
				delete this;
				return oldRight;
			}
			else if (!oldLeft) {
				delete this;
				return oldLeft;
			}
			if (left) {

			}
			return right;
		}
	};
	void print();
};
template<>
void BinaryTree<std::string>::print() {
	if (left)
		left->print();
	std::cout << key << " ";
	if (right)
		right->print();
}
template<typename Type>
void BinaryTree<Type>::print() {
	if (left)
		left->print();
	std::cout << std::to_string(key) << " ";
	if (right)
		right->print();
}
template<typename Type>
class BinaryTreeController {
	BinaryTree<Type>* trunk = nullptr;
	void insert(Type val){
		if (!trunk) trunk = new BinaryTree(val);
		else trunk->insert(val);
	}
	void remove(Type val) {

	}
	void print() {
		if (trunk) {
			trunk->print();
			std::cout << "\n";
		}
		else std::cout << "[]\n";
	}
};
typedef BinaryTreeController<int> ti;
typedef BinaryTreeController<float> tf;
typedef BinaryTreeController<std::string> ts;
static void testTree(){
	BinaryTree<int> bti(66);
	BinaryTree<std::string> bts("sapin");

	bti.insert(4);
	bti.print();
}