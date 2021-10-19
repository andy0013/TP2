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
#include "ParserSolicitudUsuario.h"
#include "OperacionMonitor.h"
#include "ProtecetedQueue.h"
#include <string>

#include "GestorHilos.h"

class ConsolaOperacionesDataset {
	ProtecetedQueue& colaDeEjecuciones;
	ParserSolicitudUsuario* solicitudUsuario;
public:
	ConsolaOperacionesDataset(ProtecetedQueue& protecetedQueue);
	/*
	 * Manda a solicitar valores a usuario
	 * Mientras el usuario solicite, envia
	 * a ejecutar el splitApplycombine
	 */
	void solicitarYDispararSolicitudUsuario(char *argv[]);

	virtual ~ConsolaOperacionesDataset();
};
#endif /* CONSOLAOPERACIONESDATASET_H_ */
