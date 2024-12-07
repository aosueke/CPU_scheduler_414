#ifndef MULTILEVEL_QUEUE_H
#define MULTILEVEL_QUEUE_H

#include "processInfo.h"
#include <vector>

class MultilevelQueueScheduler {
private:
    std::vector<ProcessInfo> queue1;
    std::vector<ProcessInfo> queue2;

    int tq1, tq2;  // Time quantum for queue1 and queue2

public:
    // Default constructor (no parameters)
    MultilevelQueueScheduler() : tq1(0), tq2(0) {
        // Default time quantum values for both queues
    }

    // Constructor that accepts two time quanta
    MultilevelQueueScheduler(int tq1, int tq2) {
        this->tq1 = tq1;
        this->tq2 = tq2;
    }

    // Adds a process to a specific queue
    void addProcess(const ProcessInfo& process, int queue_level);

    // Executes the scheduling algorithm
    void run();

    // Prints statistics about the scheduling
    void printStats();
};

#endif
