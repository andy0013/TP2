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
	this->ejecutorSolicitudes = NULL;
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(
		char *argv[]) {
	while (this->solicitudUsuario->solicitarRequerimientosUsuario()) {
		LectorDeArchivo *gestorDeDatos = new LectorDeArchivo("dataset", 4, 0);
//		this->solicitudUsuario->crearParticionesYEnviarALaQueue(this->colaDeEjecuciones,gestorDeDatos);


//		this->imprimirValorAUsuario();
	}
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {
}

void ConsolaOperacionesDataset::imprimirValorAUsuario() {
	std::cout
			<< this->ejecutorSolicitudes->SplitApplyCombineResultadoOperacion()
			<< '\n';
}
