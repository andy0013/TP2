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
	this->filaFinal = filaFinal;
	this->operacion = operacion;
	OperacionStrategy operacionPorGuardar;
	operacionPorGuardar.StrategyCrearOperacion(operacion);
	this->operacionCompartida.push_back(operacionPorGuardar);
}

void OperacionMonitor::splitApply(int filasPorParticiones,
		OperacionStrategy &operacionParcial, LectorDeArchivo *archivoPorUsar,
		int filaFinal, int filaInicial,int columna) {
	archivoPorUsar->situarLectorEnFilaInicial(filaInicial);
	for (int i = 0; i < filasPorParticiones; i++) {
		int fila = i + filaInicial;
		if (fila < filaFinal)
			operacionParcial.StrategyRealizarOperacion(
					archivoPorUsar->obtenerDatosDeArchivo(columna));
	}
}

void OperacionMonitor::splitApplyCombine(LectorDeArchivo *archivoPorUsar,
		int filasPorParticiones, int filaInicial, int particion,
		int filaFinal,int columna) {
	std::lock_guard<std::mutex> l(m);
	OperacionStrategy operacionParcial;
	this->operacionCompartida[particion].StrategyCrearOperacionParcial(&operacionParcial);
	this->splitApply(filasPorParticiones, operacionParcial, archivoPorUsar,
			filaFinal, filaInicial,columna);
	this->combine(operacionParcial, particion);
}

void OperacionMonitor::combine(OperacionStrategy &operacionParcial, int i) {
	this->operacionCompartida[i].StrategyCombineOperacion(&operacionParcial);
}

void OperacionMonitor::imprimirResultado() {
	std::lock_guard<std::mutex> l(m);
	for (int t = 0; t < 5; t++) {
		this->operacionCompartida[t]
					.StrategyImprimirValorFinalOperacion();
	}
}

OperacionMonitor::~OperacionMonitor() {
	// TODO Auto-generated destructor stub
}

