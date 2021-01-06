#include <iostream>
#include "Vettore.h"

int main()
{
	Vettore v1(5);
	Vettore v2(5);

	if (v1 == v2)
		std::cout << "v1 e v2 sono uguali" << std::endl;

	v1= 10;//costruttore usato come conversione int => Vettore

	v1[2] = 200;
	v2[0] = 120;

	std::cout << "Dim v1: " << v1.getDim() << std::endl;
	std::cout << "v1: " << v1 << std::endl;

	std::cout << "Dim v2: " << v2.getDim() << std::endl;
	std::cout << "v2: " << v2 << std::endl;

	v1.append(v2);

	std::cout << "Dim v1: " << v1.getDim() << std::endl;
	std::cout << "v1.append(v2): " << v1 << std::endl;
}