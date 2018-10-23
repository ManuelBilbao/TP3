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

void consultar_posicion(Lista &lista);
void eliminar_objeto(Lista &lista);
void agregar_objeto(Lista &lista);
void listar(Lista &lista);
void superficie_max(Lista &lista);
void superficie_min(Lista &lista);
void perimetro_max(Lista &lista);
void perimetro_min(Lista &lista);

#endif
