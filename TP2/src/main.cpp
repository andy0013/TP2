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




int main(int argc, char *argv[]) {
	ConsolaOperacionesDataset* consola = new ConsolaOperacionesDataset();

	consola->solicitarYDispararSolicitudUsuario(argv);

	return 0;
}
