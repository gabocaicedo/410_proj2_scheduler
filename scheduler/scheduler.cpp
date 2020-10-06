/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "../includes/scheduler.h"

void Scheduler::add(PCB p) {
	ready_q->push(p);
	sort();
}

//get next process
PCB Scheduler::getNext() {
	PCB temp = ready_q->front();
	ready_q->pop();
	sort();
	return temp;
}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {
	return ready_q->empty();
}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {

	return p.remaining_cpu_time <= 0;


	}

//TODO fill in content

