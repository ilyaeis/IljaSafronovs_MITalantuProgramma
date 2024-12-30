#include <iostream>

struct Data {
    int age;
    char chr;
};

void printByValue(Data obj) {
    std::cout << "Age: " << obj.age << ", Char: " << obj.chr << std::endl;
}

void printByPointer(Data *ptrObj) {
    if (ptrObj) {
        std::cout << "Age: " << ptrObj->age << ", Char: " << ptrObj->chr << std::endl;
    }
}

void printByReference(Data &obj) {
    std::cout << "Age: " << obj.age << ", Char: " << obj.chr << std::endl;
}

int main() {
	Data obj = { 25, 'a' };
	printByValue(obj);
	printByPointer(&obj);
	printByReference(obj);
	return 0;
}
