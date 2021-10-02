//============================================================================
// Name        : TP2.cpp
// Author      : Andres
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "OperacionStrategy.h"

using namespace std;

int main(int argc, char *argv[]) {


	OperacionStrategy* name = new OperacionStrategy();
	name->StrategyCrearOperacion("max");
	name->StrategyRealizarOperacion(4);
	name->StrategyRealizarOperacion(2);
	name->StrategyRealizarOperacion(100);
	name->StrategyRealizarOperacion(8);
	return 0;
}
