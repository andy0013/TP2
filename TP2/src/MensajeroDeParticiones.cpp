/*
 * MensajeroDeParticiones.cpp
 *
 *  Created on: 21 oct. 2021
 *      Author: andres
 */

#include "MensajeroDeParticiones.h"

MensajeroDeParticiones::MensajeroDeParticiones(ParserSolicitudUsuario& infoIngreasadaPorUsuario):
	infoIngreasadaPorUsuario(infoIngreasadaPorUsuario){}


void MensajeroDeParticiones::enviarParticiones(int nroParticionesPorUsar,bool agregarParticionIncompleta,ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion, LectorDeArchivo *gestorDeDatos, int nroParticion){
	int filaInicial = this->infoIngreasadaPorUsuario.obtenerFilaInicioDelInputRecibido();
	int salto = this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	for (int i = 0; i < nroParticionesPorUsar; i++) {
		Particion particion(operacion,gestorDeDatos,salto,nroParticion,filaInicial+salto,filaInicial);
		colaDeEjecuciones.addTaskIfPossible(particion);
		filaInicial = filaInicial+salto;
	}
	if(agregarParticionIncompleta){
	Particion particion(operacion,gestorDeDatos,salto,nroParticion,this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido(),filaInicial);
		colaDeEjecuciones.addTaskIfPossible(particion);
	}
}


void MensajeroDeParticiones::prepararMonitorConValoresIngresadosPorUsuario(OperacionMonitor& operacion){
	operacion.datosIngresadosPorUser(this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido(), this->infoIngreasadaPorUsuario.obtenerOperacionDelInputRecibido());
}

void MensajeroDeParticiones::enviarToken(ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion,LectorDeArchivo *gestorDeDatos){
	colaDeEjecuciones.closeTask();
}



void MensajeroDeParticiones::crearParticionesYEnviarALaQueue(ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion, LectorDeArchivo *gestorDeDatos,int nroParticion){
	int filasPorUsar = this->infoIngreasadaPorUsuario.obtenerFilaFinDelInputRecibido()-this->infoIngreasadaPorUsuario.obtenerFilaInicioDelInputRecibido();
	int resto = filasPorUsar % this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	int nroParticionesPorUsar = filasPorUsar/this->infoIngreasadaPorUsuario.obtenerNroFilasPorParticionDelInputRecibido();
	bool enviarParticionIncompleta = true;
	if(resto == 0){
		enviarParticionIncompleta = false;
	}
	enviarParticiones(nroParticionesPorUsar,enviarParticionIncompleta, colaDeEjecuciones, operacion, gestorDeDatos,nroParticion);
}


MensajeroDeParticiones::~MensajeroDeParticiones() {
}

