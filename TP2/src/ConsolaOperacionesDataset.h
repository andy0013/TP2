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

#include "ColaProtegida.h"
#include "ParserSolicitudUsuario.h"
#include "MensajeroDeParticiones.h"
#include "LectorDeArchivo.h"
#include "ResultadoCompartidoMonitor.h"

class ConsolaOperacionesDataset {

	ColaProtegida &colaDeEjecuciones;

	ConsolaOperacionesDataset(const ConsolaOperacionesDataset &other) = delete;

	ConsolaOperacionesDataset& operator=(const ConsolaOperacionesDataset &other) = delete;


public:
	explicit ConsolaOperacionesDataset(ColaProtegida &protecetedQueue);
	/*
	 * Manda a solicitar valores a usuario
	 * Mientras el usuario solicite, envia
	 * a ejecutar el splitApplycombine
	 */
	void solicitarYDispararSolicitudUsuario(char *argv[],ResultadoCompartidoMonitor& resultadoProtegido);

	virtual ~ConsolaOperacionesDataset();
};
#endif /* CONSOLAOPERACIONESDATASET_H_ */
