#include "rectangulo.h"

Rectangulo::Rectangulo(double altura, double base) {
  this->altura = altura;
  this->base = base;
  this->tipo = "Rectangulo";
  std::cout << " Se crea un rectangulo de altura " << altura << " y base " << base << endl;
}

double Rectangulo::calcular_superficie(){
  return (this->altura * this->base);
}

double Rectangulo::calcular_perimetro(){
  return (2 * (this->altura + this->base));
}
