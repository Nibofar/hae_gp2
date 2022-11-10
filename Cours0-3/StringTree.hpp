#pragma once
#include <string>
#include <iostream>
class StringTree {
public:
	std::string value;
	StringTree* left = nullptr;
	StringTree* right = nullptr;
	StringTree* insert(std::string& value);
	StringTree* remove(std::string& value);
	void print();
	StringTree* searchString(std::string& val);
	StringTree* searchPattern(std::string& val);
};
class StringTreeController {
public:
	StringTree* root = nullptr;
	void insert(std::string val) {
		if (!root) {
			root = new StringTree;
			root->value = val;
		}
		else root = root->insert(val);
	}
	void remove(std::string val) {
		root = root->remove(val);
	}
	void print();
	StringTree* searchString(std::string& val);
	StringTree* searchPattern(std::string& val);
};
static void testStringTree() {
	StringTreeController StringTree;
	std::string value1("Chiaki");
	std::string value2("Mashiro");
	std::string value3("Hifumi");
	std::string value4("MishaKyokaRyukoMaple");
	std::string searchS("Mashiro");
	std::string searchP("kaRyukoM");
	StringTree.insert(value1);
	StringTree.insert(value2);
	StringTree.insert(value3);
	StringTree.insert(value4);
	StringTree.print();
	//auto res = test.searchString(searchS);
	auto res = StringTree.searchPattern(searchP);
	if (res) std::cout << res->value;
	//test.remove("Test");
	//test.insert("Réusite");
	//test.print();
	int here = 0;
}