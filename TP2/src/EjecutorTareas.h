/*
 * EjecutorTareas.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef EJECUTORTAREAS_H_
#define EJECUTORTAREAS_H_
#include "Particion.h"
#include <string>
#include <mutex>
#include "ColaProtegida.h"

class EjecutorTareas {
private:
	ColaProtegida& colaCompartidaConTareas;
	OperacionMonitor& resultadoProtegido;
	std::string dataset;
	int columnas;

public:
	EjecutorTareas(ColaProtegida& colaPorUsar,std::string dataset
			, int columnas,OperacionMonitor& resultadoProtegido);

	void operator()();

	virtual ~EjecutorTareas();
};

#endif /* EJECUTORTAREAS_H_ */
