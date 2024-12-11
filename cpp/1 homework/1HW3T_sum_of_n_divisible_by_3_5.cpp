#include <iostream>

// input : number
// output : sum of nums (which can be divided by 3 or 5) from 1 to the input number

// Example: 
// 8
// 14

// 3 + 5 + 6 = 14

int main()
{
    int n, sum = 0;
    std::cin >> n;

    for (int i = 3; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    std::cout << sum;
}
