/*
 * Particion.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "Particion.h"

Particion::Particion(OperacionMonitor& operacionMonitor):monitor(operacionMonitor){
	this->archivo = NULL;
	this->i = (-1);
	this->filasPorParticiones = 0;
	this->filaFinal = 0;
	this->filaInicial = 0;
}


Particion::Particion(OperacionMonitor& operacionMonitor,LectorDeArchivo* archivo,int filasPorParticiones,int ii,int filaFinal,int filaInicial):
	monitor(operacionMonitor){
	this->archivo = archivo;
	this->i = ii;
	this->filasPorParticiones = filasPorParticiones;
	this->filaFinal = filaFinal;
	this->filaInicial = filaInicial;
}


void Particion::execute() {
	this->monitor.splitApplyCombine(this->archivo,this->filasPorParticiones,this->filaInicial,this->i,this->filaFinal);
}

bool Particion::isToken(){
	return this->i == (-1) ? true : false;
}



Particion::~Particion() {
	// TODO Auto-generated destructor stub
}

