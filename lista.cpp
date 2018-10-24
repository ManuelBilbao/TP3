#include "lista.h"

int const POSICION_INICIO_LISTA = 1;
int const LONGITUD_LISTA_VACIA = 0;

//Constructor
Lista::Lista () {
	this->primero = 0;
	this->longitud = 0;
}

//Destructor
Lista::~Lista () {
	while (longitud > LONGITUD_LISTA_VACIA) {
		borrar_elemento (1);
	}
}

unsigned Lista::obtener_longitud() {
	return this -> longitud;
}

bool Lista::lista_vacia () {
	return (longitud == LONGITUD_LISTA_VACIA);
}

void Lista::insertar (Tipo* elemento, unsigned posicion) {

	Nodo* nuevo = new Nodo (elemento);

	if (posicion == POSICION_INICIO_LISTA) {
		nuevo -> asignar_siguiente (primero);
		this -> primero = nuevo;
	} else {
		Nodo* anterior = obtener_nodo(posicion - 1);
		nuevo -> asignar_siguiente (anterior -> obtener_siguiente ());
		anterior -> asignar_siguiente (nuevo);
	}

	this -> longitud++;
}

//Método privado
Nodo* Lista::obtener_nodo (unsigned posicion) {

	Nodo* auxiliar = primero;

	for (unsigned i = 1; i < posicion; i++) {
		auxiliar = auxiliar -> obtener_siguiente ();
	}

	return auxiliar;
}

Tipo* Lista::consultar (unsigned posicion) {

	Nodo* auxiliar = obtener_nodo (posicion);
	return (auxiliar -> obtener_dato ());
}

void Lista::borrar_elemento (unsigned posicion) {

	Nodo* borrar = primero;

	if (posicion == POSICION_INICIO_LISTA) {
		primero = borrar -> obtener_siguiente ();
	} else {
		borrar = obtener_nodo (posicion);
		Nodo* anterior = obtener_nodo (posicion - 1);
		Nodo* siguiente = borrar -> obtener_siguiente ();
		anterior -> asignar_siguiente (siguiente);
	}

	delete borrar;
	this -> longitud--;
}
