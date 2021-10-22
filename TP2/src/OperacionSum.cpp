/*
 * OperacionSum.cpp
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#include "OperacionSum.h"

OperacionSum::OperacionSum(){
		this->valorActual = 0;
}

void OperacionSum::resolverOperacion(int valor){
	this->valorActual += valor;
}

void OperacionSum::combineOperacion(int valor, int particiones){
	this->resolverOperacion(valor);
}

int OperacionSum::obtenerValorActual(){
	return this->valorActual;
}

int OperacionSum::obtenerCantiadDeVAloresActual(){
		return 0;
}

void OperacionSum::obtenerValorFinal(){
	std::cout << this->valorActual << std::endl;
}


OperacionSum::~OperacionSum(){}

