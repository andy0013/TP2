/*
 * SplitApplyCombineImpl.cpp
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#include "SplitApplyCombineImpl.h"

SplitApplyCombineImpl::SplitApplyCombineImpl(int filaInicio, int filaFin,
		const std::string operacion, int nroParticiones) {
	this->filaInicio = filaInicio;
	this->filaFin = filaFin;
	this->operacion = operacion;
	this->nroParticiones = nroParticiones;
	this->gestorDeDatos = NULL;
	this->particion = new OperacionStrategy();
}

void SplitApplyCombineImpl::cargarDatosParaResolverOperaciones(char *argv[],
		int columnaDondeOperar) {
	std::string nombreDataset = argv[1];
	int cantidadColumnas = strtol(argv[2], NULL, 10);
//	char *hilos = argv[3];
	this->gestorDeDatos = new LectorDeArchivo(nombreDataset, cantidadColumnas,
			columnaDondeOperar);
	this->gestorDeDatos->leerArchivoBinario();
	this->gestorDeDatos->situarLectorEnFilaInicial(this->filaInicio);
	this->particion->StrategyCrearOperacion(this->operacion);
}

void SplitApplyCombineImpl::SplitApplyCombineImplementarOperacion() {
	bool terminamosDeLeerParticiones = false;
	terminamosDeLeerParticiones = this->SplitApply(particion);
	while (!terminamosDeLeerParticiones) {
		OperacionStrategy *particionNueva = new OperacionStrategy();
		particionNueva->StrategyCrearOperacion(this->operacion);
		terminamosDeLeerParticiones = this->SplitApply(particionNueva);
		this->Combine(particion, particionNueva);
	}
}

bool SplitApplyCombineImpl::SplitApply(OperacionStrategy *name) {
	bool terminamosFilasValidas = false;
	for (int i = 0; i < this->nroParticiones; i++) {
		if (!this->gestorDeDatos->siguienteFilaValida(this->filaFin)) {
			terminamosFilasValidas = true;
			break;
		}
		int numeroLeido = this->gestorDeDatos->obtenerDatosDeArchivo();
		name->StrategyRealizarOperacion(numeroLeido);
	}
	return terminamosFilasValidas;
}

void SplitApplyCombineImpl::Combine(OperacionStrategy *particion,
		OperacionStrategy *nuevaParticion) {
	particion->StrategyCombineOperacion(nuevaParticion,
			this->filaFin - this->filaInicio);
}

int SplitApplyCombineImpl::SplitApplyCombineResultadoOperacion() {
	return this->particion->StrategyObtenerValorFinalOperacion();
}

SplitApplyCombineImpl::~SplitApplyCombineImpl() {
}

