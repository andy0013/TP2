/*
 * MensajeroDeParticiones.cpp
 *
 *  Created on: 21 oct. 2021
 *      Author: andres
 */

#include "MensajeroDeParticiones.h"

MensajeroDeParticiones::MensajeroDeParticiones(
		ParserSolicitudUsuario &infoIngreasadaPorUsuario) :
		infoIngreasadaPorUsuario(infoIngreasadaPorUsuario) {
}

void MensajeroDeParticiones::enviarParticiones(int nroParticionesPorUsar,
		bool agregarParticionIncompleta, ProtecetedQueue &colaDeEjecuciones,
		OperacionMonitor &operacion,
		int nroParticion, int columna) {
	int filaInicial =
			this->infoIngreasadaPorUsuario
			.obtenerFilaInicioDelInputRecibido();
	int salto =
			this->infoIngreasadaPorUsuario
			.obtenerNroFilasPorParticionDelInputRecibido();
	for (int i = 0; i < nroParticionesPorUsar; i++) {
		Particion particion(operacion, salto, nroParticion,
				filaInicial + salto, filaInicial,columna);
		colaDeEjecuciones.agregarParticionSiEsPosible(particion);
		filaInicial = filaInicial + salto;
	}
	if (agregarParticionIncompleta) {
		Particion particion(operacion, salto, nroParticion,
				this->infoIngreasadaPorUsuario
				.obtenerFilaFinDelInputRecibido(),
				filaInicial,columna);
		colaDeEjecuciones.agregarParticionSiEsPosible(particion);
	}
}

void MensajeroDeParticiones::prepararMonitorConValoresIngresadosPorUsuario(
		OperacionMonitor &operacion) {
	operacion.datosIngresadosPorUser(
			this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido(),
			this->infoIngreasadaPorUsuario.obtenerOperacionDelInputRecibido());
}

void MensajeroDeParticiones::enviarToken(ProtecetedQueue &colaDeEjecuciones) {
	colaDeEjecuciones.terminarQueue();
}

void MensajeroDeParticiones::crearParticionesYEnviarALaQueue(
		ProtecetedQueue &colaDeEjecuciones, OperacionMonitor &operacion
		, int nroParticion) {
	int filasPorUsar =
			this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido()
					- this->infoIngreasadaPorUsuario
					.obtenerFilaInicioDelInputRecibido();
	int resto =
			filasPorUsar
					% this->infoIngreasadaPorUsuario
					.obtenerNroFilasPorParticionDelInputRecibido();
	int nroParticionesPorUsar =
			filasPorUsar
					/ this->infoIngreasadaPorUsuario
					.obtenerNroFilasPorParticionDelInputRecibido();
	bool enviarParticionIncompleta = true;
	if (resto == 0) {
		enviarParticionIncompleta = false;
	}
	enviarParticiones(nroParticionesPorUsar, enviarParticionIncompleta,
			colaDeEjecuciones, operacion, nroParticion,
			this->infoIngreasadaPorUsuario.obtenerColumnaPorUsarDelInputRecibido());
}

MensajeroDeParticiones::~MensajeroDeParticiones() {
}

