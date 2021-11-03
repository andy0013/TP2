/*
 * Particion.cpp
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#include "Particion.h"

Particion::Particion() {
	this->nroParticion = (-1);
	this->filasPorParticiones = 0;
	this->columna = 0;
	this->filaFinal = 0;
	this->filaInicial = 0;
}

Particion::Particion(int filasPorParticiones, int nroPart, int filaFinal,
		int filaInicial, int columna,
		std::string operacionPorEjecutarEnParalelo) {
	this->operacionPorEjecutarEnParalelo = (operacionPorEjecutarEnParalelo);
	this->nroParticion = nroPart;
	this->columna = columna;
	this->filasPorParticiones = filasPorParticiones;
	this->filaFinal = filaFinal;
	this->filaInicial = filaInicial;
}

Particion::Particion(const Particion &&other) {
	this->operacionPorEjecutarEnParalelo = other.operacionPorEjecutarEnParalelo;
	this->nroParticion = other.nroParticion;
	this->columna = other.columna;
	this->filasPorParticiones = other.filasPorParticiones;
	this->filaFinal = other.filaFinal;
	this->filaInicial = other.filaInicial;
}

void Particion::resolverValorParcialDeParticionEnParalelo(const int &columnas,
		OperacionStrategy &operacionParcial, const std::string &dataset) {
	LectorDeArchivo archivoPorUsar(dataset, columnas);
	archivoPorUsar.situarLectorEnFilaInicial(filaInicial);
	for (int i = 0; i < filasPorParticiones; i++) {
		int fila = i + filaInicial;
		if (fila < filaFinal)
			operacionParcial.StrategyRealizarOperacion(
					archivoPorUsar.obtenerDatosDeArchivo(columna));
	}
}

void Particion::ejecutar(std::string &dataset, int &columnas,
		ResultadoCompartidoMonitor &resultadoProtegido) {
	OperacionStrategy operacionParcial;
	operacionParcial.StrategyCrearOperacion(operacionPorEjecutarEnParalelo);
	resolverValorParcialDeParticionEnParalelo(columnas, operacionParcial,
			dataset);
	resultadoProtegido.guardarResultadosParciales(std::move(operacionParcial),
			this->nroParticion);
}

bool Particion::esElToken() {
	return this->nroParticion == (-1) ? true : false;
}

Particion::~Particion() {
}

