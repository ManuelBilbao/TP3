#ifndef NODO_H
#define NODO_H

typedef Figuras Tipo;

class Nodo {
	private:
		Tipo dato;
		Nodo* siguiente;

	public:
		Nodo(Tipo dato);
		Tipo obtener_dato();
		void asignar_dato(Tipo dato);
		Nodo* obtener_siguiente();
		void asignar_siguiente(Nodo* siguiente);
};

#endif