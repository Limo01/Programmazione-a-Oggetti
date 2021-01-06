#include <iostream>
#include "albero.h"

int main()
{
	albero<int> a;
	a.insert(2);
	a.insert(3);

	std::cout << a << std::endl;

	albero<int> b = a;
	if (a == b)
		std::cout << "true" << std::endl;
	else 
		std::cout << "false" << std::endl;
}