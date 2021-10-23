/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset(
		ProtecetedQueue &protecetedQueue) :
		colaDeEjecuciones(protecetedQueue) {
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[]) {
	int nroSolicitudUsuario = 0;
	std::string line;
	ParserSolicitudUsuario solicitudUsuario;
	MensajeroDeParticiones mensajero(solicitudUsuario);
	while (std::getline(std::cin, line)) {
		solicitudUsuario.parsearInputDeUsuario(line);
		mensajero.prepararMonitorConValoresIngresadosPorUsuario(operacion);
		mensajero.crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,
				operacion, nroSolicitudUsuario);
		nroSolicitudUsuario++;
	}
	mensajero.enviarToken(this->colaDeEjecuciones);
}

void ConsolaOperacionesDataset::imprimir() {
	this->operacion.imprimirResultado();
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
