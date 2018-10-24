#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <iostream>
#include "figura.h"

class Rectangulo : public Figura {
	private:
		double altura;
		double base;
	public:
		Rectangulo(double altura, double base);
		double calcular_superficie();
		double calcular_perimetro();
};

#endif
