/*
 * OperacionMean.h
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONMEAN_H_
#define OPERACIONMEAN_H_
#include "Operacion.h"

class OperacionMean: public Operacion{
	int valorActual;
	int cantidadDeValores;
public:
	OperacionMean();
	void resolverOperacion(int valor)override ;
	void combineOperacion(int valor, int particiones)override;
	int obtenerValorActual()override;
	int obtenerCantiadDeVAloresActual()override;
	int obtenerValorFinal()override;
	virtual ~OperacionMean();
};

#endif /* OPERACIONMEAN_H_ */
