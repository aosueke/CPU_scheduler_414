#include "round_robin.h"
#include <queue>
#include <iostream>

// Constructor to set time quantum for round robin scheduling
RoundRobinScheduler::RoundRobinScheduler(int quantum) : time_quantum(quantum) {}

// Add a new process to the scheduler
void RoundRobinScheduler::addProcess(const Process& process) {
    processes.push_back(process);
}

// Run round robin scheduling
void RoundRobinScheduler::run() {
    std::queue<Process*> ready_queue; // Queue for processes ready to run

    // Push all processes into the ready queue
    for (auto& process : processes) {
        ready_queue.push(&process);
    }

    int current_time = 0; // Current time of execution

    while (!ready_queue.empty()) {
        Process* process = ready_queue.front(); // Get the first process in the queue
        ready_queue.pop(); // Remove it from the queue

        // If it's the first time this process runs, record its response time
        if (process->respo_time == -1) {
            process->respo_time = current_time - process->arr_time;
        }

        // Run the process for either the time quantum or the remaining time
        int exec_time = std::min(time_quantum, process->remain_time);
        process->remain_time -= exec_time;
        current_time += exec_time;

        // If process is done, calculate its turnaround and waiting time
        if (process->remain_time == 0) {
            process->is_completed = true;
            process->turnarnd_time = current_time - process->arr_time;
            process->wait_time = process->turnarnd_time - process->burst_time;
        } else {
            // If not done, push the process back into the queue
            ready_queue.push(process);
        }
    }
}

// Print stats for each process (waiting time, turnaround time, response time)
void RoundRobinScheduler::printStats() {
    double avg_wait_time = 0, avg_turnarnd_time = 0;

    std::cout << "\nRound Robin Scheduling Results:\n";
    std::cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n";

    for (const auto& process : processes) {
        avg_wait_time += process.wait_time;
        avg_turnarnd_time += process.turnarnd_time;

        std::cout << process.id << "\t" << process.arr_time << "\t"
                  << process.burst_time << "\t" << process.wait_time << "\t"
                  << process.turnarnd_time << "\t\t" << process.respo_time << "\n";
    }

    // Print average wait and turnaround times
    std::cout << "\nAverage Waiting Time: " << avg_wait_time / processes.size() << "\n";
    std::cout << "Average Turnaround Time: " << avg_turnarnd_time / processes.size() << "\n";
}
