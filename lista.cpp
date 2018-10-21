#include "lista.h"

//Constructor
Lista::Lista() {
	this->primero = 0;
	this->longitud = 0;
}

//Destructor
Lista::~Lista() {
	while (longitud > 0) {
		borrar(1);
	}
}

unsigned Lista::obtener_longitud() {
	return this->longitud;
}

bool Lista::lista_vacia() {
	return (longitud == 0);
}

void Lista::insertar(Tipo* e, unsigned pos) {
	Nodo* nuevo = new Nodo(e);

	if (pos == 1) {
		nuevo->asignar_siguiente(primero);
		this->primero = nuevo;
	} else {
		Nodo* anterior = obtener_nodo(pos - 1);
		nuevo->asignar_siguiente(anterior->obtener_siguiente());
		anterior->asignar_siguiente(nuevo);
	}

	this->longitud++;
}

//Método privado
Nodo* Lista::obtener_nodo(unsigned pos) {
	Nodo* aux = primero;

	for (int i = 1; i < pos; i++) {
		aux = aux->obtener_siguiente();
	}

	return aux;
}

Tipo* Lista::consultar(unsigned pos){
	Nodo* aux = obtener_nodo(pos);
	return (aux->obtener_dato());
}

void Lista::borrar(unsigned pos){
	Nodo* borrar = primero;

	if (pos == 1) {
		primero = borrar->obtener_siguiente();
	} else {
		Nodo* anterior = obtener_nodo(pos - 1);
		borrar = anterior->obtener_siguiente();
	}

	delete borrar;
	this->longitud--;
}
