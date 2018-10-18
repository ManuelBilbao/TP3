#ifndef CIRCULO_H
#define CIRCULO_H

#include "forma.h"

const double PI = 3.14159265359;

class Circulos:public Figuras{

    private:
        double radio;

    public:
        Circulos(double radio);
        double calcular_perimetro();
        double calcular_superficie();

};

#endif // CIRCULO_H
