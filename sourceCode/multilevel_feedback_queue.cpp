#include "MLFQ.h"
#include <iostream>

Multilevel_Feedback_Queue::Multilevel_Feedback_Queue(int tq1, int tq2) : timeQuantum1(tq1), timeQuantum2(tq2) {}

void Multilevel_Feedback_Queue::addProcess(const Process& new_process) {
    All_processes.push_back(new_process);
    que1.push(&All_processes.back());
}
