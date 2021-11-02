/*
 * EjecutorTareas.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "EjecutorTareas.h"

EjecutorTareas::EjecutorTareas(ColaProtegida &colaPorUsar,
		const std::string dataset , int columnas,OperacionMonitor& resultadoProtegido) :
		colaCompartidaConTareas(colaPorUsar), resultadoProtegido(resultadoProtegido){
	this->columnas = columnas;
	this->dataset = dataset;
}

void EjecutorTareas::operator()() {
	bool hilosSiguenEjecutando = true;
	while (hilosSiguenEjecutando) {
		Particion particionPorEjecutar =
				this->colaCompartidaConTareas.obtenerInformacionSiEsPosible();
		if (!particionPorEjecutar.esElToken()) {
			particionPorEjecutar.ejecutar(this->dataset,this->columnas,resultadoProtegido);
		} else {
			hilosSiguenEjecutando = false;
		}
	}
}

EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

