/*
 * Dispatcher.cpp
 *
 *  Created on: Oct 4, 2019
 *      Author: Gabriel Caicedo
 */
#include "../includes/dispatcher.h"

//get process from cpu
PCB Dispatcher::get_from_CPU() {
	is_valid_job_on_cpu = false;
	return cpu->get_process_off_core();

}

//set process_on_cpu true, send process to cpu
void Dispatcher::put_on_CPU(PCB &process) {
	is_valid_job_on_cpu = true;
	cpu->put_process_on_core(process);
}

//return true if valid process on cpu
bool Dispatcher::isValidJobOnCPU() {
	return is_valid_job_on_cpu;
}

//TODO fill in content

