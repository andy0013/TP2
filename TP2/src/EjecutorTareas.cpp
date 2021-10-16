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
    bool keepWriting = true;
	while (keepWriting) {

		Particion block = this->colaCompartidaConTareas.consumeTaskIfPosible();
		block.execute();
//			keepWriting &= block.valid();
//			block.write(*streamTowrite);

	}
}


EjecutorTareas::~EjecutorTareas() {
	// TODO Auto-generated destructor stub
}

