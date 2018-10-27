#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>
#include "figura.h"

class Cuadrado : public Figura {

		private:

				double lado;

		public:

				//constructor
				Cuadrado(double lado);

				//pre: -
				//pos: devuelve el perimetro del cuadrado
				double calcular_perimetro();

				//pre: -
				//pos: devuelve la superficie del cuadrado
				double calcular_superficie();

				//pre: -
				//pos: muestra por pantalla que la figura es un cuadrado y el perimetro y superficie del mismo
				void mostrar();

				//destructor
				~Cuadrado();

};

#endif
