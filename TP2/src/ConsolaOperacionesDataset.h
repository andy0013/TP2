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
#include "ProtecetedQueue.h"
#include <string>

class ConsolaOperacionesDataset {
	ProtecetedQueue& colaDeEjecuciones;
	ParserSolicitudUsuario* solicitudUsuario;
	SplitApplyCombineImpl* ejecutorSolicitudes;

public:
	ConsolaOperacionesDataset(ProtecetedQueue& protecetedQueue);
	/*
	 * Manda a solicitar valores a usuario
	 * Mientras el usuario solicite, envia
	 * a ejecutar el splitApplycombine
	 */
	void solicitarYDispararSolicitudUsuario(char *argv[]);

	virtual ~ConsolaOperacionesDataset();

private:
	void imprimirValorAUsuario();
};
#endif /* CONSOLAOPERACIONESDATASET_H_ */
