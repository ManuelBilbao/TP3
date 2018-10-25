#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura {
	protected:
		string tipo;

	public:

		//constructor
		string obtener_tipo();

		//calcula la superficie de una Figura
		virtual double calcular_superficie() = 0;

		//calcula el perimetro de una Figura 
		virtual double calcular_perimetro() = 0;

		//muestra el tipo de figura con su perimetro y superficie
		virtual void mostrar() = 0;

		//destructor
		virtual ~Figura() {};
};

#endif
