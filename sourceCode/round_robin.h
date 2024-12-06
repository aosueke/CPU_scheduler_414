#ifndef ROUND_ROBIN_H
#define ROUND_ROBIN_H

#include "processInfo.h"
#include <vector>
#include <queue>

class RoundRobinScheduler {
private:
    int time_quantum; // Time quantum for round-robin
    std::vector<ProcessInfo> processes; // List of all processes

public:
    RoundRobinScheduler(int quantum); // Constructor to set time quantum
    void addProcess(const ProcessInfo& process); // Add new process
    void run(); // Run the round robin scheduling
    void printStats(); // Print process stats (waiting, turnaround, etc.)
};

#endif
