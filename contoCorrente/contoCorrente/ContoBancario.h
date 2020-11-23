#ifndef CONTOBANCARIO_H
#define CONTOBANCARIO_H

class ContoBancario
{
private:
	double saldo;
public:
	ContoBancario(double);
	double deposita(double);
	double preleva(double);
	double getSaldo() const;
};
#endif