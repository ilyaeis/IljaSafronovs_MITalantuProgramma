#include <iostream>
#include <fstream>

void writeToFile(std::string filename, std::string text) {
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		outFile << text;
	}
	else {
		std::cout << "Unable to open the file!";
	}
	outFile.close();
}

std::string divideStep(int& remaining, int num, int divider) {
	int currentResult = (remaining * 10 + num) / divider;
	remaining = (remaining * 10 + num) % divider;

	if (currentResult > 0) {
		return std::string(1, currentResult + '0');
	}
	return "";
}

std::string divideBigNum(std::string bigNum, int divider, int precision) {
	std::string result;
	int remaining = 0;
	
	for (char ch : bigNum) {
		if (!std::isdigit(ch)) {
			std::cout << "Number contains non-number element! Unable to procceed!";
			return "";
		}
		result += divideStep(remaining, ch - '0', divider);
	}
	if (remaining > 0) {
		result += '.';
	}
	while (remaining > 0 && (precision--) > 0) {
		result += divideStep(remaining, 0, divider);
	}
	return result;
}

int main() {
	std::string bigNum = "12345678912345678912345678911234567891234567891234567891123456789123456789";
	int divider = 2;
	int precision = 5;

	std::string filename = "bigNumber.txt";
	writeToFile(filename, divideBigNum(bigNum, divider, precision));

	return 0;
}