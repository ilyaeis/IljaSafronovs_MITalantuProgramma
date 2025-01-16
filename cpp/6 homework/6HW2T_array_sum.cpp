#include <iostream>
using namespace std;

void printArr(int *arr, int *length) {
	cout << "Array data:" << endl;
	cout << "Value\tAddress" << endl;
	for (int* i = arr; i < arr + *length; i++) {
        cout << *i << "\t" << i << endl;
    }
}

int sumOfArray(int *arr, int *length) {
	int sum = 0;
	for (int* i = arr; i < arr + *length; i++) {
		sum += *i;
	}
	return sum;
}

int main() {
	int *length = new int;
	*length = 10;
	int *arr = new int[*length]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 11 };

	printArr(arr, length);
	cout << endl;
	
	int sum = sumOfArray(arr, length);
	cout << "Sum is " << sum << endl;
	return 0;
}
