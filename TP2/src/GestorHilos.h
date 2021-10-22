
#ifndef GESTORHILOS_H_
#define GESTORHILOS_H_
#include <string>
#include "ProtecetedQueue.h"
#include "EjecutorTareas.h"

#include <cstdio>
#include <vector>
#include <thread>



class GestorHilos {
private:
	int cantidadHilos;
	std::mutex mutex;
	ProtecetedQueue& colaCompartida;

	std::vector<std::thread*> hilosEnCurso;

	std::vector<EjecutorTareas> operacionPorDisparar;

public:
	/*
	 * Iniciamos clase, recibe como parametro sus atributos.
	 */
	GestorHilos(ProtecetedQueue& colaCompartida,int cantidadHilos);

	void iniciarOperacionHilosHastaQueUserFinaliceInput(std::string dataset
			, int columnas);

	void verificarFinalizacionHilos();

	virtual ~GestorHilos();
};
#endif /* GESTORHILOS_H_ */
