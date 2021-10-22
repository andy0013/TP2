/*
 * LectorDeArchivo.cpp
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#include "LectorDeArchivo.h"

LectorDeArchivo::LectorDeArchivo(const std::string pathPorLeer,
		int cantidadCols, int nroCols) {
	this->pathDeArchivo = pathPorLeer;
	this->cantidadDeColumnas = cantidadCols;
	this->numeroDeColumna = nroCols;
	this->archivo.open(this->pathDeArchivo.c_str(),
			std::ifstream::in | std::ifstream::out | std::ifstream::binary);
}

void LectorDeArchivo::situarLectorEnFilaInicial(int nroDeFila) {
	int fila = nroDeFila * this->cantidadDeColumnas * 2;
	this->archivo.seekg(fila, this->archivo.beg);
}

int LectorDeArchivo::obtenerDatosDeArchivo() {
	uint16_t valorLeido;
	uint16_t numeroLeido = 0;
	for (int i = 0; i < this->cantidadDeColumnas; i++) {
		this->archivo.read((char*) &valorLeido, sizeof(uint16_t));

		if (i == this->numeroDeColumna) {
			numeroLeido = ntohs(valorLeido);
		}
	}
	return numeroLeido;
}
LectorDeArchivo::~LectorDeArchivo() {
}

