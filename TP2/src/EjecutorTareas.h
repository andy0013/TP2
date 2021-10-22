/*
 * EjecutorTareas.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef EJECUTORTAREAS_H_
#define EJECUTORTAREAS_H_
#include "ProtecetedQueue.h"
#include "Particion.h"


class EjecutorTareas {
private:
	ProtecetedQueue& colaCompartidaConTareas;
//	bool& hilosSiguenEjecutando;

public:
//	EjecutorTareas(ProtecetedQueue& colaPorUsar,bool& hilosSiguenEjecutando);
	explicit EjecutorTareas(ProtecetedQueue& colaPorUsar);

	void operator()();

	virtual ~EjecutorTareas();
};

#endif /* EJECUTORTAREAS_H_ */
