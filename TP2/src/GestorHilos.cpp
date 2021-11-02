#include "GestorHilos.h"

GestorHilos::GestorHilos(ColaProtegida &colaCompartida, int cantidadHilos) :
		colaCompartida(colaCompartida) {
	this->cantidadHilos = cantidadHilos;
}

void GestorHilos::iniciarOperacionHilosHastaQueUserFinaliceInput(std::string dataset
		, int columnas,OperacionMonitor& resultadoProtegido) {
	for (int i = 0; i < this->cantidadHilos; i++) {
		EjecutorTareas hilo(this->colaCompartida,dataset,columnas,resultadoProtegido);
		this->operacionPorDisparar.push_back(std::move(hilo));
	}

	for (int i = 0; i < this->cantidadHilos; i++) {
		this->hilosEnCurso.push_back(
				new std::thread(std::ref(this->operacionPorDisparar[i])));
	}
}

void GestorHilos::verificarFinalizacionHilos() {
	for (int i = 0; i < this->cantidadHilos; i++) {
		this->hilosEnCurso[i]->join();
	}
}

GestorHilos::~GestorHilos() {
	for (int i = 0; i < this->cantidadHilos; i++) {
		delete this->hilosEnCurso[i];
	}
}

