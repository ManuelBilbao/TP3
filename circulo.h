#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

const double PI = 3.14159265359;

class Circulo : public Figuras {

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

};

#endif // CIRCULO_H
