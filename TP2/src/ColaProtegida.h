/*
 * ProtecetedQueue.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef COLAPROTEGIDA_H_
#define COLAPROTEGIDA_H_

#include <queue>
#include <utility>
#include <thread>
#include "Particion.h"
#include <mutex>
#include <condition_variable>



class ColaProtegida {
private:
	std::queue<Particion> informacionCola;
    std::mutex m;
    bool terminamos;
    size_t limiteDeHilos;
    std::condition_variable colaVacia;
    std::condition_variable colaLlena;

    ColaProtegida(const ColaProtegida &other) = delete;

    ColaProtegida& operator=(const ColaProtegida &other) = delete;

public:
	explicit ColaProtegida(int threadsToUse);
	/*
	 * se modifica el bool terminamos, que se utilizaba como desencadenante
	 * para enviar una Particion Token que avise a los hilos que
	 * deben finalizar.
	 */
	void terminarQueue();
	/*
	 * Hace un push a la cola siempre y cuando el limite lo permita.
	 */
	void agregarParticionSiEsPosible(Particion particion);
	/*
	 * Retorna la Particion popeada
	 */
	Particion obtenerInformacionSiEsPosible();

	virtual ~ColaProtegida();
};

#endif /* COLAPROTEGIDA_H_ */
