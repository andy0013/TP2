
#ifndef GESTORHILOS_H_
#define GESTORHILOS_H_
#include <string>
#include "EjecutorTareas.h"

#include <cstdio>
#include <vector>
#include <thread>
#include "ColaProtegida.h"



class GestorHilos {
private:
	int cantidadHilos;

	ColaProtegida& colaCompartida;

	std::vector<std::thread*> hilosEnCurso;

	std::vector<EjecutorTareas> operacionPorDisparar;

	GestorHilos(const GestorHilos &other) = delete;

	GestorHilos& operator=(const GestorHilos &other) = delete;


public:
	/*
	 * Iniciamos clase, recibe como parametro sus atributos.
	 */
	GestorHilos(ColaProtegida& colaCompartida,int cantidadHilos);

	void iniciarOperacionHilosHastaQueUserFinaliceInput(std::string dataset
			, int columnas,OperacionMonitor& resultadoProtegido);

	void verificarFinalizacionHilos();

	virtual ~GestorHilos();
};
#endif /* GESTORHILOS_H_ */
