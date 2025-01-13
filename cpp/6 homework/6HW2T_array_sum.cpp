#include <iostream>
using namespace std;

void printArr(int (&arr)[10]) {
	int length = sizeof(arr) / sizeof(int);

	cout << "Array data:" << endl;
	cout << "Value\tAddress" << endl;
	for (int i = 0; i < *(&length); i++)
	{
		cout << *(arr + i) << "\t" << (arr + i) << endl;
	}
}

int sumOfArray(int(&arr)[10]) {
	int sum = 0;
	for (int* i = arr; i < arr + 10; i++) {
		sum += *i;
	}
	return sum;
}

int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };
	printArr(arr);

	cout << endl;
	
	int sum = sumOfArray(arr);
	cout << "Sum is " << sum << endl;
	return 0;
}
