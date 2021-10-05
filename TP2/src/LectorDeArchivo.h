/*
 * LectorDeArchivo.h
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#ifndef LECTORDEARCHIVO_H_
#define LECTORDEARCHIVO_H_
#include <string>
#include <fstream>
#include <iostream>
#include "LectorDeArchivo.h"


class LectorDeArchivo {

private:
	std::string pathDeArchivo;
	std::fstream archivo;
	int cantidadDeColumnas;
	int numeroDeColumna;

public:
	LectorDeArchivo(std::string pathPorLeer, int cantidadCols, int nroCols);

	void leerArchivoBinario();

	int obtenerDatosDeArchivo();

	bool seLlegoAlFinDelArchivo();

	virtual ~LectorDeArchivo();
};

#endif /* LECTORDEARCHIVO_H_ */
