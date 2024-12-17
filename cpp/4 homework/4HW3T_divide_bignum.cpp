#include <iostream>
#include <fstream>

void write_to_file(std::string filename, std::string text) {
	std::ofstream out_file(filename);
	if (out_file.is_open()) {
		out_file << text;
	}
	else {
		std::cout << "Unable to open the file!";
	}
	out_file.close();
}

std::string divide_step(int& remaining, int num, int divider) {
	int current_result = (remaining * 10 + num) / divider;
	remaining = (remaining * 10 + num) % divider;

	if (current_result > 0) {
		return std::string(1, current_result + '0');
	}
	return "";
}

std::string divide_big_num(std::string big_num, int divider, int precision) {
	std::string result;
	int remaining = 0;
	
	for (char ch : big_num) {
		if (!std::isdigit(ch)) {
			std::cout << "Number contains non-number element! Unable to procceed!";
			return "";
		}
		result += divide_step(remaining, ch - '0', divider);
	}
	if (remaining > 0) {
		result += '.';
	}
	while (remaining > 0 && (precision--) > 0) {
		result += divide_step(remaining, 0, divider);
	}
	return result;
}

int main() {
	std::string big_num = "12345678912345678912345678911234567891234567891234567891123456789123456789";
	int divider = 2;
	int precision = 5;

	std::string filename = "bigNumber.txt";
	write_to_file(filename, divide_big_num(big_num, divider, precision));

	return 0;
}