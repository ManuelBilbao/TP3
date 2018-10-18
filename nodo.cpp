#include "nodo.h"

Nodo::Nodo(Tipo dato) {
	this->dato = dato;
	this->siguiente = 0;
}

Tipo Nodo::obtener_dato() {
	return this->dato;
}

void Nodo::asignar_dato(Tipo dato) {
	this->dato = dato;
}

Nodo* Nodo::obtener_siguiente() {
	return this->siguiente;
}

void Nodo::asignar_siguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}