/*
 * ParserSolicitudUsuario.h
 *
 *  Created on: 11 oct. 2021
 *      Author: andres
 */

#include <string.h>
#include <iostream>
#include <string>

#include "GestorHilos.h"
#include "ProtecetedQueue.h"
#include "OperacionStrategy.h"


#ifndef PARSERSOLICITUDUSUARIO_H_
#define PARSERSOLICITUDUSUARIO_H_

class ParserSolicitudUsuario {
	std::string filaInicio;
	std::string  filaFin;
//	std::string  operacion;
	std::string  nroParticiones;
//	std::string  columnaPorUsar;

public:
	std::string  columnaPorUsar;
	std::string  operacion;
	ParserSolicitudUsuario();
	/*
	 * POST: Bool que indica si el usuario dejo de ingresar
	 * o ingreso un #EOF
	 */
	bool solicitarRequerimientosUsuario();

	void prepararMonitorConValoresIngresadosPorUsuario(OperacionMonitor& operacion);

	void crearParticionesYEnviarALaQueue(ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion,LectorDeArchivo *gestorDeDatos);
	/*
	 * POST: limpia los atributos para cuando el usuario vuelva
	 * a ingresar datos.
	 */
	void prepararValoresParaNuevaSolicitud();

	virtual ~ParserSolicitudUsuario();
private:
	/*
	 * PRE: Input user.
	 * POST: parsea el string recibido por input
	 * y lo guarda en los atributos de la clase.
	 */
	void identificarInformacionIngresadaStdin(char *input);

	void enviarParticiones(int nroParticionesPorUsar,ProtecetedQueue& colaDeEjecuciones,OperacionMonitor& operacion, LectorDeArchivo *gestorDeDatos);

	/*
	 * POST: Retorna la ubicacion en el input en la que se esta leyendo
	 * de donde se van opteniendo valores separados por '\n'
	 */
	int obtenerValor(std::string* value, char* input, int inicio);
};

#endif /* PARSERSOLICITUDUSUARIO_H_ */
