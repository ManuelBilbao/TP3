#include "cuadrado.h"

Cuadrado::Cuadrado(double lado) {
	this->lado = lado;
	this->tipo = "Cuadrado";
	std::cout << " Se crea un cuadrado de " << lado << " de lado" << endl;
}

double Cuadrado::calcular_perimetro() {
	return lado * 4;
}

double Cuadrado::calcular_superficie() {
	return lado * lado;
}

void Cuadrado::mostrar() {
	std::cout << endl << " El objeto es un cuadrado" << endl;
	std::cout << " Su superficie es de: " << calcular_superficie() << " y su perimetro de: " << calcular_perimetro() << endl << endl;
}

Cuadrado::~Cuadrado() {
	std::cout << "Se destruye un cuadrado de lado " << lado << endl;
}
