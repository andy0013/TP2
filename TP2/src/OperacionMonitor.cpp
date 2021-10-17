/*
 * OperacionMonitor.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "OperacionMonitor.h"

OperacionMonitor::OperacionMonitor(OperacionStrategy* strat,int filaFinal) {
	this->lecturaValida = true;
	this->filaFinal = filaFinal;
	this->operacion = strat;
}

void OperacionMonitor::cargarDatosParaOperacionSiEsNecesario(LectorDeArchivo* archivoPorUsar, int filasPorParticiones){
    std::lock_guard<std::mutex> l(m);
    for(int i = 0; i < filasPorParticiones ; i++){
		if(this->lecturaValida){
			this->operacion->StrategyRealizarOperacion(archivoPorUsar->obtenerDatosDeArchivo());
		}
		this->lecturaValida = archivoPorUsar->siguienteFilaValida(this->filaFinal);
    }
}

void OperacionMonitor::imprimirResultado(){
	std::cout << this->operacion->StrategyObtenerValorFinalOperacion();
}

OperacionMonitor::~OperacionMonitor() {
	// TODO Auto-generated destructor stub
}

