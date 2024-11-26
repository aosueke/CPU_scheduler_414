#ifndef MULTILEVEL_QUEUE_H
#define MULTILEVEL_QUEUE_H

#include "processInfo.h"
#include <vector>

class MultilevelQueueScheduler {
private:
  std::vector<Process> queue1;
  std::vector<Process> queue2;

public:
  void addProcess(const Process& process, int queue_level);
  void run();
  void printStats90:
};

#endif
