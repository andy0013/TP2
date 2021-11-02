/*
 * OperacionMonitor.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "ResultadoCompartidoMonitor.h"

ResultadoCompartidoMonitor::ResultadoCompartidoMonitor() {
	this->lecturaValida = true;
	this->filaFinal = 0;
}




void ResultadoCompartidoMonitor::crearInstanciaDeResultadoProtegidoParaLaSolicitudDeUsuario(std::string operacion) {
	this->operacion = operacion;
	OperacionStrategy *operacionPorGuardar = new OperacionStrategy();
	operacionPorGuardar->StrategyCrearOperacion(operacion);
	this->operacionCompartida.push_back(operacionPorGuardar);
}

void ResultadoCompartidoMonitor::guardarResultadosParciales(OperacionStrategy operacionParcial,int nroParticion){
	std::lock_guard<std::mutex> l(m);
	this->operacionCompartida[nroParticion]->StrategyCombineOperacion(
				&operacionParcial);
}

void ResultadoCompartidoMonitor::imprimirResultado() {
	for (size_t t = 0; t < this->operacionCompartida.size(); t++) {
		this->operacionCompartida[t]->StrategyImprimirValorFinalOperacion();
	}
}

ResultadoCompartidoMonitor::~ResultadoCompartidoMonitor() {
	for (size_t t = 0; t < this->operacionCompartida.size(); t++) {
		delete this->operacionCompartida[t];
	}
	this->operacionCompartida.clear();
}

