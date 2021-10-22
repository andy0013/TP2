/*
 * Particion.h
 *
 *  Created on: 13 oct. 2021
 *      Author: andres
 */

#ifndef PARTICION_H_
#define PARTICION_H_
#include "LectorDeArchivo.h"
#include "OperacionMonitor.h"
#include <string>

class Particion {
private:
	OperacionMonitor &monitor;
	int filasPorParticiones;
	int nroParticion;
	int filaFinal;
	int columna;
	int filaInicial;
public:
	explicit Particion(OperacionMonitor &operacionMonitor);

	Particion(OperacionMonitor &operacionMonitor,
			int filasPorParticiones, int nroParticion, int filaFinal,
			int filaInicial,int columna);

	void execute(std::string dataset , int columnas);

	bool isToken();

	virtual ~Particion();
};

#endif /* PARTICION_H_ */
