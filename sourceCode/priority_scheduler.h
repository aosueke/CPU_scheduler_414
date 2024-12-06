#ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H

#include "processInfo.h"
#include <vector>

class PriorityScheduler {
private:
    bool preemptive;
    std::vector<ProcessInfo> processes;

public:
    PriorityScheduler(bool is_preemptive);
    void addProcess(const ProcessInfo& process);
    void run();
    void printStats();
};

#endif
