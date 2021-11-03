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
#include <utility>
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
	 * Cuando recibe stdin - toma esa informacion
	 * a traves de la clase MensajeroDeParticiones y
	 * De la clase ParserSolicitudUsuario, y luego
	 * las envia como Particiones a la Cola.
	 */
	void solicitarYDispararSolicitudUsuario(char *argv[],
			ResultadoCompartidoMonitor& resultadoProtegido);

	virtual ~ConsolaOperacionesDataset();
};
#endif /* CONSOLAOPERACIONESDATASET_H_ */
