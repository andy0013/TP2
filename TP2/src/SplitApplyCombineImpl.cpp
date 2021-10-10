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
	this->gestorDeDatos->situarLectorEnFilaInicial(this->filaInicio);
}


void SplitApplyCombineImpl::SplitApplyCombineImplementarOperacion(){
	OperacionStrategy* name = new OperacionStrategy();
	name->StrategyCrearOperacion(this->operacion);
	this->SplitApply(name);
}

void SplitApplyCombineImpl::SplitApply(OperacionStrategy* name){
	for(int i = 0; i < this->nroParticiones; i++){
		if(!this->gestorDeDatos->siguienteFilaValida(this->filaFin))
			break;
		int numeroLeido = this->gestorDeDatos->obtenerDatosDeArchivo();
		name->StrategyRealizarOperacion(numeroLeido);
	}
}

void SplitApplyCombineImpl::Combine(OperacionStrategy* name){

}


SplitApplyCombineImpl::~SplitApplyCombineImpl() {
}

