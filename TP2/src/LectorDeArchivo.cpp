/*
 * LectorDeArchivo.cpp
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#include "LectorDeArchivo.h"

LectorDeArchivo::LectorDeArchivo(std::string pathPorLeer, int cantidadCols, int nroCols) {
	this->pathDeArchivo = pathPorLeer;
	this->cantidadDeColumnas = cantidadCols;
	this->numeroDeColumna = nroCols;
}

void LectorDeArchivo::leerArchivoBinario(){
	this->archivo.open(this->pathDeArchivo.c_str(),std::ifstream::in |std::ifstream::out |std::ifstream::binary);
}

bool LectorDeArchivo::seLlegoAlFinDelArchivo(){
	return this->archivo.eof();
}


int LectorDeArchivo::obtenerDatosDeArchivo(){
	uint16_t valorLeido;
	for(int i = 0; i < this->cantidadDeColumnas ; i++){

		if(i == this->numeroDeColumna){

			this->archivo.read((char *)&valorLeido, sizeof(uint16_t));

		}
	}
	uint16_t numeroLeido = ntohs(valorLeido);
	return numeroLeido;
}
LectorDeArchivo::~LectorDeArchivo() {
}

