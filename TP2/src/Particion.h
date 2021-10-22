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

class Particion {
private:
	OperacionMonitor &monitor;
	LectorDeArchivo *archivo;
	int filasPorParticiones;
	int nroParticion;
	int filaFinal;
	int columna;
	int filaInicial;
public:
	explicit Particion(OperacionMonitor &operacionMonitor);

	Particion(OperacionMonitor &operacionMonitor, LectorDeArchivo *archivo,
			int filasPorParticiones, int nroParticion, int filaFinal,
			int filaInicial,int columna);

	void execute();

	bool isToken();

	virtual ~Particion();
};

#endif /* PARTICION_H_ */
