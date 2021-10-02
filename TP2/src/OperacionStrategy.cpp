/*
 * OperacionStrategy.cpp
 *
 *  Created on: 1 oct. 2021
 *      Author: andres
 */

#include "OperacionStrategy.h"

OperacionStrategy::OperacionStrategy() {
	this->operacion = NULL;

}

void OperacionStrategy::StrategyCrearOperacion(std::string operacion){
	//no puedo usar un switch
	if(!operacion.compare("max")){
		this->operacion = new OperacionMax();
	}
	if(!operacion.compare("min")){
		this->operacion = new OperacionMin();
	}
	if(!operacion.compare("mean")){
		this->operacion = new OperacionMean();
	}
	if(!operacion.compare("sum")){
		this->operacion = new OperacionSuma();
	}
}

void OperacionStrategy::StrategyRealizarOperacion(int valor){
	this->operacion->resolverOperacion(valor);
}



OperacionStrategy::~OperacionStrategy() {
	// TODO Auto-generated destructor stub
}

