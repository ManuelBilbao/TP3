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

void Circulo::mostrar() {
	std::cout << endl << " El objeto es un circulo" << endl;
	std::cout << " Su superficie es de: " << calcular_superficie() << " y su perimetro de: " << calcular_perimetro() << endl << endl;
}

Circulo::~Circulo() {
	std::cout << " Se destruye un circulo de radio " << radio << endl;
}
