/*
 * EjecutorTareas.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "EjecutorTareas.h"

//EjecutorTareas::EjecutorTareas(ProtecetedQueue& colaPorUsar,bool& hilosSiguenEjecutando) :
//	colaCompartidaConTareas(colaPorUsar),hilosSiguenEjecutando(hilosSiguenEjecutando){}

EjecutorTareas::EjecutorTareas(ProtecetedQueue& colaPorUsar) :
	colaCompartidaConTareas(colaPorUsar){}

void EjecutorTareas::operator()() {
	bool hilosSiguenEjecutando = true;
	while(hilosSiguenEjecutando){
		Particion particionPorEjecutar = this->colaCompartidaConTareas.consumeTaskIfPosible();
		if(!particionPorEjecutar.isToken()){
			particionPorEjecutar.execute();
		}else{
			hilosSiguenEjecutando = false;
		}
	}
}


EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

