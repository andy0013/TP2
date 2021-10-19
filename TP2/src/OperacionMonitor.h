/*
 * OperacionMonitor.h
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONMONITOR_H_
#define OPERACIONMONITOR_H_

#include <iostream>
#include "LectorDeArchivo.h"
#include "OperacionStrategy.h"
#include <mutex>

class OperacionMonitor {
private:
	OperacionStrategy operacionCompartida;
    std::mutex m;
    bool lecturaValida;
    std::string operacion;
    int filaFinal;

	void splitApply(int filasPorParticiones, OperacionStrategy& operacionParcial,
			LectorDeArchivo *archivoPorUsar);

	void combine(OperacionStrategy operacionParcial);

public:
	OperacionMonitor();

	void datosIngresadosPorUser(int filaFinal,std::string operacion);

	void splitApplyCombine(LectorDeArchivo* archivoPorUsar, int filasPorParticiones);

	void imprimirResultado();

	virtual ~OperacionMonitor();
};

#endif /* OPERACIONMONITOR_H_ */
