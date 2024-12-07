#include "MLFQ.h"
#include <iostream>

MultilevelFeedbackQueue::MultilevelFeedbackQueueScheduler(int tq1, int tq2) : timeQuantum1(tq1), timeQuantum2(tq2) {}

void MultilevelFeedbackQueue::addProcess(const ProcessInfo& new_process) {
    All_processes.push_back(new_process);
    que1.push(&All_processes.back());
}

void MultilevelFeedbackQueueScheduler::run() {
    int curr_time = 0; //current time

    auto execute_Queue = [&](std::queue<ProcessInfo*>& que, int timeQuantum) {

        while (!que.empty()) {
            ProcessInfo* proc = que.front();
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
                 if (que.size() == que1.size()) {
                    que2.push(proc);
                } else if (que.size() == que2.size()) {
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
        ProcessInfo* proc = que3.front();
        que3.pop();

        proc->remain_time = 0;
        curr_time += proc->remain_time;

        proc->turnarnd_time = curr_time - proc->arr_time;
        proc->wait_time = proc->turnarnd_time - proc->burst_time;
    }
}
void MultilevelFeedbackQueueScheduler::printStats() {
    double avgWaitTime = 0, avg_turnarnd_time = 0;

    std::cout << "\nResults of Multilevel Feedback Queue Scheduling:\n";
    std::cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n";

    for (const auto& new_process : All_processes) {
        avgWaitTime += new_process.wait_time;
        avg_turnarnd_time += new_process.turnarnd_time;

        std::cout << new_process.id << "\t" << new_process.arr_time << "\t"
                  << new_process.burst_time << "\t" << new_process.wait_time << "\t"
                  << new_process.turnarnd_time << "\t\t" << new_process.respo_time << "\n";
    }
    std::cout << "\nAverage Waiting Time: " << avgWaitTime / All_processes.size() << "\n";
    std::cout << "Average Turnaround Time: " << avg_turnarnd_time / All_processes.size() << "\n";
}
