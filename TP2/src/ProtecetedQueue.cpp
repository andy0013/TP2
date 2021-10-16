/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ProtecetedQueue.h"


ProtecetedQueue::ProtecetedQueue(int threadsToUse) {
	this->limitThreads = threadsToUse;
}

void ProtecetedQueue::addTaskIfPossible(Particion party) {
	std::unique_lock<std::mutex> lock(m);
	 while (this->threads.size() == this->limitThreads)
		 taskFull.wait(lock);

	 this->threads.push(party);
	 this->taskFull.notify_all();
}

Particion ProtecetedQueue::consumeTaskIfPosible() {
	 std::unique_lock<std::mutex> lock(m);
	 while (this->threads.size() == 0)
		 taskVoid.wait(lock);

	 Particion name = this->threads.front();
	 this->threads.pop();
	 this->taskVoid.notify_all();
	 return name;
}

ProtecetedQueue::~ProtecetedQueue(){

}
