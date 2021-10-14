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

SplitApplyCombineImpl*
	ParserSolicitudUsuario::crearSplitApplyCombineConInformacionIngresada
	(char *argv[]) {
	OperacionStrategy* strategySolicitadaPorUser = new OperacionStrategy();
	strategySolicitadaPorUser->StrategyCrearOperacion(operacion);
	SplitApplyCombineImpl* ejecutorSplitApplyCombine =
			new SplitApplyCombineImpl(std::stoi(this->filaInicio),
					std::stoi(this->filaFin), strategySolicitadaPorUser,
					std::stoi(this->nroParticiones));
	ejecutorSplitApplyCombine->cargarDatosParaResolverOperaciones(argv,
			std::stoi(this->columnaPorUsar));
	return ejecutorSplitApplyCombine;
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

