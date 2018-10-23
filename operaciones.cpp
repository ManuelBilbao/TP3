#include "operaciones.h"

unsigned pedir_posicion(unsigned longitud_lista) {
	bool posicion_valida = false;
	unsigned posicion;

	while (!posicion_valida) {
		cout << " Ingresar posicion deseada: ";
		cin >> posicion;

		while (!cin.good()) { // Comprobar que sea un numero
			cin.clear();
			cin.ignore();
			cout << " Por favor ingrese un numero valido";
			cin >> posicion;
		}

		if (posicion > 0 && posicion <= longitud_lista) {
			posicion_valida = true;
		} else {
			cout << endl;
			cout << " Por favor ingrese una posicion valida (mayor a 0 y menor o igual a " << longitud_lista << ")";
			cout << endl;
		}
	}
	return posicion;
}

void msj_lista_vacia() {
	cout << endl << " No se encontro ninguna forma en la lista" << endl << endl;
}

void consultar_posicion(Lista &lista) {
	if (lista.obtener_longitud() <= 0) {
		msj_lista_vacia();
		return;
	}

	unsigned posicion = pedir_posicion(lista.obtener_longitud());
	Tipo* forma = lista.consultar(posicion);
	cout << endl << " El objeto es un " << forma->obtener_tipo() << endl;
	cout << " Su superficie es de: " << forma->calcular_superficie() << " y su perimetro de: " << forma->calcular_perimetro() << endl << endl;
}

void eliminar_objeto(Lista &lista) {
	if (lista.obtener_longitud() <= 0) {
		msj_lista_vacia();
		return;
	}

	unsigned posicion = pedir_posicion(lista.obtener_longitud());
	lista.borrar(posicion);
}

void agregar_objeto(Lista &lista) {
	string tipo;
	bool tipo_valido = false;

	while (!tipo_valido) {
		cout << " A: Cuadrado, B: Rectangulo, C: Circulo, X: Cancelar" << endl;
		cout << " Tipo de forma: ";
		cin >> tipo;

		if (tipo.length() == 1 && (tipo == "A" || tipo == "B" || tipo == "C" || tipo == "X")) {
			tipo_valido = true;
		} else {
			cout << endl << " Por favor ingrese una forma valida" << endl;
		}
	}

	srand(time(nullptr));
	int numero = rand() % 1000;
	Figuras* figura;

	if (tipo == "A")
		figura = new Cuadrado(numero);
	else if (tipo == "B")
		figura = new Rectangulo(numero, numero % 11);
	else if (tipo == "C")
		figura = new Circulo(numero);
	else if (tipo == "X")
		return;

	lista.insertar(figura, lista.obtener_longitud() + 1);
}

void listar(Lista &lista) {
	if (lista.obtener_longitud() <= 0) {
		msj_lista_vacia();
		return;
	}

	cout << endl << " Listado de formas:" << endl;
	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		cout << " " << i << ". " << lista.consultar(i)->obtener_tipo() << endl;
	}
	cout << endl;
}

void superficie_max(Lista &lista) {
	if (lista.obtener_longitud() <= 0) {
		msj_lista_vacia();
		return;
	}

	double superficie_maxima = 0;
	Tipo* forma_mayor = 0;

	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		Tipo* forma = lista.consultar(i);
		double superficie = forma->calcular_superficie();

		if (superficie > superficie_maxima) {
			superficie_maxima = superficie;
			forma_mayor = forma;
		}
	}

	cout << endl << " El objeto con mayor superficie es un " << forma_mayor->obtener_tipo() << " y su valor es " << superficie_maxima << endl;
}

void superficie_min(Lista &lista) {
	double superficie_minima;
	Tipo* forma_menor;

	if (lista.obtener_longitud() > 0) {
		forma_menor = lista.consultar(1);
		superficie_minima = forma_menor->calcular_perimetro();
	} else {
		cout << endl << " No se encontro ninguna forma en la lista" << endl;
		return;
	}

	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		Tipo* forma = lista.consultar(i);
		double perimetro = forma->calcular_perimetro();

		if (perimetro < superficie_minima) {
			superficie_minima = perimetro;
			forma_menor = forma;
		}
	}

	cout << endl << " El objeto con menor superficie es un " << forma_menor->obtener_tipo() << " y su valor es " << superficie_minima << endl;
}

void perimetro_max(Lista &lista) {
	if (lista.obtener_longitud() <= 0) {
		msj_lista_vacia();
		return;
	}

	double perimetro_maximo = 0;
	Tipo* forma_mayor = 0;

	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		Tipo* forma = lista.consultar(i);
		double perimetro = forma->calcular_perimetro();

		if (perimetro > perimetro_maximo) {
			perimetro_maximo = perimetro;
			forma_mayor = forma;
		}
	}

	cout << endl << " El objeto con mayor perimetro es un " << forma_mayor->obtener_tipo() << " y su valor es " << perimetro_maximo << endl;
}

void perimetro_min(Lista &lista) {
	double perimetro_minimo;
	Tipo* forma_menor;

	if (lista.obtener_longitud() > 0) {
		forma_menor = lista.consultar(1);
		perimetro_minimo = forma_menor->calcular_perimetro();
	} else {
		cout << endl << " No se encontro ninguna forma en la lista" << endl;
		return;
	}

	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		Tipo* forma = lista.consultar(i);
		double perimetro = forma->calcular_perimetro();

		if (perimetro < perimetro_minimo) {
			perimetro_minimo = perimetro;
			forma_menor = forma;
		}
	}

	cout << endl << " El objeto con menor perimetro es un " << forma_menor->obtener_tipo() << " y su valor es " << perimetro_minimo << endl;
}
