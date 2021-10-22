/*
 * LectorDeArchivo.h
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#ifndef LECTORDEARCHIVO_H_
#define LECTORDEARCHIVO_H_
#include <string>
#include <arpa/inet.h>
#include <fstream>
#include <iostream>
#include "LectorDeArchivo.h"

class LectorDeArchivo {
private:
	std::string pathDeArchivo;
	std::fstream archivo;
	int cantidadDeColumnas;

public:
	LectorDeArchivo(std::string pathPorLeer, int cantidadCols);
	/*
	 * Situa el puntero de lectura en la ubicacion de la
	 * fila inicial de donde leer valores.
	 */
	void situarLectorEnFilaInicial(int nroDeFila);
	/*
	 * POST: el valor de la columna leido.
	 */
	int obtenerDatosDeArchivo(int numeroDeColumna);

	virtual ~LectorDeArchivo();
};

#endif /* LECTORDEARCHIVO_H_ */
