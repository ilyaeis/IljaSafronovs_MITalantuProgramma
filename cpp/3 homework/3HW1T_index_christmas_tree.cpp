#include <iostream>
#include <string>

int main() {
	int row;
	std::cout << "Ievadit rindu skaitu: ";
	std::cin >> row;

	for (int i = 1; i <= row; i++) {
		std::string str(i, '0' + i); // Creates str with i copies of i
		std::cout << str << std::endl;
	}
}