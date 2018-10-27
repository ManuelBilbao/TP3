#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <iostream>
#include "figura.h"

class Rectangulo : public Figura {

    private:

        double altura;
        double base;

      public:

        //constructor
        Rectangulo(double base, double altura);

        //pre: -
        //pos: devuelve la superficie del rectangulo
        double calcular_superficie();

        //pre: -
        //pos: devuelve el perimetro del rectangulo
        double calcular_perimetro();

        //pre: -
        //pos: muestra por pantalla el tipo de figura, su perimetro y su superficie
        void mostrar();

        //destructor
        ~Rectangulo();
};

#endif
