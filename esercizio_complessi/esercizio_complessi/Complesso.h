#pragma once
class Complesso
{
	private:
		int reale;
		int immaginaria;
	public:
		Complesso();
		Complesso(int, int);
		double getModulo() const;
		int getReale() const;
		int getImmaginaria() const;
};

Complesso operator-(const Complesso& c1, const Complesso& c2);
Complesso operator+(const Complesso& c1, const Complesso& c2);
bool operator>(const Complesso& c1, const Complesso& c2);
bool operator<(const Complesso& c1, const Complesso& c2);