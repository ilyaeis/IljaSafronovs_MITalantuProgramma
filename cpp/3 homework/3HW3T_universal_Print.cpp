#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>

template <typename T>
void Print(std::vector<T> v) {
	std::cout << "Vector:" << std::endl;
	for (T i : v) {
		std::cout << i << " ";
	} std::cout << std::endl;
}

template <typename T>
void Print(std::list<T> l) {
	std::cout << "List:" << std::endl;
	for (T i : l) {
		std::cout << i << " ";
	} std::cout << std::endl;
}

template <typename T>
void Print(std::stack<T> stk) {
	std::cout << "Stack:" << std::endl;
	while (!stk.empty()) {
		std::cout << stk.top() << " ";
		stk.pop();
	} std::cout << std::endl;
}

template <typename T>
void Print(std::set<T> s) {
	std::cout << "Set:" << std::endl;
	for (T i : s) {
		std::cout << i << " ";
	} std::cout << std::endl;
}

template <typename K, typename V>
void Print(std::map<K, V> m) {
	std::cout << "Map:" << std::endl;
	for (auto it = m.cbegin(); it != m.cend(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	} 
}

int main() {
	// Vector
	std::vector<int> v = { 5, 1, 4, 2, 3 };
	Print(v);

	// List
	std::list<int> l = { 5, 1, 4, 2, 3 };
	Print(l);

	// Stack
	std::stack<int> stk;
	stk.push(5);
	stk.push(1);
	stk.push(4);
	stk.push(2);
	stk.push(3);
	Print(stk);

	// Set
	std::set<int> s = { 5, 1, 4, 2, 3 };
	Print(s);

	// Map
	std::map<int, int> m = { {5, 1}, {1, 2}, {4, 3}, {2, 4}, {3, 5} };
	Print(m);

	return 0;
}