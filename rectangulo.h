#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <iostream>
#include "forma.h"

using namespace std;

class Rectangulo : public Figuras {
  private:
    double altura;
    double base;
  public:
    Rectangulo(double altura, double base);
    double calcular_superficie();
    double calcular_perimetro();

};

#endif
