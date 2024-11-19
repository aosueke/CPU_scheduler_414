#include "MLFQ.h"
#include <iostream>

Multilevel_Feedback_Queue::Multilevel_Feedback_Queue(int tq1, int tq2) : timeQuantum1(tq1), timeQuantum2(tq2) {}

void Multilevel_Feedback_Queue::addProcess(const Process& new_process) {
    All_processes.push_back(new_process);
    que1.push(&All_processes.back());
}

void Multilevel_Feedback_Queue::run() {
    int current_time = 0;

    auto execute_Queue = [&](std::queue<Process*>& que, int timeQuantum) {
        int quantum_used = 0;

        while (!que.empty()) {
            Process* proc = que.front();
            que.pop();

            // Recording response_time of first execution
            if (proc->response_time == -1) {
                proc->response_time = current_time - proc->arrival_time;
            }
            
            int execTime = std::min(timeQuantum, proc->remaining_time); // execution time
            proc->remaining_time -= execTime;
            current_time += execTime;

            if (proc->remaining_time == 0) {
                proc->completed = true;
                proc->turnaround_time = current_time - proc->arrival_time;
                proc->waiting_time = proc->turnaround_time - proc->burst_time;
            } else {
                // Move to the next queue
                if (que == que1) {
                    que2.push(proc);
                } else if (que == que2) {
                    que3.push(proc);
                }
            }
        }
    };
