/*
 * EjecutorTareas.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "EjecutorTareas.h"

EjecutorTareas::EjecutorTareas(ProtecetedQueue &colaPorUsar,
		const std::string dataset , int columnas) :
		colaCompartidaConTareas(colaPorUsar){
	this->columnas = columnas;
	this->dataset = dataset;
}

void EjecutorTareas::operator()() {
	bool hilosSiguenEjecutando = true;
	while (hilosSiguenEjecutando) {
		Particion particionPorEjecutar =
				this->colaCompartidaConTareas.obtenerParticionSiEsPosible();
		if (!particionPorEjecutar.esElToken()) {
			particionPorEjecutar.ejecutar(this->dataset,this->columnas);
		} else {
			hilosSiguenEjecutando = false;
		}
	}
}

EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

