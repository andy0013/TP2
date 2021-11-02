/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ColaProtegida.h"


ColaProtegida::ColaProtegida(int threadsToUse) {
	this->limitThreads = threadsToUse;
	this->terminamos = false;
}

void ColaProtegida::agregarParticionSiEsPosible(Particion particionPorPushear) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	 while (this->informacionCola.size() == this->limitThreads){
		 this->taskFull.wait(unique_lock);
	 }
	 this->informacionCola.push(std::move(particionPorPushear));
	 this->taskVoid.notify_all();
}

void ColaProtegida::terminarQueue() {
	std::unique_lock<std::mutex> unique_lock(this->m);
	this->terminamos = true;
	this->taskVoid.notify_all();
}

Particion ColaProtegida::obtenerInformacionSiEsPosible() {
	 std::unique_lock<std::mutex> unique_lock(this->m);
	 while (this->informacionCola.empty()){
		 if (this->terminamos){
	     	 return Particion();
		 }
		 this->taskVoid.wait(unique_lock);
	 }
	 Particion name = std::move(this->informacionCola.front());
	 this->informacionCola.pop();
	 this->taskFull.notify_all();
	 return name;
}


ColaProtegida::~ColaProtegida(){}
