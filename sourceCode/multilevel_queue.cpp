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
      if (!process.is_completed) {
        //Simulate Execution
        process.respo_time = current_time - process.arr_time;
        current_time += process.burst_time;
        process.turnarnd_time = current_time - process.arr_time;
        process.wait_time = process.turnarnd_time - process.burst_time;
        process.is_completed = true;
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
  std::cout << "Queue 1 size: " << queue1.size() << "\n";
  std::cout << "Queue 2 size: " << queue2.size() << "\n";
  
  auto printQueueStats = [](const std::vector<ProcessInfo>& queue) {
    double avg_waiting_time = 0, avg_turnaround_time = 0;

    for (const auto& process : queue) {
      avg_waiting_time += process.wait_time;
      avg_turnaround_time += process.turnarnd_time;

      std::cout << process.id << "\t" << process.arr_time << "\t"
        << process.burst_time << "\t" << process.wait_time << "\t"
        << process.turnarnd_time << "\t\t" << process.respo_time << "\n";
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
