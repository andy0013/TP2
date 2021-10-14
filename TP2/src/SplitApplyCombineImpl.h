/*
 * SplitApplyCombineImpl.h
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#ifndef SPLITAPPLYCOMBINEIMPL_H_
#define SPLITAPPLYCOMBINEIMPL_H_
#include <string>
#include "LectorDeArchivo.h"
#include "Operacion.h"
#include "OperacionStrategy.h"
#include "OperacionMonitor.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Particion.h"
#include <cstdio>
#include <vector>
#include <thread>



class SplitApplyCombineImpl {
private:
	int filaInicio;

	int nroParticiones;

	int filaFin;

	int hilos;

	LectorDeArchivo* gestorDeDatos;

	OperacionStrategy* operacionStrategy;

public:
	/*
	 * Iniciamos clase, recibe como parametro sus atributos.
	 */
	SplitApplyCombineImpl(int filaInicio, int filaFin, OperacionStrategy* operacionPorUsar, int nroParticiones);

	/*
	 * PRE: Recibe los argumentos de la consulta, recibe la columna ingresad por input.
	 * POST: void
	 * Inicializa el atributo LectorDeArchivo, y conociendo los argumentos
	 * inicializa la Operacion.
	 */
	void cargarDatosParaResolverOperaciones(char *argv[], int columnaDondeOperar);

	/*
	 * POST: void
	 * Realiza la creacion de cada particion y itera mientras
	 * es necesario, luego combina las particiones.
	 */
	void SplitApplyCombineImplementarOperacion();

	/*
	 * POST: Retorna el resultado (int) final de una particion.
	 */
	int SplitApplyCombineResultadoOperacion();

	virtual ~SplitApplyCombineImpl();

private:
	/*
	 * POST: retorna un bool, se ocupa de leer los datos de la particion
	 * el bool indica si en medio de la lectura de la particion
	 * llegamos a la fila final permitida
	 */
	bool SplitApply(OperacionStrategy* particion);

	/*
	 * Combina los datos de 2 particiones.
	 */
	void Combine(OperacionStrategy* particion, OperacionStrategy* nuevaParticion);
};
#endif /* SPLITAPPLYCOMBINEIMPL_H_ */
