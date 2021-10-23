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
#include "GestorHilos.h"
#include "ProtecetedQueue.h"
#include "Particion.h"

int main(int argc, char *argv[]) {
	if(argc != 4)
		return 1;
	int columnas = atoi(argv[2]);
	std::string nombreDataset = argv[1];
	int hilos = atoi(argv[3]);
	ProtecetedQueue colaDeEjecuciones(hilos);
	GestorHilos gestorHilos(colaDeEjecuciones,hilos);
	ConsolaOperacionesDataset consola(colaDeEjecuciones);
	gestorHilos.iniciarOperacionHilosHastaQueUserFinaliceInput(nombreDataset,columnas);
	consola.solicitarYDispararSolicitudUsuario(argv);
	gestorHilos.verificarFinalizacionHilos();
	consola.imprimir();
	return 0;
}
