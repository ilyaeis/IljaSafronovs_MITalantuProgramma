#include <iostream>
#include <set>

int main()
{
    int nums[5][5] = {
        { 10, 2, 3, 4, 5 },
        { 2, 3, 4, 5, 6 },
        { 3, 4, 5, 6, 7 },
        { 4, 5, 6, 7, 8 },
        { 5, 6, 7, 8, 9 },
    };

    std::set<int> unique_nums;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << nums[i][j] << " ";
            unique_nums.insert(nums[i][j]);
        } std::cout << std::endl;
    }

    std::cout << "\nVisas divdimensija masīva unikālās vērtības augošā secībā:\n";
    for (int i : unique_nums) {
        std::cout << i << " ";
    }

    return 0;
}