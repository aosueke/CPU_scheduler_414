#ifndef NON_PREEMPTIVE_PRIORITY_SCHEDULER_H
#define NON_PREEMPTIVE_PRIORITY_SCHEDULER_H

#include "priority_scheduler.h"

class NonPreemptivePriorityScheduler : public PriorityScheduler {
public:
    void run() override;
    void printStats() const override;
};

#endif // NON_PREEMPTIVE_PRIORITY_SCHEDULER_H
