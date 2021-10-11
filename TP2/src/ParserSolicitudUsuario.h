/*
 * ParserSolicitudUsuario.h
 *
 *  Created on: 11 oct. 2021
 *      Author: andres
 */

#include <string.h>
#include <iostream>
#include <string>
#include "SplitApplyCombineImpl.h"


#ifndef PARSERSOLICITUDUSUARIO_H_
#define PARSERSOLICITUDUSUARIO_H_

class ParserSolicitudUsuario {

	std::string filaInicio;
	std::string  filaFin;
	std::string  operacion;
	std::string  nroParticiones;
	std::string  columnaPorUsar;

public:
	ParserSolicitudUsuario();

	bool solicitarRequerimientosUsuario();

	SplitApplyCombineImpl* crearSplitApplyCombineConInformacionIngresada(char *argv[]);

	virtual ~ParserSolicitudUsuario();

	void identificarInformacionIngresadaStdin(char *input);

private:

	void prepararValoresParaNuevaSolicitud();

	int obtenerValor(std::string* value, char* input, int inicio);

};

#endif /* PARSERSOLICITUDUSUARIO_H_ */
