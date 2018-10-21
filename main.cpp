#include <iostream>
#include "lista.h"
#include "circulo.h"
#include "cuadrado.h"
#include "rectangulo.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void imprimir_menu();
int pedir_opcion();
void agregar_objeto(Lista &lista);
void listar(Lista &lista);

int main() {
	bool sigue = true;
	Lista formas;
	while (sigue) {
		imprimir_menu();
		int opcion = pedir_opcion();
		switch (opcion) {
			case 3:
				agregar_objeto(formas);
				break;
			case 4:
				listar(formas);
				break;
			default:
				sigue = false;
		}
	}
}

void agregar_objeto(Lista &lista) {
	string tipo;
	cout << "Tipo dato: ";
	cin >> tipo;
	if (tipo.length() != 1) {
		cin >> tipo;
	}

	srand(time(nullptr));
	int numero = rand() % 1000;
	if (tipo == "a") {
		Circulo* circulo = new Circulo(numero);
		lista.insertar(circulo, lista.obtener_longitud() + 1);
	} else if (tipo == "b") {
		Cuadrado* cuadrado = new Cuadrado(numero);
		lista.insertar(cuadrado, lista.obtener_longitud() + 1);
	} else if (tipo == "c") {
		Rectangulo* rectangulo = new Rectangulo(numero, numero % 11);
		lista.insertar(rectangulo, lista.obtener_longitud() + 1);
	}
}

void listar(Lista &lista) {
	cout << "Longitud: " << lista.obtener_longitud() << endl;
	for (int i = 1; i < lista.obtener_longitud() + 1; i++) {
		cout << lista.consultar(i)->obtener_tipo() << endl;
	}
}

void imprimir_menu() {
	cout << "\tFiguras y figuritas" << endl;
	cout << "\t___________________" << endl << endl;
	cout << " 1. Consultar posicion" << endl;
	cout << " 2. Eliminar objeto" << endl;
	cout << " 3. Agregar objeto" << endl;
	cout << " 4. Listar objetos" << endl;
	cout << " 5. Superficie maxima" << endl;
	cout << " 6. Superficie minima" << endl;
	cout << " 7. Perimetro maximo" << endl;
	cout << " 8. Perimetro minimo" << endl;
	cout << " 9. Salir" << endl << endl;
}

int pedir_opcion() {
	int opcion;
	cout << " Opcion: ";
	cin >> opcion;

	if (!cin.good()) { // Comprobar que sea un numero
		cin.clear();
		cin.ignore();
		cout << " Por favor ingrese un numero" << endl;
		return pedir_opcion();
	}

	if (opcion < 1 || opcion > 9) {
		cout << " Por favor ingrese un numero entre 1 y 9" << endl;
		return pedir_opcion();
	}

	return opcion;
}