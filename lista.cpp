#include "lista.h"

int const PRIMER_POSICION = 1;

Lista::Lista() {

		this->primero = NULL;
		this->longitud = LONGITUD_LISTA_VACIA;

}

Lista::~Lista () {

		while (longitud > LONGITUD_LISTA_VACIA) {
				borrar_elemento(PRIMER_POSICION);
		}

}

unsigned Lista::obtener_longitud() {

		return this->longitud;

}

bool Lista::lista_vacia() {

		return (longitud == LONGITUD_LISTA_VACIA);

}

void Lista::insertar(Tipo* elemento, unsigned posicion) {

		Nodo* nuevo = new Nodo(elemento);

		if (posicion == PRIMER_POSICION) {
				nuevo->asignar_siguiente(primero);
				this->primero = nuevo;
		} else {
				Nodo* anterior = obtener_nodo(posicion - 1);
				nuevo->asignar_siguiente(anterior->obtener_siguiente());
				anterior->asignar_siguiente(nuevo);
		}

		this->longitud++;

}

Nodo* Lista::obtener_nodo(unsigned posicion) {

		Nodo* auxiliar = primero;

		for (unsigned i = 1; i < posicion; i++) {
				auxiliar = auxiliar->obtener_siguiente();
		}

		return auxiliar;

}

Tipo* Lista::consultar(unsigned posicion) {

		Nodo* auxiliar = obtener_nodo(posicion);
		return (auxiliar->obtener_dato());

}

void Lista::borrar_elemento(unsigned posicion) {

		Nodo* borrar = primero;

		if (posicion == PRIMER_POSICION) {
				primero = borrar->obtener_siguiente();
		} else {
				borrar = obtener_nodo(posicion);
				Nodo* anterior = obtener_nodo(posicion - 1);
				Nodo* siguiente = borrar->obtener_siguiente();
				anterior->asignar_siguiente(siguiente);
		}

		delete borrar;
		this->longitud--;

}
