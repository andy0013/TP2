/*
 * SplitApplyCombineImpl.cpp
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#include "SplitApplyCombineImpl.h"

SplitApplyCombineImpl::SplitApplyCombineImpl(int filaInicio, int filaFin, std::string operacion, int nroParticiones) {
	this->filaInicio = filaInicio;
	this->filaFin = filaFin;
	this->operacion = operacion;
	this->nroParticiones = nroParticiones;
	this->gestorDeDatos = NULL;
}

void SplitApplyCombineImpl::cargarDatosParaResolverOperaciones(std::string nombreDataset, int cantidadColumnas, int columnaDondeOperar){
	this->gestorDeDatos = new LectorDeArchivo(nombreDataset,cantidadColumnas,columnaDondeOperar);
	this->gestorDeDatos->leerArchivoBinario();
}


void SplitApplyCombineImpl::SplitApplyCombineImplementarOperacion(){
	OperacionStrategy* name = new OperacionStrategy();
	for(int i = 0; i < this->nroParticiones; i++){
		int numeroLeido = this->gestorDeDatos->obtenerDatosDeArchivo();
		name->StrategyCrearOperacion(this->operacion);

	}
}


SplitApplyCombineImpl::~SplitApplyCombineImpl() {
}

