/*
 * OperacionMean.cpp
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#include "OperacionMean.h"

OperacionMean::OperacionMean() {
	this->cantidadDeValores = 0;
	this->valorActual = 0;
}

void OperacionMean::resolverOperacion(int valor){
	this->valorActual += valor;
	this->cantidadDeValores++;
}

void OperacionMean::combineOperacion(int valor, int particiones){
	this->cantidadDeValores += particiones;
	this->valorActual += valor;
}

int OperacionMean::obtenerValorActual(){
	return this->valorActual;
}

int OperacionMean::obtenerCantiadDeVAloresActual(){
	return this->cantidadDeValores;
}

int OperacionMean::obtenerValorFinal(){
	return (this->valorActual/this->cantidadDeValores);
}

OperacionMean::~OperacionMean() {
	// TODO Auto-generated destructor stub
}

