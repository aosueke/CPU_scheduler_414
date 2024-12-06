#include <iostream>
#include "round_robin.h"
#include "priority_scheduler.h"
#include "preemptive_priority_scheduler.h"
#include "non_preemptive_priority_scheduler.h"
#include "multilevel_queue.h"
#include "MLFQ.h"

int main() {
    int choice;
    std::cout << "Advanced CPU Scheduler\n";
    std::cout << "1. Round Robin\n";
    std::cout << "2. Preemptive Priority Scheduling\n";
    std::cout << "3. Non-Preemptive Priority Scheduling\n";
    std::cout << "4. Multilevel Queue\n";
    std::cout << "5. Multilevel Feedback Queue\n";
    std::cout << "Choose a scheduling algorithm: ";
    std::cin >> choice;

    if (choice == 2) {
        PreemptivePriorityScheduler scheduler;

        int num_process;
        std::cout << "Enter number of processes: ";
        std::cin >> num_process;

        for (int i = 0; i < num_process; ++i) {
            int arrival, burst, priority;
            std::cout << "Process " << i + 1 << ":\n";
            std::cout << "Arrival time: ";
            std::cin >> arrival;
            std::cout << "Burst time: ";
            std::cin >> burst;
            std::cout << "Priority (lower is higher priority): ";
            std::cin >> priority;

            scheduler.addProcess(Process(i + 1, arrival, burst, priority));
        }

        scheduler.run();
        scheduler.printStats();
    } 
    else if (choice == 3) {
        NonPreemptivePriorityScheduler scheduler;

        int num_process;
        std::cout << "Enter number of processes: ";
        std::cin >> num_process;

        for (int i = 0; i < num_process; ++i) {
            int arrival, burst, priority;
            std::cout << "Process " << i + 1 << ":\n";
            std::cout << "Arrival time: ";
            std::cin >> arrival;
            std::cout << "Burst time: ";
            std::cin >> burst;
            std::cout << "Priority (lower is higher priority): ";
            std::cin >> priority;

            scheduler.addProcess(Process(i + 1, arrival, burst, priority));
        }

        scheduler.run();
        scheduler.printStats();
    }
    else if (choice == 4) {
        MultilevelQueueScheduler mq;

        int num_process;
        std::cout << "Enter number of processes: ";
        std::cin >> num_process;
        for (int i = 0; i < num_process; ++i) {
            int arrival, burst, queue_level;
            std::cout << "Process " << i + 1 << ":\n";
            std::cout << "Arrival time: ";
            std::cin >> arrival;
            std::cout << "Burst time: ";
            std::cin >> burst;
            std::cout << "Queue level (1 = High, 2 = Low): ";
            std::cin >> queue_level;

            // Convert Process to ProcessInfo before adding
            ProcessInfo pinfo(i + 1, arrival, burst, queue_level);
            mq.addProcess(pinfo, queue_level);
        }

        mq.run();
        mq.printStats();
    } 
    else if (choice == 5) {
        int tq1, tq2;
        std::cout << "Enter time quantum for Queue 1: ";
        std::cin >> tq1;
        std::cout << "Enter time quantum for Queue 2: ";
        std::cin >> tq2;

        // Create the MultilevelQueueScheduler object with time quantum values
        MultilevelQueueScheduler mfq(tq1, tq2);

        int num_process;
        std::cout << "Enter number of processes: ";
        std::cin >> num_process;

        for (int i = 0; i < num_process; ++i) {
            int arrival, burst;
            std::cout << "Process " << i + 1 << ":\n";
            std::cout << "Arrival time: ";
            std::cin >> arrival;
            std::cout << "Burst time: ";
            std::cin >> burst;

            // Convert Process to ProcessInfo before adding
            ProcessInfo pinfo(i + 1, arrival, burst, 0);  // Assuming priority is 0 for this case
            mfq.addProcess(pinfo, 0);
        }

        mfq.run();
        mfq.printStats();
    }
    else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
