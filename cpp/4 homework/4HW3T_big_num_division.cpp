#include <iostream>
#include <fstream>
#include <cctype> 

std::string divide_big_num(std::string num, int divider, int precision) {
    if (divider == 0) {
        std::cout << "Error! How am I suposed to divide by 0?";
        return "";
    }
    
    std::string result;
    int remaining = 0;
    for (char ch : num) {
        if (!std::isdigit(ch)) {
            std::cout << "Error! Not a number in the number.";
            return "";
        }
        int num = remaining * 10 + (ch - '0');
        int current_n = num / divider;
        remaining = num % divider;
        if (current_n > 0) {
            result += current_n + '0';
        }
    }

    int counter = 0;
    while (remaining != 0 && counter < precision) {
        if (counter == 0) {
            result += '.';
        }
        int num = remaining * 10;
        int current_n = num / divider;
        remaining = num % divider;
        if (current_n > 0) {
            result += current_n + '0';
        }
        counter++;
    }
    return result;
}

void write_to_file(std::string filename, std::string text) {
    std::ofstream out_file(filename);
    if (out_file.is_open()) {
        out_file << text;
    }
    out_file.close();
}

int main() {
    std::string big_num = "12345678912345678912345678911234567891234567891234567891123456789123456789";
    int divider = 2;
    int precision = 10;

    std::string result = divide_big_num(big_num, divider, precision);
    std::cout << "Result of dividing " << big_num << " by " << divider << " is equal to " << result;

    std::string filename = "bigNumber.txt";
    write_to_file(filename, result);

    return 0;
}
