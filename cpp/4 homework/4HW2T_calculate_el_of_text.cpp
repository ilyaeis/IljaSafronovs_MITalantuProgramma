#include <iostream>
#include <fstream>
#include <cctype>

int main() {
	std::ifstream in_file("fileText.txt");
	int upper_count = 0;
	int word_count = 0;
	int num_count = 0;

	int word_length = 0;
	char ch;

	if (in_file.is_open()) {
		while (in_file.get(ch)) {
			if (std::isdigit(ch)) {
				num_count++;
				word_length++;
			}
			else if (std::isalpha(ch)) {
				if (std::isupper(ch)) {
					upper_count++;
				}
				word_length++;
			}
			else {
				if (word_length == 3) {
					word_count++;
				}
				word_length = 0;
			}
		}
	}
	else {
		std::cout << "Unable to find the file!";
		return 1;
	}
	in_file.close();

	std::cout << "In text are " << num_count << " numbers!" << std::endl;
	std::cout << "In text are " << word_count << " word with length of 3 chars!" << std::endl;
	std::cout << "In text are " << upper_count << " chars in upper case!" << std::endl;

	return 0;

}
