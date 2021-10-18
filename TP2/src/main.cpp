//============================================================================
// Name        : TP2.cpp
// Author      : Andres
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <thread>
#include <stdlib.h>
#include "ConsolaOperacionesDataset.h"
#include "EjecutorTareas.h"
#include "LectorDeArchivo.h"
#include "OperacionStrategy.h"
#include "ProtecetedQueue.h"
#include "Particion.h"

int main(int argc, char *argv[]) {
//	ConsolaOperacionesDataset* consola = new ConsolaOperacionesDataset();
//
//	consola->solicitarYDispararSolicitudUsuario(argv);
	int nroParticiones = 2;
	int filaFin = 15;
	int hilos = 2;
	ProtecetedQueue colaDeEjecuciones(hilos);
	std::vector<EjecutorTareas> threads;
	std::vector<std::thread*> trya;
	for (int i = 0; i < hilos; i++) {
		EjecutorTareas hilo(colaDeEjecuciones);
		threads.push_back(hilo);
	}

	LectorDeArchivo *gestorDeDatos = new LectorDeArchivo("dataset", 4, 1);
	gestorDeDatos->leerArchivoBinario();
	OperacionStrategy *operacionStrategy = new OperacionStrategy();
	operacionStrategy->StrategyCrearOperacion("sum");
	OperacionMonitor operacion(operacionStrategy,filaFin);
	std::vector<Particion> particiones;
	for (size_t i = 0; i < threads.size(); i++) {
		trya.push_back(new std::thread(std::ref(threads[i])));
	}

	for (int i = 0; i < 8; i++) {
		Particion particion(operacion,gestorDeDatos,2);
		colaDeEjecuciones.addTaskIfPossible(&particion);
	}

	colaDeEjecuciones.closeTask();

	for (size_t i = 0; i < threads.size(); i++) {
		trya[i]->join();
	}

	operacion.imprimirResultado();


	return 0;
}
