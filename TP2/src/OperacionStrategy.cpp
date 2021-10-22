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
	this->tipoDeOperacion = operacion;
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
		this->operacion = new OperacionSum();
	}
}

void OperacionStrategy::StrategyRealizarOperacion(int valor) {
	this->operacion->resolverOperacion(valor);
}

int OperacionStrategy::StrategyObtenerValorOperacion() {
	return this->operacion->obtenerValorActual();
}

void OperacionStrategy::StrategyImprimirValorFinalOperacion() {
	this->operacion->obtenerValorFinal();
}

int OperacionStrategy::StrategyObtenerCantidadDeFilasUsadasParcial() {
	return this->operacion->obtenerCantiadDeVAloresActual();
}

void OperacionStrategy::StrategyCrearOperacionParcial(OperacionStrategy* particionNueva){
	particionNueva->StrategyCrearOperacion(this->tipoDeOperacion);
}


void OperacionStrategy::StrategyCombineOperacion(
		OperacionStrategy *particionNueva) {
	this->operacion->combineOperacion(
			particionNueva->StrategyObtenerValorOperacion(),
			particionNueva->StrategyObtenerCantidadDeFilasUsadasParcial());
}

OperacionStrategy::~OperacionStrategy() {
	delete this->operacion;
}

