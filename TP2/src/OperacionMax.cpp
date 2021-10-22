/*
 * OperacionMax.cpp
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#include "OperacionMax.h"

OperacionMax::OperacionMax() {
		this->valorActual = 0;
}

void OperacionMax::resolverOperacion(int valor) {
	if(valor > this->valorActual){
		this->valorActual = valor;
	}
}

void OperacionMax::combineOperacion(int valor, int particiones){
	this->resolverOperacion(valor);
}

int OperacionMax::obtenerValorActual(){
	return this->valorActual;
}

int OperacionMax::obtenerCantiadDeVAloresActual(){
		return 0;
}

void OperacionMax::obtenerValorFinal(){
	std::cout << this->valorActual << std::endl;
}


OperacionMax::~OperacionMax() {
	// TODO Auto-generated destructor stub
}

