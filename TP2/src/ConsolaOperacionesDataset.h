/*
 * Consola.h
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#ifndef CONSOLAOPERACIONESDATASET_H_
#define CONSOLAOPERACIONESDATASET_H_

#include <string.h>
#include <iostream>
#include "SplitApplyCombineImpl.h"
#include "ParserSolicitudUsuario.h"
#include <string>

class ConsolaOperacionesDataset {

	ParserSolicitudUsuario* solicitudUsuario;
	SplitApplyCombineImpl* ejecutorSolicitudes;

public:
	ConsolaOperacionesDataset();

	void solicitarYDispararSolicitudUsuario(char *argv[]);

	virtual ~ConsolaOperacionesDataset();

private:
	void imprimirValorAUsuario();

};

#endif /* CONSOLAOPERACIONESDATASET_H_ */