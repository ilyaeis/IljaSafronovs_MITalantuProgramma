#include <iostream>
using namespace std;

int main() {
	int num1, num2;

	int *ptr1 = &num1;
	int *ptr2 = &num2;

	cout << endl;

	cout << "In the begining:" << endl;
	cout << "Num: " << *ptr1 << "; memory address: " << ptr1 << endl;
	cout << "Num: " << num2 << "; memory address: " << ptr2 << endl;

	cout << endl;
	cout << "Ievadiet pirmo skaitli: ";
	cin >> num1;
	cout << "Ievadiet otro skaitli: ";
	cin >> *ptr2;

	cout << endl << "After user input:" << endl;
	cout << "Num: " << *ptr1 << "; memory address: " << ptr1 << endl;
	cout << "Num: " << num2 << "; memory address: " << ptr2 << endl;

	return 0;
}
