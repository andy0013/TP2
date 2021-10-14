//============================================================================
// Name        : TP2.cpp
// Author      : Andres
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ConsolaOperacionesDataset.h"
#include "LectorDeArchivo.h"
#include "OperacionMonitor.h"
#include "OperacionStrategy.h"
#include "Particion.h"
#include <cstdio>
#include <vector>
#include <string>
#include <thread>
#include <mutex>



int main(int argc, char *argv[]) {
//	ConsolaOperacionesDataset* consola = new ConsolaOperacionesDataset();
//
//	consola->solicitarYDispararSolicitudUsuario(argv);

	char hilos = 8;
	int filasPorParticiones = 2;
	int finicio = 0;
	int ffinal = 15;
	LectorDeArchivo* archivo = new LectorDeArchivo("dataset",4,0);
	OperacionStrategy* operacion = new OperacionStrategy();
	operacion->StrategyCrearOperacion("sum");
	archivo->leerArchivoBinario();
	archivo->situarLectorEnFilaInicial(finicio);
	OperacionMonitor colaDeEjecuciones(operacion);
	while(archivo->siguienteFilaValida(ffinal)){
		std::vector<Particion> counters;
		std::vector<std::thread*> threads;
		for(int i = 0; i < hilos ; i++){
			Particion particion(colaDeEjecuciones, archivo,filasPorParticiones);
			counters.push_back(particion);
		}


		for(size_t i = 0; i < counters.size() ; i++){
			threads.push_back(new std::thread(std::ref(counters[i])));
		}

		for(size_t i = 0; i < threads.size() ; i++){
			threads[i]->join();
		}
	}
	colaDeEjecuciones.imprimirResultado();

	return 0;
}
