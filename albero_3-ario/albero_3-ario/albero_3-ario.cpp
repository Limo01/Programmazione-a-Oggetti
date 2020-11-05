#include <iostream>
#include "albero.h"

int main()
{
	albero<int> a;
	a.insert(2);
	a.insert(3);
	std::cout << a.search(4) << std::endl;
}