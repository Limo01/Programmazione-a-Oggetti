#include "ContoArancio.h"

ContoArancio::ContoArancio(ContoCorrente& cc, double s = 0.0) : ContoDiRisparmio(s), appoggio(cc) {};

double ContoArancio::preleva(double x)
{
	if (x <= getSaldo() && x >= 0)
	{
		appoggio.deposita(x);
		return ContoDiRisparmio::preleva(x);
	}
	return getSaldo();
};

double ContoArancio::deposita(double x)
{
	if (x >= 0)
	{
		appoggio.preleva(x);
		return ContoDiRisparmio::deposita(x);
	}
	return getSaldo();
};