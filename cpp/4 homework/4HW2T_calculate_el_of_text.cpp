#include <iostream>
#include <fstream>
#include <cctype>

int main() {
	std::ifstream inFile("fileText.txt");
	int upperCount = 0;
	int wordCount = 0;
	int numCount = 0;

	int wordLength = 0;
	char ch;

	if (inFile.is_open()) {
		while (inFile.get(ch)) {
			if (std::isdigit(ch)) {
				numCount++;
				wordLength++;
			}
			else if (std::isalpha(ch)) {
				if (std::isupper(ch)) {
					upperCount++;
				}
				wordLength++;
			}
			else {
				if (wordLength == 3) {
					wordCount++;
				}
				wordLength = 0;
			}
		}
	}
	else {
		std::cout << "Unable to find the file!";
		return 1;
	}
	inFile.close();

	std::cout << "In text are " << numCount << " numbers!" << std::endl;
	std::cout << "In text are " << wordCount << " word with length of 3 chars!" << std::endl;
	std::cout << "In text are " << upperCount << " chars in upper case!" << std::endl;

	return 0;

}
