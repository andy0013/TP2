/*
 * Operacion.h
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#ifndef OPERACION_H_
#define OPERACION_H_

class Operacion {
public:
	virtual void resolverOperacion(int valor) = 0;
//	~Operacion();
};


/*
 *
 */
class OperacionSuma : public Operacion{
	int valorActual;
public:
	/*
	 *
	 */
	OperacionSuma(){
		this->valorActual = 0;
	}

	void resolverOperacion(int valor) {
		this->valorActual += valor;
	}

};


/*
 *
 */
class OperacionMax : public Operacion{
	int valorActual;
public:
	/*
	 *
	 */
	OperacionMax(){
		this->valorActual = 0;
	}

	void resolverOperacion(int valor){
		if(valor > this->valorActual ){
			this->valorActual = valor;

		}
	}

};


/*
 *
 */
class OperacionMin : public Operacion{
	int valorActual;
public:
	/*
	 *
	 */
	OperacionMin(){
		this->valorActual = 0;
	}


	void resolverOperacion(int valor){
		if(valor == 0){
			this->valorActual = valor;
		}else if(this->valorActual > valor){
			this->valorActual = valor;
		}
	}

};


/*
 *
 */
class OperacionMean : public Operacion{
	int valorActual;
	int cantidadDeValores;
public:
	/*
	 *
	 */
	OperacionMean(){
		this->cantidadDeValores = 0;
		this->valorActual = 0;
	}

	void resolverOperacion(int valor){
		this->cantidadDeValores ++;
		this->valorActual += valor;
	}

};



#endif /* OPERACION_H_ */
