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
	this->operacionCompartida = OperacionStrategy();
}


void OperacionMonitor::datosIngresadosPorUser(int filaFinal,std::string operacion) {
	this->filaFinal = filaFinal;
	this->operacion = operacion;
	this->operacionCompartida.StrategyCrearOperacion(operacion);
}


void OperacionMonitor::splitApply(int filasPorParticiones,
		OperacionStrategy& operacionParcial, LectorDeArchivo *archivoPorUsar) {
	for (int i = 0; i < filasPorParticiones; i++) {
		if (this->lecturaValida) {
			operacionParcial.StrategyRealizarOperacion(
					archivoPorUsar->obtenerDatosDeArchivo());
		}
		this->lecturaValida = archivoPorUsar->siguienteFilaValida(
				this->filaFinal);
	}
}

void OperacionMonitor::splitApplyCombine(LectorDeArchivo* archivoPorUsar, int filasPorParticiones){
    std::lock_guard<std::mutex> l(m);
    OperacionStrategy operacionParcial;
    operacionParcial.StrategyCrearOperacion(this->operacion);
	this->splitApply(filasPorParticiones, operacionParcial, archivoPorUsar);
	this->combine(operacionParcial);
}

void OperacionMonitor::combine(OperacionStrategy operacionParcial){
	this->operacionCompartida.StrategyCombineOperacion(&operacionParcial);
}


void OperacionMonitor::imprimirResultado(){
	std::cout << this->operacionCompartida.StrategyObtenerValorFinalOperacion() << '\n';
}

OperacionMonitor::~OperacionMonitor() {
	// TODO Auto-generated destructor stub
}

