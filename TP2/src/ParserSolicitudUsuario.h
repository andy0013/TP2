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
#include "ProtecetedQueue.h"
#include "OperacionStrategy.h"


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
	/*
	 * POST: Bool que indica si el usuario dejo de ingresar
	 * o ingreso un #EOF
	 */
	bool solicitarRequerimientosUsuario();

	/*
	 * POST: retorna el implementador de las operaciones con los
	 * datos leidos del usuario.
	 */
	SplitApplyCombineImpl* crearSplitApplyCombineConInformacionIngresada(char *argv[]);

	void crearParticionesYEnviarALaQueue(ProtecetedQueue& colaDeEjecuciones, LectorDeArchivo *gestorDeDatos);

	virtual ~ParserSolicitudUsuario();

	/*
	 * PRE: Input user.
	 * POST: parsea el string recibido por input
	 * y lo guarda en los atributos de la clase.
	 */
	void identificarInformacionIngresadaStdin(char *input);

	/*
	 * POST: limpia los atributos para cuando el usuario vuelva
	 * a ingresar datos.
	 */
	void prepararValoresParaNuevaSolicitud();

	/*
	 * POST: Retorna la ubicacion en el input en la que se esta leyendo
	 * de donde se van opteniendo valores separados por '\n'
	 */
	int obtenerValor(std::string* value, char* input, int inicio);
};

#endif /* PARSERSOLICITUDUSUARIO_H_ */
