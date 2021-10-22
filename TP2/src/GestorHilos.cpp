#include "GestorHilos.h"

GestorHilos::GestorHilos(ProtecetedQueue &colaCompartida, int cantidadHilos) :
		colaCompartida(colaCompartida) {
	this->cantidadHilos = cantidadHilos;
//	this->hilosSiguenEjecutando = true;
}

void GestorHilos::iniciarOperacionHilosHastaQueUserFinaliceInput() {
	for (int i = 0; i < this->cantidadHilos; i++) {
//		EjecutorTareas hilo(this->colaCompartida,this->hilosSiguenEjecutando);
		EjecutorTareas hilo(this->colaCompartida);
		this->operacionPorDisparar.push_back(hilo);
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
}

