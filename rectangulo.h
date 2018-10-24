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
  
    //constructor
    Rectangulo(double altura, double base);
   
    //pre: -
    //pos: devuelve la superficie del rectangulo
    double calcular_superficie();
  
    //pre: -
    //pos: devuelve el perimetro del rectangulo
    double calcular_perimetro();

};

#endif
