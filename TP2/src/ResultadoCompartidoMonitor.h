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

	ResultadoCompartidoMonitor(const ResultadoCompartidoMonitor &other) = delete;

	ResultadoCompartidoMonitor& operator=(const ResultadoCompartidoMonitor &other) = delete;


public:
	ResultadoCompartidoMonitor();
	/*
	 * Se crea la operacion en donde se guardaran los resultados parciales
	 * de las Particiones que seran enviadas.
	 */
	void crearInstanciaDeResultadoProtegidoParaLaSolicitudDeUsuario(std::string operacion);
	/*
	 * Guarda el resultado parcial de la operacion que se hizo en la Particion.
	 */
	void guardarResultadosParciales(OperacionStrategy operacionParcial,int nroParticion);
	/*
	 * Imprime el resultado final de las distintas operaciones.
	 */
	void imprimirResultado();

	virtual ~ResultadoCompartidoMonitor();
};

#endif /* RESULTADOCOMPARTIDOMONITOR_H_ */
