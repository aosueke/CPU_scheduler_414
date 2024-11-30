#include <iostream>
#include "round_robin.h"
#include "priority_scheduler.h"
#include "multilevel_queue.h"
#include "MLFQ.h"

int main() {
    int choice;
    std::cout << "Advanced CPU Scheduler\n";
    std::cout << "1. Round Robin\n";
    std::cout << "2. Priority Scheduling\n";
    std::cout << "3. Multilevel Queue\n";
    std::cout << "4. Multilevel Feedback Queue\n";
    std::cout << "Choose a scheduling algorithm: ";
    std::cin >> choice;
   if (choice == 3) {
        MultilevelQueueScheduler mq;

        int num_process;
        std::cout << "Enter number of processes: ";
        std::cin >> num_process;
