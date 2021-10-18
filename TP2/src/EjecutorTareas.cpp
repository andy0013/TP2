/*
 * EjecutorTareas.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "EjecutorTareas.h"

EjecutorTareas::EjecutorTareas(ProtecetedQueue& colaPorUsar) :
	colaCompartidaConTareas(colaPorUsar){}

void EjecutorTareas::operator()() {
	bool hiloEnCurso = true;
	while(hiloEnCurso){
		Particion* particionPorEjecutar = this->colaCompartidaConTareas.consumeTaskIfPosible();
		if(particionPorEjecutar != NULL)
			particionPorEjecutar->execute();
		else{
			hiloEnCurso = false;
		}
	}
}


EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

