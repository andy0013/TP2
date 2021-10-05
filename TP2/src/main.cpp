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
#include "OperacionStrategy.h"
#include "LectorDeArchivo.h"

using namespace std;

int main(int argc, char *argv[]) {
	LectorDeArchivo* lector = new LectorDeArchivo("dataset",strtol(argv[2],NULL,10),1);
	lector->leerArchivoBinario();
	int numeroLeido = lector->obtenerDatosDeArchivo();

	OperacionStrategy* name = new OperacionStrategy();
	name->StrategyCrearOperacion("max");
	name->StrategyRealizarOperacion(4);
	name->StrategyRealizarOperacion(2);
	name->StrategyRealizarOperacion(100);
	name->StrategyRealizarOperacion(8);
	delete lector;
	delete name;
	return 0;
}
