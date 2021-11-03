/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ColaProtegida.h"

ColaProtegida::ColaProtegida(int threadsToUse) {
	this->limiteDeHilos = threadsToUse;
	this->terminamos = false;
}

void ColaProtegida::agregarParticionSiEsPosible(Particion particionPorPushear) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	while (this->informacionCola.size() == this->limiteDeHilos) {
		this->colaLlena.wait(unique_lock);
	}
	this->informacionCola.push(std::move(particionPorPushear));
	this->colaVacia.notify_all();
}

void ColaProtegida::terminarQueue() {
	std::unique_lock<std::mutex> unique_lock(this->m);
	this->terminamos = true;
	this->colaVacia.notify_all();
}

Particion ColaProtegida::obtenerInformacionSiEsPosible() {
	std::unique_lock<std::mutex> unique_lock(this->m);
	while (this->informacionCola.empty()) {
		if (this->terminamos) {
			return Particion();
		}
		this->colaVacia.wait(unique_lock);
	}
	Particion name = std::move(this->informacionCola.front());
	this->informacionCola.pop();
	this->colaLlena.notify_all();
	return name;
}

ColaProtegida::~ColaProtegida() {
}
