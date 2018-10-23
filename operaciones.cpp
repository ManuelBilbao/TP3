#include "operaciones.h"
#include <iomanip>

const string ESQUINA_SUPERIOR_IZQUIERDA = "\u250C";
const string ESQUINA_SUPERIOR_DERECHA = "\u2510";
const string ESQUINA_INFERIOR_IZQUIERDA = "\u2514";
const string ESQUINA_INFERIOR_DERECHA = "\u2518";
const string LINEA_HORIZONTAL = "\u2500";
const string LINEA_VERTICAL = "\u2502";
const string LINEA_HORIZONTAL_UNION_SUPERIOR = "\u252C";
const string LINEA_HORIZONTAL_UNION_INFERIOR = "\u2534";
const string LINEA_VERTICAL_UNION_IZQUIERDA = "\u251C";
const string LINEA_VERTICAL_UNION_DERECHA = "\u2524";
const string CRUZ = "\u253C";

const int LONG_TIPO = 16;
const int LONG_PERIMETRO = 20;
const int LONG_SUPERFICIE = 20;

const int CANTIDAD_DECIMALES = 4;

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

int contar_cifras(double numero) {
	string str_numero = to_string(numero);
	return str_numero.find(".") + CANTIDAD_DECIMALES + 1;
}

void dibujar_cabecera_tabla() {
	// Primer fila (Borde)
	cout << ESQUINA_SUPERIOR_IZQUIERDA;
	for (int i = 0; i < LONG_TIPO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << LINEA_HORIZONTAL_UNION_SUPERIOR;
	for (int i = 0; i < LONG_PERIMETRO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << LINEA_HORIZONTAL_UNION_SUPERIOR;
	for (int i = 0; i < LONG_SUPERFICIE; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << ESQUINA_SUPERIOR_DERECHA << endl;

	// Segunda fila (Titulos)
	cout << LINEA_VERTICAL;
	cout << "Tipo:";
	for (int i = 0; i < LONG_TIPO - 5; i++) {
		cout << " ";
	}
	cout << LINEA_VERTICAL;
	cout << "Perimetro:";
	for (int i = 0; i < LONG_PERIMETRO - 10; i++) {
		cout << " ";
	}
	cout << LINEA_VERTICAL;
	cout << "Superficie:";
	for (int i = 0; i < LONG_SUPERFICIE - 11; i++) {
		cout << " ";
	}
	cout << LINEA_VERTICAL << endl;

	// Tercer fila (separador header)
	cout << LINEA_VERTICAL_UNION_IZQUIERDA;
	for (int i = 0; i < LONG_TIPO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << CRUZ;
	for (int i = 0; i < LONG_PERIMETRO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << CRUZ;
	for (int i = 0; i < LONG_SUPERFICIE; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << LINEA_VERTICAL_UNION_DERECHA << endl;
}

void dibujar_filas_tabla(Tipo* forma) {
	cout << LINEA_VERTICAL;
	cout << forma->obtener_tipo();
	for (int i = 0; i < LONG_TIPO - (forma->obtener_tipo()).length(); i++) {
		cout << " ";
	}
	cout << fixed << setprecision(CANTIDAD_DECIMALES);
	cout << LINEA_VERTICAL;
	cout << forma->calcular_perimetro();
	int resto = contar_cifras(forma->calcular_perimetro());
	for (int i = 0; i < LONG_PERIMETRO - resto; i++) {
		cout << " ";
	}
	cout << LINEA_VERTICAL;
	cout << forma->calcular_superficie();
	resto = contar_cifras(forma->calcular_superficie());
	for (int i = 0; i < LONG_SUPERFICIE - resto; i++) {
		cout << " ";
	}
	cout << LINEA_VERTICAL;
	cout << endl;
}

void dibujar_fin_tabla() {
	cout << ESQUINA_INFERIOR_IZQUIERDA;
	for (int i = 0; i < LONG_TIPO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << LINEA_HORIZONTAL_UNION_INFERIOR;
	for (int i = 0; i < LONG_PERIMETRO; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << LINEA_HORIZONTAL_UNION_INFERIOR;
	for (int i = 0; i < LONG_SUPERFICIE; i++) {
		cout << LINEA_HORIZONTAL;
	}
	cout << ESQUINA_INFERIOR_DERECHA << endl;
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
	dibujar_cabecera_tabla();
	for (unsigned i = 1; i < lista.obtener_longitud() + 1; i++) {
		dibujar_filas_tabla(lista.consultar(i));
		// cout << " " << i << ". " << lista.consultar(i)->obtener_tipo() << endl;
	}
	dibujar_fin_tabla();
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
