/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset(
		ColaProtegida &protecetedQueue) :
		colaDeEjecuciones(protecetedQueue) {
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[],OperacionMonitor& resultadoProtegido) {
	int nroSolicitudUsuario = 0;
	std::string line;
	ParserSolicitudUsuario solicitudUsuario;
	MensajeroDeParticiones mensajero(solicitudUsuario);
	while (std::getline(std::cin, line)) {
		solicitudUsuario.parsearInputDeUsuario(line);
		resultadoProtegido.crearInstanciaDeResultadoProtegidoParaLaSolicitudDeUsuario(solicitudUsuario.obtenerOperacionDelInputRecibido());
		mensajero.crearParticionesYEnviarALaQueue(this->colaDeEjecuciones, nroSolicitudUsuario);
		nroSolicitudUsuario++;
		if(nroSolicitudUsuario==4)
			break;
	}
	mensajero.enviarToken(this->colaDeEjecuciones);
}


ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
