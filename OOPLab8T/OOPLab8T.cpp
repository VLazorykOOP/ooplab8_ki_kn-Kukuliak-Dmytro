#include <iostream>
#include "example.h"
int main()
{
	SortFind<char> test1(50);
	//std::cout << test1;
	test1.randomize();
	std::cout << test1;
	std::cout <<test1.find(2);

}

