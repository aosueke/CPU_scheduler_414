#ifndef PREEMPTIVE_PRIORITY_SCHEDULER_H
#define PREEMPTIVE_PRIORITY_SCHEDULER_H

#include "priority_scheduler.h"

class PreemptivePriorityScheduler : public PriorityScheduler {
public:
    void run() override;
    void printStats() const override;
};

#endif // PREEMPTIVE_PRIORITY_SCHEDULER_H
