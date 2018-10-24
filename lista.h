#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {

	// Atributos
	private:
		Nodo* primero;
		unsigned longitud;

	// Métodos
	public:
		// Constructor
		Lista();

		// Destructor
		~Lista();

		// Pre: -
		// Post: Devuelve verdadero si la lista esta vacía
		bool lista_vacia();

		//Pre: 0 < posicion  <= obtener_longitud()+1
		//Post: coloca el dato en la posición, la primer posición es la 1
		void insertar(Tipo* elemento, unsigned posicion);

		//Pre: 0 < posicion <= obtener_longitud()
		//Post: devuelve el dato
		Tipo* consultar(unsigned posicion);

		//Pre: 0 < posicion <= obtener_longitud()
		//Post:  quita el dato
		void borrar_elemento(unsigned posicion);

		// Pre: -
		// Post: Devuelve la cantidad de nodos presentes en la lista
		unsigned obtener_longitud();

		//Pre: 0 < posicion <= obtener_longitud()
		//Post: devuelve un puntero al nodo pedido
		Nodo* obtener_nodo(unsigned posicion);
};

#endif
