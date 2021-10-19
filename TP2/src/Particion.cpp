/*
 * Particion.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "Particion.h"

Particion::Particion(OperacionMonitor& operacionMonitor,LectorDeArchivo* archivo,int filasPorParticiones):
	monitor(operacionMonitor){
	this->archivo = archivo;
	this->filasPorParticiones = filasPorParticiones;
}


void Particion::execute() {
	this->monitor.splitApplyCombine(this->archivo,this->filasPorParticiones);
}



Particion::~Particion() {
	// TODO Auto-generated destructor stub
}

