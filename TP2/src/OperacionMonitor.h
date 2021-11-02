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

	OperacionMonitor(const OperacionMonitor &other) = delete;

	OperacionMonitor& operator=(const OperacionMonitor &other) = delete;


public:
	OperacionMonitor();

	void crearInstanciaDeResultadoProtegidoParaLaSolicitudDeUsuario(std::string operacion);

	void guardarResultadosParciales(OperacionStrategy operacionParcial,int nroParticion);

	void imprimirResultado();

	virtual ~OperacionMonitor();
};

#endif /* OPERACIONMONITOR_H_ */
