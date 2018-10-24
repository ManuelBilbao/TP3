#ifndef NODO_H
#define NODO_H

#include "figura.h"

typedef Figura Tipo;

class Nodo {

	private:

		Tipo* dato;
		Nodo* siguiente;

	public:

		//pre: recibe un dato tipo valido
		//pos: crea un nodo con el dato d
		Nodo(Tipo* dato);

		//pre: debe haber un nodo creado
		//pos: devuelve el dato que contenga el nodo 
		Tipo* obtener_dato();
	
		//pre: debe haber un nodo creado
		//pos: le carga el dato recibido al nodo 
		void asignar_dato(Tipo* dato);
		
		//pre: -
		//pos: devuelve el puntero al siguiente nodo o null si es el ultimo 
		Nodo* obtener_siguiente();
		
		//pre: tiene que haber un nodo creado 
		//pos: hace que el puntero al siguente nodo apuente a siguente
		void asignar_siguiente(Nodo* siguiente);
  
    ~Nodo();
};

#endif
