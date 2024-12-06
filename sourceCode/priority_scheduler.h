ifndef PRIORITY_SCHEDULER_H
#define PRIORITY_SCHEDULER_H
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    Process(int id, int arrival, int burst, int priority)
        : id(id), arrival_time(arrival), burst_time(burst),
          priority(priority), remaining_time(burst), 
          start_time(-1), completion_time(0), 
          turnaround_time(0), waiting_time(0) {}
};
// Base class for Priority Schedulers
class PriorityScheduler {
protected:
    std::vector<Process> processes;
public:
    void addProcess(const Process& p) {
        processes.push_back(p);
    }
    virtual void run() = 0; // Pure virtual function
    virtual void printStats() const;
};
#endif // PRIORITY_SCHEDULER_H
