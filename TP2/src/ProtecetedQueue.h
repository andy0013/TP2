/*
 * ProtecetedQueue.h
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#ifndef PROTECETEDQUEUE_H_
#define PROTECETEDQUEUE_H_

#include <queue>
#include <thread>
#include "Particion.h"
#include <mutex>
#include <condition_variable>



class ProtecetedQueue {
private:
	std::queue<Particion> threads;
    std::mutex m;
    bool terminamos;
    size_t limitThreads;
    std::condition_variable taskVoid;
    std::condition_variable taskFull;

    ProtecetedQueue(const ProtecetedQueue &other) = delete;

    ProtecetedQueue& operator=(const ProtecetedQueue &other) = delete;

public:
	explicit ProtecetedQueue(int threadsToUse);

	void terminarQueue();

	void agregarParticionSiEsPosible(Particion particion);

	Particion obtenerParticionSiEsPosible();

	virtual ~ProtecetedQueue();
};

#endif /* PROTECETEDQUEUE_H_ */
