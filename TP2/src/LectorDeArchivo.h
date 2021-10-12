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
	int filaEnLaQueEstaSituado;
	int numeroDeColumna;

public:
	LectorDeArchivo(std::string pathPorLeer, int cantidadCols, int nroCols);

	void leerArchivoBinario();

	void situarLectorEnFilaInicial(int nroDeFila);

	int obtenerDatosDeArchivo();

	bool siguienteFilaValida(int filaFinal);

	virtual ~LectorDeArchivo();
};

#endif /* LECTORDEARCHIVO_H_ */
