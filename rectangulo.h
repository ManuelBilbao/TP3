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
    Rectangulo(double altura, double base);
   
    //pre: -
    //pos: devuelve la superficie del rectangulo
    double calcular_superficie();
  
    //pre: -
    //pos: devuelve el perimetro del rectangulo
    double calcular_perimetro();

    void mostrar();

    ~Rectangulo();
};

#endif
