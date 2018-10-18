#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include "forma.h"

class Cuadrado : public Figuras {
	private:
		double lado;

	public:
		Cuadrado(double lado);
		double calcular_perimetro();
		double calcular_superficie();
		~Cuadrado();
};

#endif
