#include <iostream>
#include <fstream>
#include "lista.h"
#include "operaciones.h"

using namespace std;

void imprimir_menu();
int pedir_opcion();
double obtener_dato (string informacion, int *posicion_inicio, char final_lectura);
void pasar_datos (string informacion);
void cargar_lista(Lista *forma);



int main() {
	bool sigue = true;
	Lista formas;
	cargar_lista(&formas);
	while (sigue) {
		imprimir_menu();
		int opcion = pedir_opcion();
		system("clear");
		switch (opcion) {
			case 1:
				consultar_posicion(formas);
				break;
			case 2:
				eliminar_objeto(formas);
				break;
			case 3:
				agregar_objeto(formas);
				break;
			case 4:
				listar(formas);
				break;
			case 5:
				superficie_max(formas);
				break;
			case 6:
				superficie_min(formas);
				break;
			case 7:
				perimetro_max(formas);
				break;
			case 8:
				perimetro_min(formas);
				break;
			default:
				sigue = false;
		}
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



double obtener_dato(string info, int *posicion_inicio, char final_lectura){
int  cont2 = 0;
string dato;
double numero=1;
  while(info[*posicion_inicio]!= final_lectura){
    dato[cont2]=info[*posicion_inicio];
    cont2++;
    (*posicion_inicio)++;
  }
	numero = atof(dato.c_str());
  return numero;
}

void pasar_datos (string informacion, Lista *forma){
	int posicion_inicio;
	switch (informacion[0]) {
     case 'A':{
			 posicion_inicio = 2;
			 Figuras* figura = new Cuadrado (obtener_dato(informacion, &posicion_inicio,'\0'));
			 forma->insertar(figura,forma->obtener_longitud()+1);
    	 break;
     }case 'B':{
			 posicion_inicio = 2;
			 double altura = obtener_dato(informacion, &posicion_inicio,' ');
			 double base = obtener_dato(informacion, &posicion_inicio,'\0');
			 Figuras* figura = new Rectangulo(altura, base);
			 forma->insertar(figura,forma->obtener_longitud()+1);
			 break;
	   }case 'C':{
			 posicion_inicio = 2;
			 Figuras* figura = new Circulo (obtener_dato(informacion, &posicion_inicio,'\0'));
			 forma->insertar(figura,forma->obtener_longitud()+1);
       break;
     }
	}

}

void cargar_lista (Lista *forma){
	ifstream archivo;
	string informacion;
	archivo.open("figuras.txt");
	while(!archivo.eof()){
		getline(archivo, informacion);
		std::cout << informacion << '\n';
		pasar_datos(informacion,forma);
	}

	archivo.close();
}
