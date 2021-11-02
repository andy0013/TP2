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

class Particion {
private:
	std::string operacionPorEjecutarEnParalelo;
	int filasPorParticiones;
	int nroParticion;
	int filaFinal;
	int columna;
	int filaInicial;

	void resolverValorParcialDeParticionEnParalelo(int& columnas,
			OperacionStrategy& operacionParcial, std::string &dataset);


	Particion(const Particion &other) = delete;

	Particion& operator=(const Particion &other) = delete;


public:
	explicit Particion();

	Particion(const Particion &&other);

	Particion(int filasPorParticiones, int nroParticion, int filaFinal,
			int filaInicial,int columna,std::string operacionPorEjecutarEnParalelo);

	void ejecutar(std::string dataset , int columnas,ResultadoCompartidoMonitor& resultadoProtegido);

	bool esElToken();

	virtual ~Particion();
};

#endif /* PARTICION_H_ */
