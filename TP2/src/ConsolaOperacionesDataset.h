/*
 * Consola.h
 *
 *  Created on: 10 oct. 2021
 *      Author: andres
 */

#ifndef CONSOLAOPERACIONESDATASET_H_
#define CONSOLAOPERACIONESDATASET_H_

#include <cstdlib>
#include <string>
#include "OperacionMonitor.h"
#include "ProtecetedQueue.h"
#include "ParserSolicitudUsuario.h"
#include "MensajeroDeParticiones.h"
#include "LectorDeArchivo.h"

class ConsolaOperacionesDataset {
	ProtecetedQueue &colaDeEjecuciones;
	OperacionMonitor operacion;

public:
	explicit ConsolaOperacionesDataset(ProtecetedQueue &protecetedQueue);
	/*
	 * Manda a solicitar valores a usuario
	 * Mientras el usuario solicite, envia
	 * a ejecutar el splitApplycombine
	 */
	void solicitarYDispararSolicitudUsuario(char *argv[]);

	void imprimir();

	virtual ~ConsolaOperacionesDataset();
};
#endif /* CONSOLAOPERACIONESDATASET_H_ */
