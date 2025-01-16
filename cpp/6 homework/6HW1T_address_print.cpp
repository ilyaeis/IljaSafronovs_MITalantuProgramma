#include <iostream>
using namespace std;

int main() {
	int *ptr1 = new int;
	int *ptr2 = new int;

	cout << endl;
	cout << "Ievadiet pirmo skaitli: ";
	cin >> *ptr1;
	cout << "Ievadiet otro skaitli: ";
	cin >> *ptr2;

	cout << endl
		 << "After user input:" << endl;
	cout << "Num: " << *ptr1 << "; memory address: " << ptr1 << endl;
	cout << "Num: " << *ptr2 << "; memory address: " << ptr2 << endl;

	delete ptr1;
	delete ptr2;

	return 0;
}
