#ifndef CONTOCORRENTE_H
#define CONTOCORRENTE_H

#include "ContoBancario.h"

class ContoCorrente : public ContoBancario
{
private:
	static double spesaFissa;
public:
	ContoCorrente(double);
	double deposita(double);
	double preleva(double);
};
#endif