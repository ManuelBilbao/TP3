#include "cuadrado.h"

//constructor
Cuadrado::Cuadrado(double lado) {
	this->lado = lado;
	this->tipo = "Cuadrado";
	std::cout << " Se crea un cuadrado de " << lado << " de lado" << endl;
}

//pre: -
//pos: devuelve el perimetro del cuadrado
double Cuadrado::calcular_perimetro() {
	return lado * 4;
}

//pre: -
//pos: devuelve la superficie del cuadrado 
double Cuadrado::calcular_superficie() {
	return lado * lado;
}

//destructor
Cuadrado::~Cuadrado() {
	std::cout << "Se destruye un cuadrado" << endl;
}
