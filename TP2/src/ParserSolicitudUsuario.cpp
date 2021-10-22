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
	this->nroFilasPorParticion = "";
	this->operacion = "";
}

void ParserSolicitudUsuario::parsearInputDeUsuario(std::string input){
	this->identificarInformacionIngresadaStdin(input);
}


int ParserSolicitudUsuario::obtenerFilaInicioDelInputRecibido(){
	return std::stoi(this->filaInicio);
}

int ParserSolicitudUsuario::obtenerFilaFinDelInputRecibido(){
	return std::stoi(this->filaFin);
}

int ParserSolicitudUsuario::obtenerNroFilasPorParticionDelInputRecibido(){
	return std::stoi(this->nroFilasPorParticion);
}

int ParserSolicitudUsuario::obtenerColumnaPorUsarDelInputRecibido(){
	return std::stoi(this->columnaPorUsar);
}

std::string ParserSolicitudUsuario::obtenerOperacionDelInputRecibido(){
	return this->operacion;
}


void ParserSolicitudUsuario::identificarInformacionIngresadaStdin
	(std::string input) {
	int i = 0;
	this->prepararValoresParaNuevaSolicitud();
	i = this->obtenerValor(&this->filaInicio, input, i);
	i = this->obtenerValor(&this->filaFin, input, i);
	i = this->obtenerValor(&this->nroFilasPorParticion, input, i);
	i = this->obtenerValor(&this->columnaPorUsar, input, i);
	this->obtenerValor(&this->operacion, input, i);
}


int ParserSolicitudUsuario::obtenerValor(std::string *value, std::string input,
		int inicio) {
	int i;
	for (i = inicio; inicio < (int) ((input.length()) - 1); i++) {
		if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0') {
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
	this->nroFilasPorParticion = "";
	this->operacion = "";
}

ParserSolicitudUsuario::~ParserSolicitudUsuario() {
	// TODO Auto-generated destructor stub
}

