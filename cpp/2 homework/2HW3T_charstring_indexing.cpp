#include <iostream>
#include <cstring> 

int main()
{
	char str[256];

	std::cout << "Enter string: ";
	std::cin.getline(str, 256);

	for (int i = 0; i < strlen(str); i++) {
		std::cout << str[i] << " : " << i << std::endl;
	}

	return 0;
}