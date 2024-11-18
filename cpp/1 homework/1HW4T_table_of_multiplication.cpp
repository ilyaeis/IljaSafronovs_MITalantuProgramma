#include <iostream>
#include <iomanip>

// input : number - multiplicand, range - range of multipliers from 1 to range (including)
// output : sum of nums (which can be divided by 3 or 5) from 1 to the input number

// Example: 
// 6, 8

// 6 * 1 =  6
// 6 * 2 = 12
// 6 * 3 = 18
// 6 * 4 = 24
// 6 * 5 = 30
// 6 * 6 = 36
// 6 * 7 = 42
// 6 * 8 = 48

int main()
{
    int n, range;
    std::cout << "Enter multiplicand: ";
    std::cin >> n;
    std::cout << "Enter range of multipliers: ";
    std::cin >> range;
    
    for (int i = 1; i <= range; i++) {
        std::cout << n << std::setw(4) << "*" << std::setw(4) << i << std::setw(4) << "=" << std::setw(6) << n * i << std::endl;
    }
}
