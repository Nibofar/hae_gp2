template<typename T>
struct Node {
	T key = {};
	Node* next = nullptr;
	Node(T val) {
		key = val;
	};
	Node<T>* removeAll(T val) {
		if (val == key) {
			Node<T>* chain = next;
			delete this;
			return chain->removeAll(val);
		}
		else if (next) next = next->removeAll(val);
		return this;
	};
	Node<T>* removeOne(T val) {
		if (val == key) {
			Node<T>* chain = next;
			delete this;
			return chain;
		}
		else if (next) next = next->removeOne(val);
		return this;
	};
	Node<T>* push_back(T val) {
		if (next) next = next->push_back(val);
		else next = new Node<T>(val);
		return this;
	}
};
template<typename T>
class LinkedList {
public:
	Node<T>* head = nullptr;
	void push_back(T val) {
		if (!head) head = new Node<T>(val);
		else head = head->push_back(val);
	}
	void push_front(T val) {
		Node<T>* nuVal = new Node<T>(val);
		if (!head) head = nuVal;
		else {
			auto oldHead = head;
		    head = nuVal;
			oldHead->prev = head;
			head->next = oldHead;
		}
	}
	void removeAll(T val) {
		if (!head) return;
		head = head->removeAll(val);
	};

	void removeOne(T val) {
		if (!head) return;
		head = head->removeOne(val);
	};
	void print() {
		std::cout << ("[");
		auto cur = head;
		while (cur) {
			std::cout << std::to_string(cur->key);
			cur = cur->next;
			if (cur) std::cout << (" ");
		}
		std::cout << ("]\n");
	}
};
typedef LinkedList<int> IntList;
typedef LinkedList<float> FloatList;
static void testTemplateList() {
	IntList ti;
	Node<int> toto(66);
	Node<float> tata(66.0f);
	FloatList tf;
	ti.push_back(2);
	ti.push_back(9);
	ti.push_back(7);
	ti.print();
	tf.print();
	int here = 0;
}