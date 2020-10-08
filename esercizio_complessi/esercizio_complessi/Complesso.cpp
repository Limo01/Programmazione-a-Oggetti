#include "Complesso.h"
#include "Math.h"

Complesso::Complesso()
{
	immaginaria = 0;
	reale = 0;
};

Complesso::Complesso(int reale, int immaginaria)
{
	this->reale = reale;
	this->immaginaria = immaginaria;
};

int Complesso::getReale() const
{
	return reale;
}

int Complesso::getImmaginaria() const
{
	return immaginaria;
}

double Complesso::getModulo() const
{
	return sqrt(pow(reale, 2) + pow(immaginaria, 2));
};

//Operatori definiti esternamente alla classe
Complesso operator-(const Complesso& c1, const Complesso& c2)
{
	return Complesso(c1.getReale()-c2.getReale(), c1.getImmaginaria()-c2.getImmaginaria());
}

Complesso operator+(const Complesso& c1, const Complesso& c2)
{
	return Complesso(c1.getReale() + c2.getReale(), c1.getImmaginaria() + c2.getImmaginaria());
}

bool operator<(const Complesso& c1, const Complesso& c2)
{
	return c1.getModulo() < c2.getModulo();
}

bool operator>(const Complesso& c1, const Complesso& c2)
{
	return c1.getModulo() > c2.getModulo();
}