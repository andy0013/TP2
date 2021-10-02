/*
 * Solicitud.h
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
#include <string>

class Solicitud {

	int inicioDeFila;
	int finDeFila;
	int nroDeColumna;
	int nroDeParticiones;
	std::string operacion;

public:
	Solicitud(int inicioDeFila,int finDeFila,int nroDeColumna,int nroDeParticion,std::string operacion);

	void realizarOperacion();


	virtual ~Solicitud();
};

#endif /* SOLICITUD_H_ */
