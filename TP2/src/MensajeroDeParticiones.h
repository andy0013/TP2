/*
 * MensajeroDeParticiones.h
 *
 *  Created on: 21 oct. 2021
 *      Author: andres
 */

#ifndef MENSAJERODEPARTICIONES_H_
#define MENSAJERODEPARTICIONES_H_
#include "ColaProtegida.h"
#include "GestorHilos.h"
#include "OperacionStrategy.h"
#include "ParserSolicitudUsuario.h"

class MensajeroDeParticiones {

	ParserSolicitudUsuario &infoIngreasadaPorUsuario;

	MensajeroDeParticiones(const MensajeroDeParticiones &other) = delete;

	MensajeroDeParticiones& operator=(const MensajeroDeParticiones &other) = delete;


public:
	explicit MensajeroDeParticiones(ParserSolicitudUsuario &infoIngreasadaPorUsuario);
	/*
	 * Envia la orden a la cola de terminar y
	 * en caso de que soliciten un pop, enviar
	 * el token al hilo correspondiente.
	 */
	void cerrarCola(ColaProtegida &colaDeEjecuciones);
	/*
	 * Crea la particion con los datos necesarios, y los envia a
	 * la cola compartida para que sea pusheada cuando sea posible.
	 */
	void crearParticionesYEnviarALaQueue(ColaProtegida &colaDeEjecuciones,
			int nroParticion);

	virtual ~MensajeroDeParticiones();

private:
	void enviarParticiones(int nroParticionesPorUsar,
			bool agregarParticionIncompleta, ColaProtegida &colaDeEjecuciones,
			int nroParticion, int columna);
};

#endif /* MENSAJERODEPARTICIONES_H_ */
