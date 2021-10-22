///*
// * Operacion.h
// *
// *  Created on: 30 sep. 2021
// *      Author: andres
// */
//
#ifndef OPERACION_H_
#define OPERACION_H_
//
class Operacion {
public:
	virtual void resolverOperacion(int valor) = 0;
	virtual void combineOperacion(int valor, int particiones) = 0;
	virtual int obtenerValorActual() = 0;
	virtual int obtenerCantiadDeVAloresActual() = 0;
	virtual void obtenerValorFinal() = 0;
	virtual ~Operacion(){}
};
#endif /* OPERACION_H_ */
