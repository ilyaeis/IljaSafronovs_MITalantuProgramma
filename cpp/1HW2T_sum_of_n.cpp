#include <iostream>

// input : number
// output : sum of nums from 1 to the input numver

// Example: 
// 6
// 21

// 1 + 2 + 3 + 4 + 5 + 6 = 21

int main()
{
    int n, sum = 0;
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    std::cout << sum;
}
