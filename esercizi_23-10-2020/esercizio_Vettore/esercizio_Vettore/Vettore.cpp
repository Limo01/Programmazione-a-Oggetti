#include <iostream>
#include "Vettore.h"

Vettore::Vettore(int d)
{
	vett = new int[d];
	dim = d;

	for (int i = 0; i < dim; i++)
		vett[i] = 0;
}

int Vettore::getDim() const
{
	return dim;
}

void Vettore::append(const Vettore& v)
{
	if (v.dim != 0)
	{
		int* aux = new int[dim + v.dim];

		for (int i = 0; i < dim; i++)
			aux[i] = vett[i];

		for (int i = 0; i < v.dim; i++)
			aux[dim+i] = v.vett[i];

		delete[] vett;
		dim += v.dim;
		vett = aux;
	}
}

int& Vettore::operator[](int a) const
{
	return vett[a];
}

bool Vettore::operator==(const Vettore& v) const
{
	if (dim != v.dim)
		return false;

	bool esito = true;
	for (int i = 0; i < dim && esito; i++)
		esito = vett[i] == v.vett[i];
	return esito;
}

Vettore& Vettore::operator=(const Vettore& v)
{
	if (this != &v)
	{
		delete[] vett;
		vett = v.dim == 0 ? nullptr : new int[v.dim];
		dim = v.dim;

		for (int i = 0; i < dim; i++)
			vett[i] = v.vett[i];
	}
	return *this;
}

Vettore operator+(const Vettore& v1, const Vettore& v2)
{
	Vettore aux(v1);
	aux.append(v2);
	return aux;
}

std::ostream& operator<<(std::ostream& os, const Vettore& v)
{
	if (v.getDim() == 0)
		os << "[ ]";
	else
	{
		os << "[ ";
		for (int i = 0; i < v.getDim(); i++)
			os << v[i] << " ";
		os << "]";
	}
	return os;
}