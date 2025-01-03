#include <iostream>

struct Data {
	int age;
	char chr;

	Data(int age = 0, char chr = 0) {
		this->age = age;
		this->chr = chr;
	}
};

void printByValue(Data obj) {
	std::cout << "Age: " << obj.age << ", Char: " << obj.chr << std::endl;
}

void printByPointer(Data* ptrObj) {
	if (ptrObj) {
		std::cout << "Age: " << ptrObj->age << ", Char: " << ptrObj->chr << std::endl;
	}
	else {
		std::cout << "Pointer is null" << std::endl;
	}
}

void printByReference(Data& obj) {
	std::cout << "Age: " << obj.age << ", Char: " << obj.chr << std::endl;
}

int main() {
	Data obj;
	Data* pointer = nullptr;
	Data* objPointer = &obj;

	printByValue(obj);
	printByPointer(pointer);
	printByPointer(objPointer);
	printByReference(obj);

	std::cout << std::endl;

	obj = { 20, 'A' };
	objPointer = &obj;

	printByValue(obj);
	printByPointer(objPointer);
	printByReference(obj);
	return 0;
}
