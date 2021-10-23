/*
 * MensajeroDeParticiones.h
 *
 *  Created on: 21 oct. 2021
 *      Author: andres
 */

#ifndef MENSAJERODEPARTICIONES_H_
#define MENSAJERODEPARTICIONES_H_
#include "GestorHilos.h"
#include "ProtecetedQueue.h"
#include "OperacionStrategy.h"
#include "ParserSolicitudUsuario.h"

class MensajeroDeParticiones {

	ParserSolicitudUsuario &infoIngreasadaPorUsuario;

	MensajeroDeParticiones(const MensajeroDeParticiones &other) = delete;

	MensajeroDeParticiones& operator=(const MensajeroDeParticiones &other) = delete;


public:
	explicit MensajeroDeParticiones(ParserSolicitudUsuario &infoIngreasadaPorUsuario);

	void enviarToken(ProtecetedQueue &colaDeEjecuciones);

	void prepararMonitorConValoresIngresadosPorUsuario(
			OperacionMonitor &operacion);

	void crearParticionesYEnviarALaQueue(ProtecetedQueue &colaDeEjecuciones,
			OperacionMonitor &operacion,
			int nroParticion);

	virtual ~MensajeroDeParticiones();

private:
	void enviarParticiones(int nroParticionesPorUsar,
			bool agregarParticionIncompleta, ProtecetedQueue &colaDeEjecuciones,
			OperacionMonitor &operacion,
			int nroParticion, int columna);
};

#endif /* MENSAJERODEPARTICIONES_H_ */
