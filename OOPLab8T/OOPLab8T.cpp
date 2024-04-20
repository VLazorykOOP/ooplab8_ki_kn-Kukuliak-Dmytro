#include <iostream>
#include "example.h"
#include <string>
int main()
{
	SortFind<char*> test1(10);
	//std::cout << test1;
	test1.randomize();
	std::cout << test1;
	
	test1.countingSort();
	std::cout << test1;

	//std::cout << test1.find('f');
}


