#include "multilevel_queue.h"
#include <iostream>
#include <algorithm>

void MultilevelQueueScheduler::addProcess(const ProcessInfo& process, int queue_level) {
  if (queue_level == 1) {
    queue1.push_back(process);
  } else if (queue_level == 2) {
  queue2.push_back(process);
  }
}

void MultilevelQueueScheduler::run() {
  auto executeQueue = [](std::vector<ProcessInfo>& queue, int& current_time) {
    for (auto& process : queue) {
      if (!process.completed) {
        //Simulate Execution
        process.response_time = current_time - process.arrival_time;
        current_time += process.burst_time;
        process.turnaround_time = curent_time - process.arrival_time;
        process.waiting_time = process.turnaround_time - process.burst_time;
        process.completed = true;
      }
    }
  };

  int current_time = 0;

  //Execute queue 1 first (higher priority)
  executeQueue(queue1, current_time);

  //Then execute queue 2 (lower priority)
  executeQueue(queue2, current_time);
}

void MultilevelQueueScheduler::printStats() {
  auto printQueueStats = [](const std::vector<ProcessInfo>& queue) {
    double avg_waiting_time = 0, avg_turnaround_time = 0;

    for (const auto& process : queue) {
      avg_waiting_time += process.waiting_time;
      avg_turnaround_time += process.turnaround_time;

      std::cout << process.id << "\t" << process.arrival_time << "\t"
        << process.burst_time << "\t" << process.waiting_time << "\t"
        << process.turnaround_time << "\t\t" << process.response_time << "\n";
    }

    std::cout << "\nAverage Waiting Time: " << avg_waiting_time / queue.size() << "\n";
    std::cout << "Average Turnaround Time: " << avg_turnaround_time / queue.size() << "\n";
  };

  std::cout << "\nMultilevel Queue Scheduling Results (Queue 1 - High Priority):\n";
  std::cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n";
  printQueueStats(queue1);

  std::cout << "\nMultilevel Queue Scheduling Results (Queue 2 - Low Priority):\n";
  std::cout << "ID\tArrival\tBurst\tWaiting\tTurnaround\tResponse\n";
  printQueueStats(queue2);
}
