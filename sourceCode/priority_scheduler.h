#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Process {
    int id;                 // Unique process ID
    int arrival_time;       // Arrival time of the process
    int burst_time;         // Burst time of the process
    int priority;           // Priority of the process (lower is higher priority)
    int remaining_time;     // Remaining time for the process (used in preemptive scheduling)
    int start_time;         // Start time of the process
    int completion_time;    // Completion time of the process
    int turnaround_time;    // Turnaround time (completion_time - arrival_time)
    int waiting_time;       // Waiting time (turnaround_time - burst_time)

    // Constructor to initialize process attributes
    Process(int id, int arrival, int burst, int priority)
        : id(id), arrival_time(arrival), burst_time(burst),
          priority(priority), remaining_time(burst), 
          start_time(-1), completion_time(0), 
          turnaround_time(0), waiting_time(0) {}
};

// Base class for Priority Schedulers
class PriorityScheduler {
protected:
    std::vector<Process> processes;  // List of processes

public:
    // Add a process to the list
    void addProcess(const Process& p) {
        processes.push_back(p);
    }

    // Pure virtual function to be implemented by derived classes
    virtual void run() = 0;

    // Print the statistics of all processes
    virtual void printStats() const {
        std::cout << "Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
        for (const auto& process : processes) {
            std::cout << process.id << "\t\t"
                      << process.arrival_time << "\t\t"
                      << process.burst_time << "\t\t"
                      << process.priority << "\t\t"
                      << process.waiting_time << "\t\t"
                      << process.turnaround_time << "\n";
        }
    }
};

#endif // PRIORITY_SCHEDULER_H
