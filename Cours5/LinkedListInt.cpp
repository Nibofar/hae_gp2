#include "LinkedListInt.hpp"
#include <string>
void LinkedListInt::insert(int val){
	//Crée une EntryInt pour la valeur
	EntryInt * nuVal = new EntryInt;
	nuVal->value = val;
	//Si il y a une root, l'a lier
	//Sinon Installer la root
	if (!root) {
		root = nuVal;
	}else{
		auto oldRoot = root;
		root = nuVal;
		oldRoot->prev = root;
		root->next = oldRoot;
	}
}
void LinkedListInt::remove(int val){
	auto cur = root;
	while (cur) {
		if (cur->value == val) {
			if (cur->prev) cur->prev->next = cur->next;
			else root = cur->next;
			if (cur->next)cur->next->prev = cur->prev;
			delete cur;
			break;
		}
		cur = cur->next;
	}
}
void LinkedListInt::print(){
	auto cur = root;
	while (cur) {
		printf("%d, ", cur->value);
		cur = cur->next;		
	}
	printf("\n");
}
