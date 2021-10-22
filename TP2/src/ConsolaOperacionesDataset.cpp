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
	int columnas = atoi(argv[2]);
	std::string nombreDataset = argv[1];
	int nroSolicitudUsuario = 0;
	std::string line;
	ParserSolicitudUsuario solicitudUsuario;
	MensajeroDeParticiones mensajero(solicitudUsuario);
	while (std::getline(std::cin, line)) {
		solicitudUsuario.parsearInputDeUsuario(line);
		LectorDeArchivo *gestorDeDatos = new LectorDeArchivo(nombreDataset,
				columnas,
				solicitudUsuario.obtenerColumnaPorUsarDelInputRecibido());
		mensajero.prepararMonitorConValoresIngresadosPorUsuario(operacion);
		mensajero.crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,
				operacion, gestorDeDatos, nroSolicitudUsuario);
		nroSolicitudUsuario++;
		if (nroSolicitudUsuario == 4)
			break;
	}
	mensajero.enviarToken(this->colaDeEjecuciones, operacion, NULL);
}

void ConsolaOperacionesDataset::imprimir() {
	this->operacion.imprimirResultado();
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}
