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

#include "ColaProtegida.h"
#include "ConsolaOperacionesDataset.h"
#include "EjecutorTareas.h"
#include "LectorDeArchivo.h"
#include "OperacionStrategy.h"
#include "GestorHilos.h"
#include "Particion.h"

int main(int argc, char *argv[]) {
	if (argc != 4)
		return 1;
	int columnas, hilos;
	std::string nombreDataset = argv[1];
	sscanf(argv[2], "%i", &columnas);
	sscanf(argv[3], "%i", &hilos);
	ColaProtegida colaDeEjecuciones(hilos);
	ResultadoCompartidoMonitor resultadoProtegido;
	GestorHilos gestorHilos(colaDeEjecuciones, hilos);
	ConsolaOperacionesDataset consola(colaDeEjecuciones);
	gestorHilos.iniciarOperacionHilosHastaQueUserFinaliceInput(nombreDataset,
			columnas, resultadoProtegido);
	consola.solicitarYDispararSolicitudUsuario(argv, resultadoProtegido);
	gestorHilos.verificarFinalizacionHilos();
	resultadoProtegido.imprimirResultado();
	return 0;
}
