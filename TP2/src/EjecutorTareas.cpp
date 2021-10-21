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
	bool hilosEnCurso = true;
	while(hilosEnCurso){
		Particion particionPorEjecutar = this->colaCompartidaConTareas.consumeTaskIfPosible();
		if(!particionPorEjecutar.isToken()){
			particionPorEjecutar.execute();
		}else{
			hilosEnCurso= false;
		}
	}
}


EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

