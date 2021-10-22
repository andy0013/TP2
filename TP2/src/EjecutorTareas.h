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
#include <mutex>

class EjecutorTareas {
private:
	ProtecetedQueue& colaCompartidaConTareas;
	std::string dataset;
	int columnas;
	std::mutex& mutex;

public:
	EjecutorTareas(ProtecetedQueue& colaPorUsar,std::string dataset
			, int columnas,std::mutex& mutex);

	void operator()();

	virtual ~EjecutorTareas();
};

#endif /* EJECUTORTAREAS_H_ */
