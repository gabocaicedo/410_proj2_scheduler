/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"

Stats::Stats(std::vector<PCB> &finished_vector) {
	vec = new std::vector<PCB>(finished_vector);
	av_wait_time = UNINITIALIZED;
	av_turnaround_time = UNINITIALIZED;
	av_response_time = UNINITIALIZED;

	calcStats();
}
void Stats::calcStats() {
	for (PCB job : *vec) {
		av_wait_time += job.finish_time - job.arrival_time
				- job.required_cpu_time;
		av_turnaround_time += job.finish_time - job.arrival_time;
		av_response_time += job.start_time - job.arrival_time;
	}

	av_wait_time /= vec->size();
	av_turnaround_time /= vec->size();
	av_response_time /= vec->size();
}

void Stats::showAllProcessInfo() {
	int size = vec->size();
	std::string process = "";
	for (int i = 0; i < size; i++) {
		process += "Process " + std::to_string(i + 1) + " Required CPU time:"
				+ std::to_string(vec->front().required_cpu_time) + " arrived:"
				+ std::to_string(vec->front().arrival_time) + " started: "
				+ std::to_string(vec->front().start_time) + " finished:"
				+ std::to_string(vec->front().finish_time) + "\n";
	}
	std::cout << process;
}

float Stats::get_av_response_time() {
	return av_response_time;
}
float Stats::get_av_turnaround_time() {
	return av_turnaround_time;
}

float Stats::get_av_wait_time() {
	return av_wait_time;
}
