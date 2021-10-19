/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset(ProtecetedQueue& protecetedQueue):
    colaDeEjecuciones(protecetedQueue){
	this->solicitudUsuario = new ParserSolicitudUsuario();
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[]) {
	while (this->solicitudUsuario->solicitarRequerimientosUsuario()) {
		LectorDeArchivo* gestorDeDatos = new LectorDeArchivo("dataset", 4, 0);
		OperacionMonitor operacion(15);
		this->solicitudUsuario->crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,operacion,gestorDeDatos);
		operacion.imprimirResultado();
	}
	this->colaDeEjecuciones.closeTask();
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
