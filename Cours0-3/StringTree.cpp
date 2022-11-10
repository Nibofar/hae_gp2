#include "StringTree.hpp"
#include "Lib.hpp"
#include <iostream>
#include <cstring>
StringTree* StringTree::insert(std::string& val) {
	if (val < value) {
		if (left)
			left = left->insert(val);
		else {
			left = new StringTree();
			left->value = val;
		}
	}
	else {
		if (right)
			right = right->insert(val);
		else {
			right = new StringTree();
			right->value = val;
		}
	}
	return this;
}
StringTree* StringTree::remove(std::string& val) {
	if (value == val) {
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
StringTree* StringTreeController::searchString(std::string& val) {
	if (root) return root->searchString(val);
	else return nullptr;
}
StringTree* StringTree::searchString(std::string& val) {
	if (value == val) return this;
	if(left)
	if(value > val) {
		auto res = left->searchString(val);
		if (res) return res;
	}
	if (right)
	if(value < val) {
		auto res = right->searchString(val);
		if (res) return res;
	}
	return nullptr;
}
StringTree* StringTreeController::searchPattern(std::string& val) {
	if (root) return root->searchPattern(val);
	else return nullptr;
}
StringTree* StringTree::searchPattern(std::string& val) {
	auto sta = strstr(value.c_str(), val.c_str());
	if (sta) return this;
	if (left) {
		auto res = left->searchPattern(val);
		if (res) return res;
	}
	if (right) {
		auto res = right->searchPattern(val);
		if (res) return res;
	}
	return nullptr;
}
void StringTree::print() {
	if (left)
		left->print();
	std::cout << value << " ";
	if (right)
		right->print();
}
void StringTreeController::print() {
	if (root) {
		root->print();
		std::cout << "\n";
	}
	else std::cout << "[]\n";
}