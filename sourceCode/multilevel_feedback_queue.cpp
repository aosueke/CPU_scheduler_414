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
  // executing processes from queues (priority order)
    execute_Queue(que1, timeQuantum1);
    execute_Queue(que2, timeQuantum2);

    // running remaining processes in queue 3 till completion
    while (!que3.empty()) {
        Process* proc = que3.front();
        que3.pop();

        proc->remain_time = 0;
        curr_time += proc->remain_time;

        proc->turnarnd_time = curr_time - proc->arr_time;
        proc->wait_time = proc->turnarnd_time - proc->burst_time;
    }
}
void MultilevelFeedbackQueue::printStats() {
    double avgWaitTime = 0, avg_turnarnd_time = 0;

    std::cout << "\nMultilevel Feedback Queue Scheduling Results:\n";
    std::cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n";

    for (const auto& process : All_processes) {
        avgWaitTime += process.wait_time;
        avg_turnarnd_time += process.turnarnd_time;

        std::cout << process.id << "\t" << process.arr_time << "\t"
                  << process.burst_time << "\t" << process.wait_time << "\t"
                  << process.turnarnd_time << "\t\t" << process.respo_time << "\n";
    }

