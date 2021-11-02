/*
 * OperacionMonitor.h
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#ifndef RESULTADOCOMPARTIDOMONITOR_H_
#define RESULTADOCOMPARTIDOMONITOR_H_

#include <iostream>
#include "LectorDeArchivo.h"
#include "OperacionStrategy.h"
#include <mutex>
#include <vector>
#include <string>

class ResultadoCompartidoMonitor {
private:
	std::vector<OperacionStrategy*> operacionCompartida;
	std::mutex m;
	bool lecturaValida;
	std::string operacion;
	int filaFinal;

	ResultadoCompartidoMonitor(const ResultadoCompartidoMonitor &other) = delete;

	ResultadoCompartidoMonitor& operator=(const ResultadoCompartidoMonitor &other) = delete;


public:
	ResultadoCompartidoMonitor();

	void crearInstanciaDeResultadoProtegidoParaLaSolicitudDeUsuario(std::string operacion);

	void guardarResultadosParciales(OperacionStrategy operacionParcial,int nroParticion);

	void imprimirResultado();

	virtual ~ResultadoCompartidoMonitor();
};

#endif /* RESULTADOCOMPARTIDOMONITOR_H_ */
