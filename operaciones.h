#ifndef OPERACIONES_H
#define OPERACIONES_H

#include "lista.h"
#include "circulo.h"
#include "cuadrado.h"
#include "rectangulo.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Pre: recibe una lista
//Pos: imprime por pantalla que figura se encuentra en esa posicion de la lista
void consultar_posicion(Lista &lista);

//Pre: recibe una lista 
//Pos: elimina el objeto de la lista que se encuentra en la posicion indicada 
void eliminar_objeto(Lista &lista);

//Pre: recibe una lista
//Pos: agrega un abjeto en la lista en la posicion indicada
void agregar_objeto(Lista &lista);

//Pre: recibe una lista
//Pos: imprime por pantalla la lista
void listar(Lista &lista);

//Pre: recibe una lista
//Pos: calcula que elemento de la lista tiene la mayor superficie mostrando el mismo por pantalla
void superficie_max(Lista &lista);

//Pre: recibe una lista
//Pos: calcula que elemento de la lista tiene la menor superficie mostrando el mismo por pantalla
void superficie_min(Lista &lista);

//Pre: recibe una lista
//Pos: calcula que elemento de la lista tiene el mayor perimetro mostrando el mismo por pantalla
void perimetro_max(Lista &lista);

//Pre: recibe una lista
//Pos: calcula que elemento de la lista tiene el menor perimetro mostrando el mismo por pantalla
void perimetro_min(Lista &lista);

#endif