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
	this->filaEnLaQueEstaSituado = 0;
}

void LectorDeArchivo::leerArchivoBinario(){
	this->archivo.open(this->pathDeArchivo.c_str(),std::ifstream::in |std::ifstream::out |std::ifstream::binary);
}

bool LectorDeArchivo::siguienteFilaValida(int filaFinal){
	return this->filaEnLaQueEstaSituado > filaFinal ? true : false;
}

void LectorDeArchivo::situarLectorEnFilaInicial(int nroDeFila){
//	uint16_t valorLeido;
//	for(int filaLeida = 0; filaLeida < nroDeFila ; filaLeida++){
//		this->archivo.read((char *)&valorLeido, sizeof(uint16_t));
//		this->filaEnLaQueEstaSituado++;
//	}
	this->archivo.seekg(nroDeFila*this->cantidadDeColumnas*2, this->archivo.beg);
}

int LectorDeArchivo::obtenerDatosDeArchivo(){
	uint16_t valorLeido;
	uint16_t numeroLeido;
	for(int i = 0; i < this->cantidadDeColumnas ; i++){

		this->archivo.read((char *)&valorLeido, sizeof(uint16_t));

		if(i == this->numeroDeColumna){
			numeroLeido = ntohs(valorLeido);
		}
	}
	this->filaEnLaQueEstaSituado++;
	return numeroLeido;
}
LectorDeArchivo::~LectorDeArchivo() {
}

