#include <iostream>
#include <fstream>
#include "lista.h"
#include "operaciones.h"

using namespace std;

char const FINAL_STRING          = '\0';
int const POSICION_LETRA         = 0;
int const POSICION_DATO_NUMERICO = 2;
int const MINIMO_NUMERO_MENU     = 1;
int const MAXIMO_NUMERO_MENU     = 9;

//pre: -
//pos: imprime por pantalla el menu de opciones
void imprimir_menu ();

//pre: -
//pos: devuelve una opcion valida ingresada por el usuario 
int pedir_opcion ();

//pre: recibe la linea leida del archivo, la posicion desde la que se debe leer y el caracter que marca el final de la lectura y todos deben ser validos
//pos: devuelve el dato que se leyo 
double obtener_dato (string linea_leida, int *posicion_inicio, char final_lectura);

//pre: recibe la linea que se leyo en el archivo
//pos: crea la figura correspondiente a los datos leidos 
void pasar_datos (string linea_leida);

//pre: recibe una lista a ser cargada
//pos: carga la lista con los datos del archivo base
void cargar_lista (Lista *forma);

//pre: -
//pos: maneja el flujo del programa 
int main () {

	bool sigue = true;
	Lista formas;
	cargar_lista (&formas);

	while (sigue) {

		imprimir_menu ();
		int opcion = pedir_opcion ();
		system ("clear");

		switch (opcion) {
			case 1:
				consultar_posicion (formas);
				break;
			case 2:
				eliminar_objeto (formas);
				break;
			case 3:
				agregar_objeto (formas);
				break;
			case 4:
				listar (formas);
				break;
			case 5:
				superficie_max (formas);
				break;
			case 6:
				superficie_min (formas);
				break;
			case 7:
				perimetro_max (formas);
				break;
			case 8:
				perimetro_min (formas);
				break;
			default:
				sigue = false;
		}

	}

}

void imprimir_menu () {
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

int pedir_opcion () {
	int opcion;
	cout << " Opcion: ";
	cin >> opcion;

	if (!cin.good ()) { // Comprobar que sea un numero
		cin.clear ();
		cin.ignore ();
		cout << " Por favor ingrese un numero" << endl;
		return pedir_opcion();
	}

	if (opcion < MINIMO_NUMERO_MENU || opcion > MAXIMO_NUMERO_MENU) {
		cout << " Por favor ingrese un numero entre 1 y 9" << endl;
		return pedir_opcion();
	}

	return opcion;
}

double obtener_dato (string linea_leida, int *posicion_inicio, char final_lectura){

	int  contador = 0;
	string dato_leido;
	double medida_leida;

  while(linea_leida[*posicion_inicio] != final_lectura){

		dato_leido[contador] = linea_leida[*posicion_inicio];
    contador++;
    (*posicion_inicio)++;

	}

	medida_leida = atof(dato_leido.c_str());
  return medida_leida;
}

void pasar_datos (string linea_leida, Lista *forma){

	int posicion_inicio = POSICION_DATO_NUMERICO;

	if (informacion[POSICION_LETRA] == 'A') {
		double lado = obtener_dato(informacion, &posicion_inicio, FINAL_STRING);
		Figura* figura_cuadrada = new Cuadrado(lado);
		forma->insertar(figura_cuadrada, forma->obtener_longitud() + 1);
	} else if (informacion[POSICION_LETRA] == 'B') {
		double altura = obtener_dato (informacion, &posicion_inicio, ' ');
		double base = obtener_dato (informacion, &posicion_inicio, FINAL_STRING);
		Figura* figura_rectangular = new Rectangulo (altura, base);
		forma->insertar (figura_rectangular, forma->obtener_longitud() + 1);
	} else if (informacion[POSICION_LETRA] == 'C') {
		double radio = obtener_dato(informacion, &posicion_inicio, FINAL_STRING);
		Figura* figura_circular = new Circulo(radio);
		forma->insertar(figura_circular, forma->obtener_longitud() + 1);
	}

}

void cargar_lista (Lista *forma){

	ifstream archivo;
	string linea_leida;
	archivo.open ("figuras.txt");

	while(!archivo.eof ()){

		getline (archivo, linea_leida);
		pasar_datos (linea_leida,forma);

	}

	archivo.close ();
}
