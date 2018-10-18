#include "nodo.h"

class Lista {
	
	//Atributos
	private:
		Nodo* primero;
		unsigned longitud;

	//Métodos
	public:
		//Constructor
		Lista();

		//Destructor
		~Lista();

		unsigned obtener_longitud();

		bool lista_vacia();
		
		//Pre: 0 < pos  <= obtener_longitud()+1
		//Post: coloca el dato en la posición, la primer posición es la 1
		void insertar(Tipo e, unsigned pos);

		//Pre: 0 < pos <= obtener_longitud()
		//Post:  quita el dato
		void borrar(unsigned pos);

		//Pre: 0 < pos <= obtener_longitud()
		//Post: devuelve el dato
		Tipo consultar(unsigned pos);

		Nodo* obtener_nodo(unsigned pos);
};