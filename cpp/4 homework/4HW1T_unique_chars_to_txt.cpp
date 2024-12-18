#include <iostream>
#include <set>
#include <fstream>
#include <string>

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

int main() {
	std::string input;
	std::string output;

	std::cout << "Enter the string of chars: ";
	std::getline(std::cin, input);

	std::set<char> uniqueChars;
	for (char ch : input) {
		if (uniqueChars.find(ch) == uniqueChars.end()) {
			output += ch;
			uniqueChars.insert(ch);
		}
	}
	writeToFile("textUnique.txt", output);

	return 0;
}