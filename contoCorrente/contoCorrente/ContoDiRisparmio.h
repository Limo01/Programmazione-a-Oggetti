#ifndef CONTODIRISPARMIO_H
#define CONTODIRISPARMIO_H

#include "ContoBancario.h"

class ContoDiRisparmio : public ContoBancario
{
	//INVARIANTE: saldo >= 0
public:
	ContoDiRisparmio(double);
	double preleva(double);
	//deposita non necessita ridefinizione
};
#endif