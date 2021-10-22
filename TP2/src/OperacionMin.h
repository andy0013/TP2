/*
 * OperacionMin.h
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONMIN_H_
#define OPERACIONMIN_H_
#include "Operacion.h"
class OperacionMin:public Operacion{
	int valorActual;
public:
	OperacionMin();
	void resolverOperacion(int valor)override ;
	void combineOperacion(int valor, int particiones)override;
	int obtenerValorActual()override;
	int obtenerCantiadDeVAloresActual()override;
	int obtenerValorFinal()override;
	virtual ~OperacionMin();
};

#endif /* OPERACIONMIN_H_ */
