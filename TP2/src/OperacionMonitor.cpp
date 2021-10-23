/*
 * OperacionMonitor.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "OperacionMonitor.h"

OperacionMonitor::OperacionMonitor() {
	this->lecturaValida = true;
	this->filaFinal = 0;
}

void OperacionMonitor::datosIngresadosPorUser(int filaFinal,
		std::string operacion) {
	std::lock_guard<std::mutex> l(m);
	this->filaFinal = filaFinal;
	this->operacion = operacion;
	OperacionStrategy *operacionPorGuardar = new OperacionStrategy();
	operacionPorGuardar->StrategyCrearOperacion(operacion);
	this->operacionCompartida.push_back(operacionPorGuardar);
}

void OperacionMonitor::splitApply(int filasPorParticiones,
		OperacionStrategy &operacionParcial,int filaFinal,
		int filaInicial, int columna,std::string dataset,int columnas) {
	LectorDeArchivo archivoPorUsar(std::move(dataset), std::move(columnas));
	archivoPorUsar.situarLectorEnFilaInicial(filaInicial);
	for (int i = 0; i < filasPorParticiones; i++) {
		int fila = i + filaInicial;
		if (fila < filaFinal)
			operacionParcial.StrategyRealizarOperacion(
					archivoPorUsar.obtenerDatosDeArchivo(columna));
	}
}

void OperacionMonitor::splitApplyCombine(std::string dataset, int columnas,
		int filasPorParticiones, int filaInicial, int particion, int filaFinal,
		int columna) {
	std::lock_guard<std::mutex> l(m);
	OperacionStrategy operacionParcial;
	this->operacionCompartida[particion]->StrategyCrearOperacionParcial(
			&operacionParcial);
	this->splitApply(std::move(filasPorParticiones), operacionParcial,
			std::move(filaFinal), std::move(filaInicial),
			std::move(columna),std::move(dataset), std::move(columnas));
	this->combine(std::move(operacionParcial), std::move(particion));
}

void OperacionMonitor::combine(OperacionStrategy operacionParcial,
		int nroParticion) {
	this->operacionCompartida[nroParticion]->StrategyCombineOperacion(
			&operacionParcial);
}

void OperacionMonitor::imprimirResultado() {
	std::lock_guard<std::mutex> l(m);
	for (size_t t = 0; t < this->operacionCompartida.size(); t++) {
		this->operacionCompartida[t]->StrategyImprimirValorFinalOperacion();
	}
}

OperacionMonitor::~OperacionMonitor() {
	for (size_t t = 0; t < this->operacionCompartida.size(); t++) {
		delete this->operacionCompartida[t];
	}
	this->operacionCompartida.clear();
}

