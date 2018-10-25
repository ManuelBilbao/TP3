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

void Cuadrado::mostrar() {
	std::cout << endl << " El objeto es un cuadrado" << endl;
	cout << " Su superficie es de: " << calcular_superficie() << " y su perimetro de: " << calcular_perimetro() << endl << endl;
}

//destructor
Cuadrado::~Cuadrado() {
	std::cout << "Se destruye un cuadrado de lado " << lado << endl;
}
