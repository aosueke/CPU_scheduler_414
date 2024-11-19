#include "MLFQ.h"
#include <iostream>

Multilevel_Feedback_Queue::Multilevel_Feedback_Queue(int tq1, int tq2) : timeQuantum1(tq1), timeQuantum2(tq2) {}

void Multilevel_Feedback_Queue::addProcess(const Process& new_process) {
    All_processes.push_back(new_process);
    que1.push(&All_processes.back());
}

void Multilevel_Feedback_Queue::run() {
    int curr_time = 0; //current time

    auto execute_Queue = [&](std::queue<Process*>& que, int timeQuantum) {
        int quantum_used = 0;

        while (!que.empty()) {
            Process* proc = que.front();
            que.pop();

            // Recording response_time of first execution
            if (proc->respo_time == -1) {
                proc->respo_time = curr_time - proc->arr_time;
            }
            
            int execTime = std::min(timeQuantum, proc->remain_time); // execution time
            proc->remain_time -= execTime;
            curr_time += execTime;

            if (proc->remain_time == 0) {
                proc->is_completed = true;
                proc->turnarnd_time = curr_time - proc->arr_time;
                proc->wait_time = proc->turnarnd_time - proc->burst_time;
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
