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
	std::string filaFin;
	std::string operacion;
	std::string nroFilasPorParticion;
	std::string columnaPorUsar;

	ParserSolicitudUsuario(const ParserSolicitudUsuario &other) = delete;

	ParserSolicitudUsuario& operator=(const ParserSolicitudUsuario &other) = delete;


public:
	ParserSolicitudUsuario();
	/*
	 * POST: Bool que indica si el usuario dejo de ingresar
	 * o ingreso un #EOF
	 */
	void parsearInputDeUsuario(const std::string &input);
	/*
	 * POST: Fila Inicio obtenida.
	 */
	int obtenerFilaInicioDelInputRecibido();
	/*
	 * POST: Fila Fin obtenida.
	 */
	int obtenerFilaFinDelInputRecibido();
	/*
	 * POST: Nro filas por particion obtenida.
	 */
	int obtenerNroFilasPorParticionDelInputRecibido();
	/*
	 * POST: Columna por usar obtenida.
	 */
	int obtenerColumnaPorUsarDelInputRecibido();
	/*
	 * POST: Operacion obtenida.
	 */
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
	void identificarInformacionIngresadaStdin(const std::string &input);

	/*
	 * POST: Retorna la ubicacion en el input en la que se esta leyendo
	 * de donde se van opteniendo valores separados por '\n'
	 */
	int obtenerValor(std::string *value, const std::string &input, int inicio);
};

#endif /* PARSERSOLICITUDUSUARIO_H_ */
