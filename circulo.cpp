#include "circulo.h"

Circulo::Circulo(double radio){
    this->radio = radio;
}

double Circulo::calcular_perimetro(){
    return 2 * PI * radio;
}

double Circulo::calcular_superficie(){
    return PI * radio * radio;

}
