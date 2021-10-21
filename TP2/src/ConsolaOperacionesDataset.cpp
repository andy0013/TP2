/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

#include <cstdlib>

#include "LectorDeArchivo.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset(ProtecetedQueue& protecetedQueue):
    colaDeEjecuciones(protecetedQueue){
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[]) {
	int columnas = atoi(argv[2]);
	std::string nombreDataset = argv[1];
	OperacionMonitor operacion;
	int i = 0;
//	while (this->solicitudUsuario.solicitarRequerimientosUsuario()) {
//		LectorDeArchivo gestorDeDatos(nombreDataset,columnas,std::stoi(this->solicitudUsuario.columnaPorUsar));
	for (int t = 0; t < 5; t++) {
		this->solicitudUsuario.solicitarRequerimientosUsuario();
		LectorDeArchivo* gestorDeDatos = new LectorDeArchivo(nombreDataset,columnas,std::stoi(this->solicitudUsuario.columnaPorUsar));
		this->solicitudUsuario.prepararMonitorConValoresIngresadosPorUsuario(operacion);
		this->solicitudUsuario.crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,operacion,gestorDeDatos,i);
		this->solicitudUsuario.prepararValoresParaNuevaSolicitud();
		i++;
	}
	LectorDeArchivo* gestorDeDatos = new LectorDeArchivo(nombreDataset,columnas,0);
	this->solicitudUsuario.enviarToken(this->colaDeEjecuciones,operacion,gestorDeDatos,i);
	operacion.imprimirResultado();
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
