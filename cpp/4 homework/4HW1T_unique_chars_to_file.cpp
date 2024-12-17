#include <iostream>
#include <set>
#include <fstream>
#include <string>

int main() {
    std::set<char> unique_chars;
    std::string char_string;

    std::cout << "Enter string of chars: ";
    std::getline(std::cin, char_string);
    for (char c : char_string) {
        unique_chars.insert(c);
    }

    std::fstream out_file("textUnique.txt", std::ios::out);
    if (out_file.is_open()) {
        for (char c : unique_chars) {
            out_file << c;
        }
    }
    out_file.close();

    return 0;
}
