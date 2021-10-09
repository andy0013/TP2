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
#include "SplitApplyCombineImpl.h"

using namespace std;

int main(int argc, char *argv[]) {

	std::string dataset = argv[1];
	int cantidadColumnasDataset = strtol(argv[2],NULL,10);
//	char *hilos = argv[3];
	char *input = NULL;
	size_t leido = 0;
	getline(&input,&leido,stdin);
	char filaInicio = input[0];
	char filaFin = input[2];
	char nroParticiones = input[4];
	char columna = input[6];
	std::string operacion;
	for(int i = 7; i < (int)(strlen(input)-1); i++){
		operacion += input[i];
	}

	SplitApplyCombineImpl* servicio = new SplitApplyCombineImpl(filaInicio, filaFin , operacion, nroParticiones);

	servicio->cargarDatosParaResolverOperaciones(dataset, cantidadColumnasDataset, columna);

	servicio->SplitApplyCombineImplementarOperacion();

	return 0;
}
