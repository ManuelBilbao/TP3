#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "figura.h"

const double PI = 3.14159265359;

class Circulo : public Figura {

    private:
        double radio;

    public:
        Circulo(double radio);
        double calcular_perimetro();
        double calcular_superficie();

};

#endif // CIRCULO_H
