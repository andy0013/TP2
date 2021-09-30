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


class LectorDeArchivo {

private:
	std::string pathDeArchivo;
	std::ifstream archivo;

public:
	LectorDeArchivo(std::string pathPorLeer);

	void leerArchivoBinario();

	void obtenerDatosDeArchivo(int cantidadDeValores);

	bool seLlegoAlFinDelArchivo();

	virtual ~LectorDeArchivo();
};

#endif /* LECTORDEARCHIVO_H_ */
