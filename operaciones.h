#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "lista.h"
#include "circulo.h"
#include "cuadrado.h"
#include "rectangulo.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Pre:
//Post:
void consultar_posicion(Lista &lista);

//Pre:
//Post:
void eliminar_objeto(Lista &lista);

//Pre:
//Post:
void agregar_objeto(Lista &lista);

//Pre:
//Post:
void listar(Lista &lista);

//Pre:
//Post:
void superficie_max(Lista &lista);

//Pre:
//Post:
void superficie_min(Lista &lista);

//Pre:
//Post:
void perimetro_max(Lista &lista);

//Pre:
//Post:
void perimetro_min(Lista &lista);

#endif
