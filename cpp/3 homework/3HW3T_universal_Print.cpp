#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>

template <typename T>
void Print(std::vector<T> vec) {
	std::cout << "Vector:" << std::endl;
	for (T i : vec) {
		std::cout << i << " ";
	} std::cout << std::endl;
}

template <typename T>
void Print(std::list<T> lst) {
	std::cout << "List:" << std::endl;
	for (T i : lst) {
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
void Print(std::set<T> st) {
	std::cout << "Set:" << std::endl;
	for (T i : st) {
		std::cout << i << " ";
	} std::cout << std::endl;
}

template <typename K, typename V>
void Print(std::map<K, V> mp) {
	std::cout << "Map:" << std::endl;
	for (auto it = mp.cbegin(); it != mp.cend(); ++it) {
		std::cout << it->first << " : " << it->second << std::endl;
	} 
}

int main() {
	// Vector
	std::vector<int> vec = { 5, 1, 4, 2, 3 };
	Print(vec);

	// List
	std::list<int> lst = { 5, 1, 4, 2, 3 };
	Print(lst);

	// Stack
	std::stack<int> stk;
	stk.push(5);
	stk.push(1);
	stk.push(4);
	stk.push(2);
	stk.push(3);
	Print(stk);

	// Set
	std::set<int> st = { 5, 1, 4, 2, 3 };
	Print(st);

	// Map
	std::map<int, int> mp = { {5, 1}, {1, 2}, {4, 3}, {2, 4}, {3, 5} };
	Print(mp);

	return 0;
}