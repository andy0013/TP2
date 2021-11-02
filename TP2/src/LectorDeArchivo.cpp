/*
 * LectorDeArchivo.cpp
 *
 *  Created on: 30 sep. 2021
 *      Author: andres
 */

#include "LectorDeArchivo.h"


LectorDeArchivo::LectorDeArchivo(const std::string& pathPorLeer,
		int cantidadCols) :
	archivo(pathPorLeer),cantidadDeColumnas(cantidadCols) {}

void LectorDeArchivo::situarLectorEnFilaInicial(int nroDeFila) {
	int fila = nroDeFila * this->cantidadDeColumnas * 2;
	this->archivo.seekg(fila, this->archivo.beg);
}

int LectorDeArchivo::obtenerDatosDeArchivo(int numeroDeColumna) {
	uint16_t valorLeido;
	uint16_t numeroLeido = 0;
	for (int i = 0; i < this->cantidadDeColumnas; i++) {
		this->archivo.read((char*) &valorLeido, sizeof(uint16_t));

		if (i == numeroDeColumna) {
			numeroLeido = ntohs(valorLeido);
		}
	}
	return numeroLeido;
}
LectorDeArchivo::~LectorDeArchivo() {
	if(this->archivo)
		this->archivo.close();
}

