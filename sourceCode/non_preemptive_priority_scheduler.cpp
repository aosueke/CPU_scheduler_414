#include "non_preemptive_priority_scheduler.h"

void NonPreemptivePriorityScheduler::run() {
    int time = 0;
    int completed = 0;
    int n = processes.size();

    while (completed < n) {
        Process* selected_process = nullptr;

        for (auto& process : processes) {
            if (process.arrival_time <= time && process.remaining_time > 0) {
                if (selected_process == nullptr || process.priority < selected_process->priority ||
                    (process.priority == selected_process->priority && process.arrival_time < selected_process->arrival_time)) {
                    selected_process = &process;
                }
            }
        }

        if (selected_process) {
            if (selected_process->start_time == -1) {
                selected_process->start_time = time;
            }

            time += selected_process->burst_time;
            selected_process->completion_time = time;
            selected_process->turnaround_time = selected_process->completion_time - selected_process->arrival_time;
            selected_process->waiting_time = selected_process->turnaround_time - selected_process->burst_time;

            selected_process->remaining_time = 0; // Mark as completed
            completed++;
        } else {
            time++;
        }
    }
}

void NonPreemptivePriorityScheduler::printStats() const {
    std::cout << "Non-Preemptive Priority Scheduling Results:\n";
    std::cout << "ID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";

    for (const auto& process : processes) {
        std::cout << process.id << '\t' << process.arrival_time << '\t'
                  << process.burst_time << '\t' << process.priority << '\t'
                  << process.completion_time << '\t' << process.turnaround_time << '\t'
                  << process.waiting_time << '\n';
    }
}
