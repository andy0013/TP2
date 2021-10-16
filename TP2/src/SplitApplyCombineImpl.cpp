/*
 * SplitApplyCombineImpl.cpp
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#include "SplitApplyCombineImpl.h"

SplitApplyCombineImpl::SplitApplyCombineImpl(int filaInicio, int filaFin,
		OperacionStrategy* operacionPorUsar, int nroParticiones) {
	this->filaInicio = filaInicio;
	this->filaFin = filaFin;
	this->nroParticiones = nroParticiones;
	this->gestorDeDatos = NULL;
	this->hilos = 0;
	this->operacionStrategy = operacionPorUsar;
}

void SplitApplyCombineImpl::cargarDatosParaResolverOperaciones(char *argv[],
		int columnaDondeOperar) {
	std::string nombreDataset = argv[1];
	int cantidadColumnas = strtol(argv[2], NULL, 10);
	this->hilos = strtol(argv[3], NULL, 10);
	this->gestorDeDatos = new LectorDeArchivo(nombreDataset, cantidadColumnas,
			columnaDondeOperar);
	this->gestorDeDatos->leerArchivoBinario();
	this->gestorDeDatos->situarLectorEnFilaInicial(this->filaInicio);
}

void SplitApplyCombineImpl::SplitApplyCombineImplementarOperacion() {
	bool terminamosDeLeerParticiones = false;
	OperacionMonitor colaDeEjecuciones(this->operacionStrategy);
	std::vector<std::thread*> threads;
	while(this->gestorDeDatos->siguienteFilaValida(this->filaFin)){
		std::vector<Particion> counters;
		for(int i = 0; i < hilos ; i++){
			Particion particion(colaDeEjecuciones, this->gestorDeDatos,this->nroParticiones);
			counters.push_back(particion);
		}
		for(size_t i = 0; i < counters.size() ; i++){
			threads.push_back(new std::thread(std::ref(counters[i])));
		}

		for(size_t i = 0; i < threads.size() ; i++){
			threads[i]->join();
		}
	}
	colaDeEjecuciones.imprimirResultado();
}

//bool SplitApplyCombineImpl::SplitApply(OperacionStrategy *name) {
//	bool terminamosFilasValidas = false;
//	for (int i = 0; i < this->nroParticiones; i++) {
//		if (!this->gestorDeDatos->siguienteFilaValida(this->filaFin)) {
//			terminamosFilasValidas = true;
//			break;
//		}
//		int numeroLeido = this->gestorDeDatos->obtenerDatosDeArchivo();
//		name->StrategyRealizarOperacion(numeroLeido);
//	}
//	return terminamosFilasValidas;
//}

//void SplitApplyCombineImpl::Combine(OperacionStrategy *particion,
//		OperacionStrategy *nuevaParticion) {
//	particion->StrategyCombineOperacion(nuevaParticion,
//			this->filaFin - this->filaInicio);
//}

int SplitApplyCombineImpl::SplitApplyCombineResultadoOperacion() {
//	return this->StrategyObtenerValorFinalOperacion();
}

SplitApplyCombineImpl::~SplitApplyCombineImpl() {
}

