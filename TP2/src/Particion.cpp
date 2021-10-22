/*
 * Particion.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "Particion.h"

Particion::Particion(OperacionMonitor &operacionMonitor) :
		monitor(operacionMonitor) {
	this->nroParticion = (-1);
	this->filasPorParticiones = 0;
	this->columna = 0;
	this->filaFinal = 0;
	this->filaInicial = 0;
}

Particion::Particion(OperacionMonitor &operacionMonitor,
		int filasPorParticiones, int nroPart, int filaFinal, int filaInicial,
		int columna) :
		monitor(operacionMonitor) {
	this->nroParticion = nroPart;
	this->columna = columna;
	this->filasPorParticiones = filasPorParticiones;
	this->filaFinal = filaFinal;
	this->filaInicial = filaInicial;
}

void Particion::execute(std::string dataset , int columnas) {
	LectorDeArchivo lector(dataset, columnas);
	this->monitor.splitApplyCombine(&lector, this->filasPorParticiones,
			this->filaInicial, this->nroParticion, this->filaFinal,
			this->columna);
}

bool Particion::isToken() {
	return this->nroParticion == (-1) ? true : false;
}

Particion::~Particion() {
}

