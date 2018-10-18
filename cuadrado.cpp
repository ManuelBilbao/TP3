#include "cuadrado.h"

Cuadrado::Cuadrado(double lado) {
	this->lado = lado;
	std::cout << "Se crea un cuadrado de " << lado << " de lado" << endl;
}

double Cuadrado::calcular_perimetro() {
	return lado * 4;
}

double Cuadrado::calcular_superficie() {
	return lado * lado;
}

Cuadrado::~Cuadrado() {
	std::cout << "Se destruye un cuadrado" << endl;
}