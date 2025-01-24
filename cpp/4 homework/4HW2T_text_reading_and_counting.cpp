#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    int num_count = 0;
    int upper_case_count = 0;
    int word_count = 0;
    int word_length = 0;
    char ch_in_txt;

    std::ifstream in_file("fileText.txt", std::ios::in);
    if (in_file.is_open()) {
        while (in_file.get(ch_in_txt)) {
            if (std::isdigit(ch_in_txt)) {
                num_count++;
                word_length++;
            }
            else if (std::isalpha(ch_in_txt)) {
                if (std::isupper(ch_in_txt)) {
                    upper_case_count++;
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
        std::cout << "Unable to open the file!";
        in_file.close();
        return 1;
    }
    in_file.close();

    std::cout << "In text are " << upper_case_count << " chars in upper case!" << std::endl;
    std::cout << "In text are " << num_count << " nums!" << std::endl;
    std::cout << "In text are " << word_count << " words with length equals 3!" << std::endl;
    return 0;
}
