#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "figura.h"

const double PI = 3.14159265359;

class Circulo : public Figura {

    private:
        double radio;

    public:

        //constructor
        Circulo(double radio);
        
        //pre: -
        //pos: devuelve el perimetro del circulo
        double calcular_perimetro();
        
        //pre: -
        //pos: devuelve la superficie del circulo
        double calcular_superficie();

        //pre: -
        //pos: muestra por pantalla perimetro y superficie de un circulo
        void mostrar();

        ~Circulo();
};

#endif // CIRCULO_H
