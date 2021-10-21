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
	virtual int obtenerValorActual() = 0;
	virtual int obtenerCantiadDeVAloresActual() = 0;
	virtual int obtenerValorFinal() = 0;
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

	void resolverOperacion(int valor)override {
		this->valorActual += valor;
	}

	void combineOperacion(int valor, int particiones)override{
		this->resolverOperacion(valor);
	}

	int obtenerValorActual()override{
		return this->valorActual;
	}

	int obtenerCantiadDeVAloresActual()override{
			return 0;
	}

	int obtenerValorFinal()override{
		return this->valorActual;
	}

protected:
	~OperacionSuma(){}
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

	void resolverOperacion(int valor)override{
		if(valor > this->valorActual){
			this->valorActual = valor;
		}
	}

	void combineOperacion(int valor, int particiones)override{
		this->resolverOperacion(valor);
	}

	int obtenerValorActual()override{
		return this->valorActual;
	}

	int obtenerCantiadDeVAloresActual()override{
			return 0;
	}

	int obtenerValorFinal()override{
		return this->valorActual;
	}


protected:
	~OperacionMax(){}
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
		this->valorActual = 10000000;
	}

	void resolverOperacion(int valor)override{
		if (valor == 0){
			this->valorActual = valor;
		}else if (this->valorActual > valor){
			this->valorActual = valor;
		}
	}

	void combineOperacion(int valor, int particiones)override{
		this->resolverOperacion(valor);
	}

	int obtenerValorActual()override{
		return this->valorActual;
	}

	int obtenerCantiadDeVAloresActual()override{
		return 0;
	}

	int obtenerValorFinal()override{
		return this->valorActual;
	}

protected:
	~OperacionMin(){}
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

	void resolverOperacion(int valor)override{
		this->valorActual += valor;
		this->cantidadDeValores++;
	}

	void combineOperacion(int valor, int particiones)override{
		this->cantidadDeValores += particiones;
		this->valorActual += valor;
	}

	int obtenerValorActual()override{
		return this->valorActual;
	}

	int obtenerCantiadDeVAloresActual()override{
		return this->cantidadDeValores;
	}

	int obtenerValorFinal()override{
		return (this->valorActual/this->cantidadDeValores);
	}

protected:
	~OperacionMean(){}
};

#endif /* OPERACION_H_ */
