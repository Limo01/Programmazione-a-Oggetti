#include "ContoDiRisparmio.h"

ContoDiRisparmio::ContoDiRisparmio(double s = 0.0) : ContoBancario(s) {};

double ContoDiRisparmio::preleva(double x)
{
	return x <= getSaldo() ? ContoBancario::preleva(x) : getSaldo();
}