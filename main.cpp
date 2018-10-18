#include <iostream>
#include "lista.h"

using namespace std;

void imprimir_menu();
int pedir_opcion();


int main() {
	imprimir_menu();
	pedir_opcion();
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