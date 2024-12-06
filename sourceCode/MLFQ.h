#ifndef MLFQ_H
#define MLFQ_H

#include "processInfo.h"
#include <vector>
#include <queue>

class Multilevel_Feedback_Queue{
private:
    int tq1; // Queue 1 time quantum
    int tq2; // Queue 2 time quantum
    std::queue<ProcessInfo*> que1; // high priority queue
    std::queue<ProcessInfo*> que2; // med priority queue
    std::queue<ProcessInfo*> que3; // low priority queue
    std::vector<ProcessInfo> All_processes;

public:
    Multilevel_Feedback_Queue(int tq1, int tq2);
    void addProcess(const ProcessInfo& new_process);
    void run();
    void printProcStats();
};

#endif
