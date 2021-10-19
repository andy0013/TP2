/*
 * ParserSolicitudUsuario.cpp
 *
 *  Created on: 11 oct. 2021
 *      Author: andres
 */

#include "ParserSolicitudUsuario.h"

ParserSolicitudUsuario::ParserSolicitudUsuario() {
	this->columnaPorUsar = "";
	this->filaFin = "";
	this->filaInicio = "";
	this->nroParticiones = "";
	this->operacion = "";
}

bool ParserSolicitudUsuario::solicitarRequerimientosUsuario() {
	char *input = NULL;
	bool ingreso = true;
	size_t leido = 0;
	int read = getline(&input, &leido, stdin);
	if (read == -1) {
		ingreso = false;
	}
	this->identificarInformacionIngresadaStdin(input);
	if (feof(stdin))
		ingreso = false;
	return ingreso;
}
void ParserSolicitudUsuario::enviarParticiones(int nroParticionesPorUsar,ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion, LectorDeArchivo *gestorDeDatos){
	for (int i = 0; i < nroParticionesPorUsar; i++) {
		Particion particion(operacion,gestorDeDatos,std::stoi(this->nroParticiones));
		colaDeEjecuciones.addTaskIfPossible(&particion);
	}
}

void ParserSolicitudUsuario::prepararMonitorConValoresIngresadosPorUsuario(OperacionMonitor& operacion){
	operacion.datosIngresadosPorUser(std::stoi(this->filaFin), this->operacion);
}


void ParserSolicitudUsuario::crearParticionesYEnviarALaQueue(ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion, LectorDeArchivo *gestorDeDatos){
	int filasPorUsar = std::stoi(this->filaFin)-std::stoi(this->filaInicio);
	int resto = filasPorUsar % std::stoi(this->nroParticiones);
	int nroParticionesPorUsar = filasPorUsar/std::stoi(this->nroParticiones);
	if(resto == 0){
		enviarParticiones(nroParticionesPorUsar, colaDeEjecuciones, operacion, gestorDeDatos);
	}else{
		enviarParticiones(nroParticionesPorUsar+1, colaDeEjecuciones, operacion, gestorDeDatos);
	}
}

void ParserSolicitudUsuario::identificarInformacionIngresadaStdin
	(char *input) {
	int i = 0;
	this->prepararValoresParaNuevaSolicitud();
	i = this->obtenerValor(&this->filaInicio, input, i);
	i = this->obtenerValor(&this->filaFin, input, i);
	i = this->obtenerValor(&this->nroParticiones, input, i);
	i = this->obtenerValor(&this->columnaPorUsar, input, i);
	this->obtenerValor(&this->operacion, input, i);
}


int ParserSolicitudUsuario::obtenerValor(std::string *value, char *input,
		int inicio) {
	int i;
	for (i = inicio; inicio < (int) (strlen(input) - 1); i++) {
		if (input[i] == ' ' || input[i] == '\n') {
			i++;
			break;
		}
		*value += input[i];
	}
	return i;
}

void ParserSolicitudUsuario::prepararValoresParaNuevaSolicitud() {
	this->columnaPorUsar = "";
	this->filaFin = "";
	this->filaInicio = "";
	this->nroParticiones = "";
	this->operacion = "";
}

ParserSolicitudUsuario::~ParserSolicitudUsuario() {
	// TODO Auto-generated destructor stub
}

