#include <iostream>
#include "Complesso.h"

int main()
{
	Complesso c1(-3, 4);
	Complesso c2(1, -2);

	std::cout << "Modulo di c1: " << c1.getModulo() << std::endl;
	std::cout << "Modulo di c2: " << c2.getModulo() << std::endl << std::endl;

	std::cout << "Addizione c1+c2: " << (c1 + c2).getReale() << " " << (c1 + c2).getImmaginaria() << "i" << std::endl;
	std::cout << "Sottrazione c1-c2: " << (c1 - c2).getReale() << " " << (c1 - c2).getImmaginaria() << "i" << std::endl << std::endl;

	(c1 < c2) ? std::cout << "c1 e' minore di c2" << std::endl : std::cout << "c2 e' minore di c1" << std::endl;
	(c1 > c2) ? std::cout << "c1 e' maggiore di c2" << std::endl : std::cout << "c2 e' maggiore di c1" << std::endl;
}