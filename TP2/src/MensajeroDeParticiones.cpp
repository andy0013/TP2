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
		bool agregarParticionIncompleta, ColaProtegida &colaDeEjecuciones,
		int nroParticion, int columna) {
	int filaInicial =
			this->infoIngreasadaPorUsuario.obtenerFilaInicioDelInputRecibido();
	int salto =
			this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	for (int i = 0; i < nroParticionesPorUsar; i++) {
		Particion particion(salto, nroParticion, filaInicial + salto,
				filaInicial, columna,
				this->infoIngreasadaPorUsuario.obtenerOperacionDelInputRecibido());
		colaDeEjecuciones.agregarParticionSiEsPosible(std::move(particion));
		filaInicial = filaInicial + salto;
	}
	if (agregarParticionIncompleta) {
		Particion particion(salto, nroParticion,
				this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido(),
				filaInicial, columna,
				this->infoIngreasadaPorUsuario.obtenerOperacionDelInputRecibido());
		colaDeEjecuciones.agregarParticionSiEsPosible(std::move(particion));
	}
}

void MensajeroDeParticiones::cerrarCola(ColaProtegida &colaDeEjecuciones) {
	colaDeEjecuciones.terminarQueue();
}

void MensajeroDeParticiones::crearParticionesYEnviarALaQueue(
		ColaProtegida &colaDeEjecuciones, int nroParticion) {
	int filasPorUsar =
			this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido()
					- this->infoIngreasadaPorUsuario.obtenerFilaInicioDelInputRecibido();
	int resto =
			filasPorUsar
					% this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	int nroParticionesPorUsar =
			filasPorUsar
					/ this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	bool enviarParticionIncompleta = true;
	if (resto == 0) {
		enviarParticionIncompleta = false;
	}
	enviarParticiones(nroParticionesPorUsar, enviarParticionIncompleta,
			colaDeEjecuciones, nroParticion,
			this->infoIngreasadaPorUsuario.obtenerColumnaPorUsarDelInputRecibido());
}

MensajeroDeParticiones::~MensajeroDeParticiones() {
}

