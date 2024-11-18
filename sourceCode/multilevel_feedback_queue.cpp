#include "MLFQ.h"
#include <iostream>

Multilevel_Feedback_Queue::Multilevel_Feedback_Queue(int tq1, int tq2) : timeQuantum1(tq1), timeQuantum2(tq2) {}

void Multilevel_Feedback_Queue::addProcess(const Process& new_process) {
    All_processes.push_back(new_process);
    que1.push(&All_processes.back());
}

void Multilevel_Feedback_Queue::run() {
    int current_time = 0;

    auto execute_Queue = [&](std::queue<Process*>& que, int time_quantum) {
        int quantum_used = 0;

        while (!queue.empty()) {
            Process* process = que.front();
            que.pop();

            // Recording response_time of first execution
            if (process->response_time == -1) {
                process->response_time = current_time - process->arrival_time;
            }
