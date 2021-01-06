#include "ContoBancario.h"

ContoBancario::ContoBancario(double s=0.0) :saldo(s >= 0 ? s : 0.0) {};

double ContoBancario::getSaldo() const
{
	return saldo;
};

double ContoBancario::preleva(double x)
{
	return x >= 0 ? saldo -= x : saldo;
};

double ContoBancario::deposita(double x)
{
	return x >= 0 ? saldo += x : saldo;
};