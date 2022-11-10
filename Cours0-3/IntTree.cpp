#include "IntTree.hpp"
#include <stdio.h>
IntTree* IntTree::insert(int val) {
	if (val < value) {
		if (left)
			left = left->insert(val);
		else {
			left = new IntTree();
			left->value = val;
		}
	}
	else {
		if (right)
			right = right->insert(val);
		else {
			right = new IntTree();
			right->value = val;
		}
	}
	return this;
}
IntTree* IntTree::remove(int val) {
	if (value == val) {
		auto oldLeft = left;
		auto oldRight = right;
		if (!oldRight && !oldLeft) {
			delete this;
			return nullptr;
		}else if (!oldRight) {
			delete this;
			return oldRight;
		}else if (!oldLeft) {
			delete this;
			return oldLeft;
		}
		while (left) {
			auto lval = left->value;
			left = left->remove(lval);
			right->insert(lval);
		}
		return right;
	}
	if (left && (val <= value)) {
		left = left->remove(val);
	}
	if (right && (val >= value)) {
		right = right->remove(val);
		return right;
	}
	return this;
}
void IntTree::print() {
	if (left)
		left->print();
	printf("%d ", value);
	if (right)
		right->print();
}