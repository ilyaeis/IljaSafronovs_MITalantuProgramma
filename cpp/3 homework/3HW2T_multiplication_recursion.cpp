#include <iostream>
#include <string>

int multiply(int num) {
	if (num < 10) return num;
	else return (num % 10) * multiply(num / 10);
}

int main() {
	int num;
	std::cout << "Ievadit skaitli: ";
	std::cin >> num;

	int multiplication_answer = multiply(num);
	std::cout << multiplication_answer;
}