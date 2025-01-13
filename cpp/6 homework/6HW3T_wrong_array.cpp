#include <iostream>
using namespace std;

void printArr(int* (&arr), int* length) {
	cout << "Array data:" << endl;
	cout << "Value\tAddress" << endl;
	for (int i = 0; i < *length; i++)
	{
		cout << *(arr + i) << "\t" << (arr + i) << endl;
	}
}

void checkIfCorrect(int* (&arr), int& length) {
	for (int* i = (arr + 1); i < arr + length; i++) {
		if (*(i)-*(i - 1) != 1) {
			cout << "The order is wrong in this array, between value "
				<< *(i - 1) << " at address " << (i - 1)
				<< " and value " << *i << " at address " << i << endl;
			return;
		}
	}
	cout << "The order is correct in this array!" << endl;
}

int main() {
	cout << endl;

	int length = 10;
	int* arr = new int[length] {1, 3, 3, 4, 5, 6, 7, 8, 9, 10};
	printArr(arr, &length);
	checkIfCorrect(arr, length);
	delete arr;
	
	cout << endl;

	length = 5;
	arr = new int[length] {1, 2, 3, 4, 5};
	printArr(arr, &length);
	checkIfCorrect(arr, length);
	delete arr;

	return 0;
}
