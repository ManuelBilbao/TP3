#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;

class Figura {

		protected:

				string tipo_figura;

		public:

				//pre: -
				//pos: obtiene el tipo de figura y la devuelve en un string
				string obtener_tipo();

				//se encarga de calcular la superfice de la figura
				virtual double calcular_superficie() = 0;

				//se encarga de calcular el perimetro de la figura
				virtual double calcular_perimetro() = 0;

				//se encarga de mostrar el tipo de figura junto con su perimetro y superfice
				virtual void mostrar() = 0;

				//destructor
				virtual ~Figura() {};
};

#endif
