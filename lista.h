#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista {

	//Atributos
	private:
		Nodo* primero;
		unsigned longitud;

	//Métodos
	public:
		//Constructor
		Lista ();

		//Destructor
		~Lista ();

		//Pre:
		//Post:
		unsigned obtener_longitud ();

		//Pre:
		//Post:
		bool lista_vacia ();

		//Pre: 0 < pos  <= obtener_longitud()+1
		//Post: coloca el dato en la posición, la primer posición es la 1
		void insertar (Tipo* elemento, unsigned posicion);

		//Pre: 0 < pos <= obtener_longitud()
		//Post:  quita el dato
		void borrar_elemento (unsigned posicion);

		//Pre: 0 < pos <= obtener_longitud()
		//Post: devuelve el dato
		Tipo* consultar (unsigned posicion);

		//Pre:
		//Post:
		Nodo* obtener_nodo (unsigned posicion);
};

#endif
