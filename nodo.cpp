#include "nodo.h"

Nodo::Nodo(Tipo dato) {
	this->dato = dato;
	this->siguiente = 0;
}

Tipo obtener_dato() {
	return this->dato;
}

void asignar_dato(Tipo dato) {
	this->dato = dato;
}

Nodo* obtener_siguiente() {
	return this->siguiente;
}

void asignar_siguiente(Nodo* siguiente) {
	this->siguiente = siguiente;
}