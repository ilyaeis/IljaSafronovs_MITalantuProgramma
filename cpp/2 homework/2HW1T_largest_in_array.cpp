#include <iostream>

int main()
{
    int nums[] = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int largest = nums[0];

    for (int i = 0; i < 10; i++) {
        if (largest < nums[i]) largest = nums[i];
    }
    std::cout << "The largest nummber is " << largest;

    return 0;
}