#ifndef PROCESS_INFO_H
#define PROCESS_INFO_H

#include <iostream>

struct ProcessInfo {
    int id;
    int arr_time; // arrival time
    int burst_time;
    int priority; // For priority scheduling
    int remain_time; //remaining time
    int wait_time; // waiting time
    int turnarnd_time; //turnaround time
    int respo_time; //response time
    bool is_completed;

    ProcessInfo(int id, int arrival, int burst, int priority = 0)
        : id(id), arr_time(arrival), burst_time(burst), priority(priority),
          remain_time(burst), wait_time(0), turnarnd_time(0),
          respo_time(-1), is_completed(false) {}
};

#endif
