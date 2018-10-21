#ifndef FORMA_H
#define FORMA_H

#include <iostream>
#include <string>

using namespace std;

class Figuras {
	private:
		string tipo;
	
	public:
		string obtener_tipo();
		void asignar_tipo(string tipo);
		virtual double calcular_superficie() = 0;
		virtual double calcular_perimetro() = 0;
};

#endif
