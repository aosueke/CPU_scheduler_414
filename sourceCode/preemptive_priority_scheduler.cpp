#include "preemptive_priority_scheduler.h"

void PreemptivePriorityScheduler::run() {
    int time = 0;
    int completed = 0;
    int n = processes.size();

    auto compare = [](const Process& a, const Process& b) {
        return (a.priority == b.priority) ? (a.arrival_time > b.arrival_time) : (a.priority > b.priority);
    };

    std::priority_queue<Process, std::vector<Process>, decltype(compare)> pq(compare);

    while (completed < n) {
        for (auto& process : processes) {
            if (process.arrival_time <= time && process.remaining_time > 0 && process.start_time == -1) {
                pq.push(process);
            }
        }

        if (!pq.empty()) {
            Process current = pq.top();
            pq.pop();

            for (auto& process : processes) {
                if (process.id == current.id) {
                    if (process.start_time == -1) {
                        process.start_time = time;
                    }
                    process.remaining_time--;
                    time++;

                    if (process.remaining_time == 0) {
                        process.completion_time = time;
                        process.turnaround_time = process.completion_time - process.arrival_time;
                        process.waiting_time = process.turnaround_time - process.burst_time;
                        completed++;
                    }
                    break;
                }
            }
        } else {
            time++;
        }
    }
}

void PreemptivePriorityScheduler::printStats() const {
    std::cout << "Preemptive Priority Scheduling Results:\n";
    std::cout << "ID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";

    for (const auto& process : processes) {
        std::cout << process.id << '\t' << process.arrival_time << '\t'
                  << process.burst_time << '\t' << process.priority << '\t'
                  << process.completion_time << '\t' << process.turnaround_time << '\t'
                  << process.waiting_time << '\n';
    }
}
