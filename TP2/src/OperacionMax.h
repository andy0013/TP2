/*
 * OperacionMax.h
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONMAX_H_
#define OPERACIONMAX_H_
#include "Operacion.h"

class OperacionMax :public Operacion{
	int valorActual;
public:
	OperacionMax();
	void resolverOperacion(int valor)override;
	void combineOperacion(int valor, int particiones)override;
	int obtenerValorActual()override;
	int obtenerCantiadDeVAloresActual()override;
	int obtenerValorFinal()override;
	virtual ~OperacionMax();
};

#endif /* OPERACIONMAX_H_ */
