/*
 * OperacionMonitor.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "OperacionMonitor.h"

OperacionMonitor::OperacionMonitor(int filaFinal) {
	this->lecturaValida = true;
	this->filaFinal = filaFinal;
	this->operacionCompartida = OperacionStrategy();
}

void OperacionMonitor::splitApply(int filasPorParticiones,
		OperacionStrategy operacionParcial, LectorDeArchivo *archivoPorUsar) {
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
	splitApply(filasPorParticiones, operacionParcial, archivoPorUsar);

}

void OperacionMonitor::combine(OperacionStrategy operacionParcial){
	this->operacionCompartida.StrategyCombineOperacion(&operacionParcial, 15);
}


void OperacionMonitor::imprimirResultado(){
	std::cout << this->operacionCompartida.StrategyObtenerValorFinalOperacion();
}

OperacionMonitor::~OperacionMonitor() {
	// TODO Auto-generated destructor stub
}

