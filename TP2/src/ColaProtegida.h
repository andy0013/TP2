/*
 * ProtecetedQueue.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef COLAPROTEGIDA_H_
#define COLAPROTEGIDA_H_

#include <queue>
#include <thread>
#include "Particion.h"
#include <mutex>
#include <condition_variable>



class ColaProtegida {
private:
	std::queue<Particion> informacionCola;
    std::mutex m;
    bool terminamos;
    size_t limitThreads;
    std::condition_variable taskVoid;
    std::condition_variable taskFull;

    ColaProtegida(const ColaProtegida &other) = delete;

    ColaProtegida& operator=(const ColaProtegida &other) = delete;

public:
	explicit ColaProtegida(int threadsToUse);

	void terminarQueue();

	void agregarParticionSiEsPosible(Particion particion);

	Particion obtenerInformacionSiEsPosible();

	virtual ~ColaProtegida();
};

#endif /* COLAPROTEGIDA_H_ */
