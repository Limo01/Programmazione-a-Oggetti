#include "ContoCorrente.h"

ContoCorrente::ContoCorrente(double s = 0.0) : ContoBancario(s) {};

double ContoCorrente::deposita(double x)
{
	return ContoBancario::deposita(x - spesaFissa);//se spesaFissa > x, il deposito non viene effettuato
};

double ContoCorrente::preleva(double x)
{
	return ContoBancario::preleva(x + spesaFissa);
};

double ContoCorrente::spesaFissa = 1.0;