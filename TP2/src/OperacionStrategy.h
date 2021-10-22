/*
 * OperacionStrategy.h
 *
 *  Created on: 1 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONSTRATEGY_H_
#define OPERACIONSTRATEGY_H_
#include "Operacion.h"
#include "OperacionMax.h"
#include "OperacionMin.h"
#include "OperacionMean.h"
#include "OperacionSum.h"
#include <string>
#include <cstring>



class OperacionStrategy {
private:
	Operacion *operacion;
	std::string tipoDeOperacion;

public:
	OperacionStrategy();
	/*
	 * Inicializa la operacion adecuada en base
	 * al string recibido
	 */
	void StrategyCrearOperacion(std::string operacion);
	/*
	 * Realiza la operacion, esta es distinta dependiendo cual
	 * fue inicializada previamente.Aplica polimorfismo.
	 */
	void StrategyRealizarOperacion(int valor);
	/*
	 * Mediante la operacion se retorna el valor
	 * final.
	 */
	void StrategyImprimirValorFinalOperacion();
	/*
	 * Combina los valores de su operacion - con otra operacion.
	 */
	void StrategyCombineOperacion(OperacionStrategy* particionNueva);

	void StrategyCrearOperacionParcial(OperacionStrategy* particionNueva);

	virtual ~OperacionStrategy();

private:
	/*
	 * POST: Valor de la operacion que contiene.
	 */
	int StrategyObtenerValorOperacion();
	/*
	 * POST: Valor de la cantidad de valores usados en la particion actual.
	 */
	int StrategyObtenerCantidadDeFilasUsadasParcial();
};

#endif /* OPERACIONSTRATEGY_H_ */
