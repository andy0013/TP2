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
    int limitThreads;
    std::condition_variable taskVoid;
    std::condition_variable taskFull;
public:
	ProtecetedQueue(int threadsToUse);

	void closeTask();

	void addTaskIfPossible(Particion particion);

	Particion consumeTaskIfPosible();

	virtual ~ProtecetedQueue();
};

#endif /* PROTECETEDQUEUE_H_ */
