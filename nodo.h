#ifndef NODO_H
#define NODO_H

#include "figura.h"

typedef Figura Tipo;

class Nodo {
	private:
		Tipo* dato;
		Nodo* siguiente;

	public:
		Nodo(Tipo* dato);
		~Nodo();
		Tipo* obtener_dato();
		void asignar_dato(Tipo* dato);
		Nodo* obtener_siguiente();
		void asignar_siguiente(Nodo* siguiente);
};

#endif
