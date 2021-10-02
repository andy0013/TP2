/*
 * LectorDeArchivo.cpp
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#include "LectorDeArchivo.h"

LectorDeArchivo::LectorDeArchivo(std::string pathPorLeer) {
	this->pathDeArchivo = pathPorLeer;
}

void LectorDeArchivo::leerArchivoBinario(){
	std::ifstream archivo;
	this->archivo.open(this->pathDeArchivo.c_str(),std::ifstream::binary);
}

bool LectorDeArchivo::seLlegoAlFinDelArchivo(){
	return this->archivo.eof();
}


void LectorDeArchivo::obtenerDatosDeArchivo(int cantidadDeValores){
	char valoresLeidos[cantidadDeValores];
	this->archivo.getline(valoresLeidos, sizeof(valoresLeidos));

}

LectorDeArchivo::~LectorDeArchivo() {
}

