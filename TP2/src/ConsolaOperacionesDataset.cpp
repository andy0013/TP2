/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset(ProtecetedQueue& protecetedQueue):
    colaDeEjecuciones(protecetedQueue){
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[]) {
	int columnas = atoi(argv[2]);
	std::string nombreDataset = argv[1];
	while (this->solicitudUsuario.solicitarRequerimientosUsuario()) {
		LectorDeArchivo gestorDeDatos(nombreDataset,columnas,std::stoi(this->solicitudUsuario.columnaPorUsar));
		OperacionMonitor operacion;
		this->solicitudUsuario.prepararMonitorConValoresIngresadosPorUsuario(operacion);
		this->solicitudUsuario.crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,operacion,&gestorDeDatos);
		operacion.imprimirResultado();
		this->solicitudUsuario.prepararValoresParaNuevaSolicitud();
	}
	this->colaDeEjecuciones.closeTask();
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
