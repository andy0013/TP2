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
	std::vector<OperacionStrategy*> operacionCompartida;
	std::mutex m;
	bool lecturaValida;
	std::string operacion;
	int filaFinal;

	void splitApply(int filasPorParticiones,
			OperacionStrategy &operacionParcial,
			 int filaFinal, int filaInicial,
			int columna,std::string dataset,int columnas);

	void combine(OperacionStrategy operacionParcial, int nroParticion);

	OperacionMonitor(const OperacionMonitor &other) = delete;

	OperacionMonitor& operator=(const OperacionMonitor &other) = delete;


public:
	OperacionMonitor();

	void datosIngresadosPorUser(int filaFinal, std::string operacion);

	void splitApplyCombine(std::string dataset,int columnas,
			int filasPorParticiones, int filaInicial, int nroParticion, int filaFinal
			,int columna);

	void imprimirResultado();

	virtual ~OperacionMonitor();
};

#endif /* OPERACIONMONITOR_H_ */
