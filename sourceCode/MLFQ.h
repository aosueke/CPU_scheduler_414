#ifndef MLFQ_H
#define MLFQ_H

#include "process.h"
#include <vector>
#include <queue>

class Multilevel_Feedback_Queue{
private:
    int tq1; // Queue 1 time quantum
    int tq2; // Queue 2 time quantum
    std::queue<Process*> que1; // high priority queue
    std::queue<Process*> que2; // med priority queue
    std::queue<Process*> que3; // low priority queue
    std::vector<Process> processes;

public:
    Multilevel_Feedback_Queue(int tq1, int tq2);
    void addProcess(const Process& new_process);
    void run();
    void printProcStats();
};

#endif
