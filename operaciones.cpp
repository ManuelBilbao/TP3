#include "operaciones.h"

void agregar_objeto(Lista &lista) {
	string tipo;
	bool tipo_valido = false;
	
	while (!tipo_valido) {
		cout << " A: Circulo, B: Cuadrado, C: Rectangulo, X: Cancelar" << endl;
		cout << " Tipo de forma: ";
		cin >> tipo;
		
		if (tipo.length() == 1 && (tipo == "A" || tipo == "B" || tipo == "C")) {
			tipo_valido = true;
		} else {
			cout << endl << " Por favor ingrese una forma valida" << endl;
		}
	}

	srand(time(nullptr));
	int numero = rand() % 1000;
	Figuras* figura;
	
	if (tipo == "A")
		figura = new Circulo(numero);
	else if (tipo == "B")
		figura = new Cuadrado(numero);
	else if (tipo == "C")
		figura = new Rectangulo(numero, numero % 11);

	lista.insertar(figura, lista.obtener_longitud() + 1);
}

void listar(Lista &lista) {
	cout << endl << "Listado de formas:" << endl;
	for (int i = 1; i < lista.obtener_longitud() + 1; i++) {
		cout << lista.consultar(i)->obtener_tipo() << endl;
	}
	cout << endl;
}