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
	virtual void combineOperacion(int valor, int particiones) = 0;
protected:
	~Operacion();
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

	void combineOperacion(int valor, int particiones){
		this->resolverOperacion(valor);
	}
protected:
	~OperacionSuma(){

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

	void combineOperacion(int valor, int particiones){
		this->resolverOperacion(valor);
	}

protected:

	~OperacionMax(){

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

	void combineOperacion(int valor, int particiones){
		this->resolverOperacion(valor);
	}

protected:

	~OperacionMin(){

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

	void combineOperacion(int valor, int particiones){
		this->cantidadDeValores += particiones;
		this->valorActual += valor;
	}

protected:

	~OperacionMean(){

	}

};



#endif /* OPERACION_H_ */
