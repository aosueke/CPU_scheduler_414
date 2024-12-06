#ifndef MULTILEVEL_QUEUE_H
#define MULTILEVEL_QUEUE_H

#include "processInfo.h"
#include <vector>

class MultilevelQueueScheduler {
private:
  std::vector<ProcessInfo> queue1;
  std::vector<ProcessInfo> queue2;

public:
  void addProcess(const ProcessInfo& process, int queue_level);
  void run();
  void printStats90:
};

#endif
