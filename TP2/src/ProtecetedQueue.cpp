/*
 * ProtecetedQueue.cpp
 *
 *  Created on: 16 oct. 2021
 *      Author: andres
 */

#include "ProtecetedQueue.h"


ProtecetedQueue::ProtecetedQueue(int threadsToUse) {
	this->limitThreads = threadsToUse;
	this->terminamos = false;
}

void ProtecetedQueue::addTaskIfPossible(Particion party) {
	std::unique_lock<std::mutex> unique_lock(this->m);
	 while (this->threads.size() == this->limitThreads){
		 this->taskFull.wait(unique_lock);
	 }
	 this->threads.push(party);
	 this->taskVoid.notify_all();
}

void ProtecetedQueue::closeTask() {
	std::unique_lock<std::mutex> unique_lock(this->m);
	this->terminamos = true;
	this->taskVoid.notify_all();
}

Particion ProtecetedQueue::consumeTaskIfPosible() {
	 std::unique_lock<std::mutex> unique_lock(this->m);
	 while (this->threads.empty()){
		 if (this->terminamos){
			 OperacionMonitor gg;
			 Particion token(gg);
			 return token;
		 }
		 this->taskVoid.wait(unique_lock);
	 }
	 Particion name = this->threads.front();
	 this->threads.pop();
	 this->taskFull.notify_all();
	 return name;
}


ProtecetedQueue::~ProtecetedQueue(){}
