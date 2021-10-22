/*
 * OperacionMin.cpp
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#include "OperacionMin.h"

OperacionMin::OperacionMin() {
		this->valorActual = 10000000;
}

void OperacionMin::resolverOperacion(int valor){
	if (valor == 0){
		this->valorActual = valor;
	}else if (this->valorActual > valor){
		this->valorActual = valor;
	}
}

void OperacionMin::combineOperacion(int valor, int particiones){
	this->resolverOperacion(valor);
}

int OperacionMin::obtenerValorActual(){
	return this->valorActual;
}

int OperacionMin::obtenerCantiadDeVAloresActual(){
	return 0;
}

void OperacionMin::obtenerValorFinal(){
	std::cout << this->valorActual << std::endl;
}


OperacionMin::~OperacionMin() {}

