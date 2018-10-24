#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include "figura.h"

class Cuadrado : public Figura {
	private:
		double lado;

	public:
		Cuadrado(double lado);
		double calcular_perimetro();
		double calcular_superficie();
		~Cuadrado();
};

#endif
