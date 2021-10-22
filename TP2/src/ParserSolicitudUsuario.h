/*
 * ParserSolicitudUsuario.h
 *
 *  Created on: 11 oct. 2021
 *      Author: andres
 */

#include <string.h>
#include <iostream>
#include <string>

#ifndef PARSERSOLICITUDUSUARIO_H_
#define PARSERSOLICITUDUSUARIO_H_

class ParserSolicitudUsuario {
	std::string filaInicio;
	std::string  filaFin;
	std::string  operacion;
	std::string  nroFilasPorParticion;
	std::string  columnaPorUsar;

public:

	ParserSolicitudUsuario();
	/*
	 * POST: Bool que indica si el usuario dejo de ingresar
	 * o ingreso un #EOF
	 */
	void parsearInputDeUsuario(std::string input);

	int obtenerFilaInicioDelInputRecibido();
	int obtenerFilaFinDelInputRecibido();
	int obtenerNroFilasPorParticionDelInputRecibido();
	int obtenerColumnaPorUsarDelInputRecibido();
	std::string obtenerOperacionDelInputRecibido();

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
	void identificarInformacionIngresadaStdin(std::string input);

	/*
	 * POST: Retorna la ubicacion en el input en la que se esta leyendo
	 * de donde se van opteniendo valores separados por '\n'
	 */
	int obtenerValor(std::string* value, std::string input, int inicio);
};

#endif /* PARSERSOLICITUDUSUARIO_H_ */
