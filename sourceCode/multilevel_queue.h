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
    void addProcess(const ProcessInfo& process, int queue_level) {
        if (queue_level == 1) {
            queue1.push_back(process); // Add to queue1
        } else if (queue_level == 2) {
            queue2.push_back(process); // Add to queue2
        }
    }

    // Executes the scheduling algorithm
    void run() {
        // Add your scheduling logic here (e.g., round robin for each queue)
    }

    // Prints statistics about the scheduling
    void printStats() {
        std::cout << "Queue 1 size: " << queue1.size() << "\n";
        std::cout << "Queue 2 size: " << queue2.size() << "\n";
    }
};

#endif
