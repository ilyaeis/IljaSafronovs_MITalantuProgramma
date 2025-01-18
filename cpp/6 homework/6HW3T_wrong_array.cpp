#include <iostream>
using namespace std;

void printArr(int *arr, int *length) {
	cout << "Array data:" << endl;
	cout << "Value\tAddress" << endl;
	for (int *i = arr; i < arr + *length; i++) {
		cout << *i << "\t" << i << endl;
	}
}

void get_in_between(int *first, int *second) {
	cout << "Number(s) in between should be: ";
	int *i = first;
	(*i)++;
	for (; *i < *second; (*i)++) {
		cout << *i << " ";
	}
	cout << endl;
}

void checkIfCorrect(int *arr, int *length) {
	if (*arr != 1) {
		cout << "The order is wrong in this array, because first element at address " << arr
			 << " is not 1!" << endl;
		int *num = new int;
		*num = 0;
		get_in_between(num, arr);
		delete num;
		return;
	}
	for (int *i = (arr + 1); i < arr + *length; i++) {
		if (*(i) - *(i - 1) != 1) {
			cout << "The order is wrong in this array, between value "
				 << *(i - 1) << " at address " << (i - 1)
				 << " and value " << *i << " at address " << i << endl;
			get_in_between(i - 1, i);
			return;
		}
	}
	cout << "The order is correct in this array!" << endl;
}

int main() {
	cout << endl;

	int *length = new int;
	*length = 9;
	int *arr = new int[*length]{4, 5, 6, 7, 8, 9, 10, 11, 12};

	printArr(arr, length);
	checkIfCorrect(arr, length);

	delete[] arr;

	cout << endl;

	*length = 2;
	arr = new int[*length]{1, 5};

	printArr(arr, length);
	checkIfCorrect(arr, length);

	delete[] arr;

	cout << endl;

	*length = 4;
	arr = new int[*length]{2, 3, 4, 5};

	printArr(arr, length);
	checkIfCorrect(arr, length);

	delete[] arr;

	cout << endl;

	*length = 5;
	arr = new int[*length]{1, 2, 3, 4, 5};

	printArr(arr, length);
	checkIfCorrect(arr, length);

	delete[] arr;
	delete length;

	return 0;
}
