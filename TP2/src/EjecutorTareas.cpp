/*
 * EjecutorTareas.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "EjecutorTareas.h"

EjecutorTareas::EjecutorTareas(ProtecetedQueue &colaPorUsar,
		const std::string dataset , int columnas,std::mutex& mutex) :
		colaCompartidaConTareas(colaPorUsar),mutex(mutex) {
	this->columnas = columnas;
	this->dataset = dataset;
}

void EjecutorTareas::operator()() {
	bool hilosSiguenEjecutando = true;
	while (hilosSiguenEjecutando) {
		Particion particionPorEjecutar =
				this->colaCompartidaConTareas.consumeTaskIfPosible();
		if (!particionPorEjecutar.isToken()) {
			mutex.lock();
			particionPorEjecutar.execute(this->dataset,this->columnas);
			mutex.unlock();
		} else {
			hilosSiguenEjecutando = false;
		}
	}
}

EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

