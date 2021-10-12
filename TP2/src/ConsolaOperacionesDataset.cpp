/*
 * Consola.cpp
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#include "ConsolaOperacionesDataset.h"

ConsolaOperacionesDataset::ConsolaOperacionesDataset() {
	this->solicitudUsuario = new ParserSolicitudUsuario();
	this->ejecutorSolicitudes = NULL;
}

void ConsolaOperacionesDataset::solicitarYDispararSolicitudUsuario(char *argv[]){
	while(this->solicitudUsuario->solicitarRequerimientosUsuario()){

		this->ejecutorSolicitudes = this->solicitudUsuario->crearSplitApplyCombineConInformacionIngresada(argv);

		this->ejecutorSolicitudes->SplitApplyCombineImplementarOperacion();

		this->imprimirValorAUsuario();
	}
}

ConsolaOperacionesDataset::~ConsolaOperacionesDataset() {

}



void ConsolaOperacionesDataset::imprimirValorAUsuario() {

	std::cout << this->ejecutorSolicitudes->SplitApplyCombineResultadoOperacion() << '\n';
}


