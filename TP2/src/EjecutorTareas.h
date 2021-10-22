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
#include <string>

class EjecutorTareas {
private:
	ProtecetedQueue& colaCompartidaConTareas;
	const std::string dataset;
	int columnas;
public:
	EjecutorTareas(ProtecetedQueue& colaPorUsar,const std::string dataset
			, int columnas);

	void operator()();

	virtual ~EjecutorTareas();
};

#endif /* EJECUTORTAREAS_H_ */
