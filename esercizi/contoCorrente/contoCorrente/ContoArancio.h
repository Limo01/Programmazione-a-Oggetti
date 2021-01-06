#ifndef CONTOARANCIO_H
#define CONTOARANCIO_H

#include "ContoDiRisparmio.h"
#include "ContoCorrente.h"

class ContoArancio : public ContoDiRisparmio //eredita l'invariante: saldo >= 0
{
private:
	ContoCorrente& appoggio;//conto di appoggio deve essere modificabile
public:
	ContoArancio(ContoCorrente&, double);
	double preleva(double);
	double deposita(double);
};
#endif