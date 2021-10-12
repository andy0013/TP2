/*
 * OperacionStrategy.h
 *
 *  Created on: 1 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONSTRATEGY_H_
#define OPERACIONSTRATEGY_H_
#include "Operacion.h"
#include <string>
#include <cstring>



class OperacionStrategy {
private:
	Operacion *operacion;
public:
	OperacionStrategy();
	void StrategyCrearOperacion(std::string operacion);
	void StrategyRealizarOperacion(int valor);
	int StrategyObtenerValorFinalOperacion();
	void StrategyCombineOperacion(OperacionStrategy* particionNueva, int nroParticiones);
	virtual ~OperacionStrategy();
private:
	int StrategyObtenerValorOperacion();
};

#endif /* OPERACIONSTRATEGY_H_ */
