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
	OperacionStrategy *operacion;
    std::mutex m;
    bool lecturaValida;
public:
	OperacionMonitor(OperacionStrategy* strat);

	void cargarDatosParaOperacionSiEsNecesario(LectorDeArchivo* archivoPorUsar, int filasPorParticiones);

	void imprimirResultado();

	virtual ~OperacionMonitor();
};

#endif /* OPERACIONMONITOR_H_ */
