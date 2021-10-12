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

void OperacionStrategy::StrategyCrearOperacion(std::string operacion) {
	//no puedo usar un switch
	if (!strcmp("max", operacion.c_str())) {
		this->operacion = new OperacionMax();
	}
	if (!strcmp("min", operacion.c_str())) {
		this->operacion = new OperacionMin();
	}
	if (!strcmp("mean", operacion.c_str())) {
		this->operacion = new OperacionMean();
	}
	if (!strcmp("sum", operacion.c_str())) {
		this->operacion = new OperacionSuma();
	}
}

void OperacionStrategy::StrategyRealizarOperacion(int valor) {
	this->operacion->resolverOperacion(valor);
}

int OperacionStrategy::StrategyObtenerValorOperacion() {
	return this->operacion->obtenerValorActual();
}

int OperacionStrategy::StrategyObtenerValorFinalOperacion() {
	return this->operacion->obtenerValorFinal();
}

void OperacionStrategy::StrategyCombineOperacion(
		OperacionStrategy *particionNueva, int nroParticiones) {
	this->operacion->combineOperacion(
			particionNueva->StrategyObtenerValorOperacion(), nroParticiones);
}

OperacionStrategy::~OperacionStrategy() {
	// TODO Auto-generated destructor stub
}

