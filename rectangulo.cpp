#include "rectangulo.h"


Rectangulo::Rectangulo(double altura, double base){
  this->altura = altura;
  this->base = base;
  this->asignar_tipo("Rectangulo");
  cout << "se crea un rectangulo de altura " << altura << " y base " << base << endl;
}

double Rectangulo::calcular_superficie(){
  return (this->altura * this-> base);
}

double Rectangulo::calcular_perimetro(){
  return (2 * (this->altura + this->base));
}
