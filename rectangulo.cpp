#include "rectangulo.h"

Rectangulo::Rectangulo(double altura, double base) {
	this->altura = altura;
	this->base = base;
	this->tipo = "Rectangulo";
	std::cout << " Se crea un rectangulo de altura " << altura << " y base " << base << endl;
}

double Rectangulo::calcular_superficie() {
	
	return (this->altura * this->base);
}

double Rectangulo::calcular_perimetro() {

	return (2 * (this->altura + this->base));
}

void Rectangulo::mostrar() {
	
	std::cout << endl << " El objeto es un rectangulo" << endl;
	std::cout << " Su superficie es de: " << calcular_superficie() << " y su perimetro de: " << calcular_perimetro() << endl << endl;
}

Rectangulo::~Rectangulo() {
	
	std::cout << " Se destruye un rectangulo de altura " << altura << " y base " << base << endl;
}
