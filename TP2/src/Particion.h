/*
 * Particion.h
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#ifndef PARTICION_H_
#define PARTICION_H_
#include "LectorDeArchivo.h"
#include "OperacionStrategy.h"
#include <string>
#include "ResultadoCompartidoMonitor.h"
#include <utility>
class Particion {
private:
	std::string operacionPorEjecutarEnParalelo;
	int filasPorParticiones;
	int nroParticion;
	int filaFinal;
	int columna;
	int filaInicial;

	void resolverValorParcialDeParticionEnParalelo(const int& columnas,
			OperacionStrategy& operacionParcial,const std::string &dataset);


	Particion(const Particion &other) = delete;

	Particion& operator=(const Particion &other) = delete;


public:
	Particion();

	Particion(const Particion &&other);

	Particion(int filasPorParticiones, int nroParticion, int filaFinal,
			int filaInicial,int columna,
			std::string operacionPorEjecutarEnParalelo);
	/*
	 * PRE: Monitor con resultado compartido.
	 * - ejecuta la operacion parcial : sin lock.
	 * - a traves del monitor guarda el resultado parcial en monitor. con lock
	 */
	void ejecutar(std::string &dataset , int &columnas,ResultadoCompartidoMonitor& resultadoProtegido);
	/*
	 * POST: bool que indica si la Particion es el token
	 * que indica que el hilo debe terminar.
	 */
	bool esElToken();

	virtual ~Particion();
};

#endif /* PARTICION_H_ */
