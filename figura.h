#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura {
	protected:
		string tipo;
	
	public:
		string obtener_tipo();
		virtual double calcular_superficie() = 0;
		virtual double calcular_perimetro() = 0;
		virtual void mostrar() = 0;
		virtual ~Figura() {};
};

#endif
