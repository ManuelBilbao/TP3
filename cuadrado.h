#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

class Cuadrado : public Forma {
	private:
		double lado;

	public:
		Cuadrado(double lado);
		double calcular_perimetro();
		double calcular_superficie();
		~Cuadrado();
};

#endif