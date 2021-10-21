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
	int hilos = atoi(argv[3]);
	ProtecetedQueue colaDeEjecuciones(hilos);
	GestorHilos gestorHilos(colaDeEjecuciones,hilos);
	ConsolaOperacionesDataset consola(colaDeEjecuciones);
	gestorHilos.iniciarOperacionHilosHastaQueUserFinaliceInput();
	consola.solicitarYDispararSolicitudUsuario(argv);
	gestorHilos.verificarFinalizacionHilos();
	consola.imprimir();
	return 0;
}
