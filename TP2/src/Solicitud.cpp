/*
 * Solicitud.cpp
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#include "Solicitud.h"

Solicitud::Solicitud(int inicioDeFila,int finDeFila,int nroDeColumna,int nroDeParticion,std::string operacion) {
	this->finDeFila = finDeFila;
	this->inicioDeFila = inicioDeFila;
	this->nroDeColumna = nroDeColumna;
	this->nroDeParticiones = nroDeParticion;
	this->operacion = operacion;
}



Solicitud::~Solicitud() {
	// TODO Auto-generated destructor stub
}

