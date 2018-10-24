#include "circulo.h"

Circulo::Circulo(double radio) {
    this->radio = radio;
    this->tipo = "Circulo";
    std::cout << " Se crea un circulo de radio " << radio << endl;
}

double Circulo::calcular_perimetro() {
    return 2 * PI * radio;
}

double Circulo::calcular_superficie() {
    return PI * radio * radio;
}
