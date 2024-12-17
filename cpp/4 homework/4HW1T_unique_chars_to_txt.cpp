#include <iostream>
#include <set>
#include <fstream>
#include <string>

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

int main() {
	std::string input;
	std::string output;

	std::cout << "Enter the string of chars: ";
	std::getline(std::cin, input);

	std::set<char> unique_chars;
	for (char ch : input) {
		if (unique_chars.find(ch) == unique_chars.end()) {
			output += ch;
			unique_chars.insert(ch);
		}
	}
	write_to_file("textUnique.txt", output);

	return 0;
}