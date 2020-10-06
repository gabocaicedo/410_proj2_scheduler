/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */
using namespace std;
#include "../includes/scheduler_SRTF.h"
#include <algorithm>
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	// switch if a faster job in queue
	if (p.remaining_cpu_time <= 0) {
		return true;
	}

	if (!ready_q->empty()
			&& p.remaining_cpu_time > ready_q->front().remaining_cpu_time) {
		return true;
	} else {
		return false;
	}
}
bool cpu_time_sort(const PCB& x, const PCB& y) {
	return x.remaining_cpu_time > y.remaining_cpu_time;
}
//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	vector<PCB> queue;

	while(!ready_q->empty()){
		queue.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(queue.begin(),queue.end(), cpu_time_sort);
	while(!queue.empty()){
		ready_q->push(queue.back());
		queue.pop_back();
	}
}

//TODO fill in content
