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
#include <vector>
#include <string>

class OperacionMonitor {
private:
	std::vector<OperacionStrategy> operacionCompartida;
//	OperacionStrategy operacionCompartida;
	std::mutex m;
	bool lecturaValida;
	std::string operacion;
	int filaFinal;

	void splitApply(int filasPorParticiones,
			OperacionStrategy &operacionParcial,
			LectorDeArchivo *archivoPorUsar, int filaFinal, int filaInicial,
			int columna);

	void combine(OperacionStrategy &operacionParcial, int ii);

public:
	OperacionMonitor();

	void datosIngresadosPorUser(int filaFinal, std::string operacion);

	void splitApplyCombine(LectorDeArchivo *archivoPorUsar,
			int filasPorParticiones, int filaInicial, int ii, int filaFinal
			,int columna);

	void imprimirResultado();

	virtual ~OperacionMonitor();
};

#endif /* OPERACIONMONITOR_H_ */
