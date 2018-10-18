#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

const double PI = 3.14159265359;

class Circulo : public Figuras {

    private:
        double radio;

    public:
        Circulo(double radio);
        double calcular_perimetro();
        double calcular_superficie();

};

#endif // CIRCULO_H
