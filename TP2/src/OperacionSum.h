/*
 * OperacionSum.h
 *
 *  Created on: 22 oct. 2021
 *      Author: andres
 */

#ifndef OPERACIONSUM_H_
#define OPERACIONSUM_H_
#include "Operacion.h"
class OperacionSum :public Operacion{
	int valorActual;
public:
	OperacionSum();
	void resolverOperacion(int valor)override ;
	void combineOperacion(int valor, int particiones)override;
	int obtenerValorActual()override;
	int obtenerCantiadDeVAloresActual()override;
	int obtenerValorFinal()override;
	~OperacionSum();
};

#endif /* OPERACIONSUM_H_ */
