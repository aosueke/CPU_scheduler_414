# CPU_scheduler_414
#### **Advanced CPU Scheduler**
The **Advanced CPU Scheduler** simulates multiple CPU scheduling algorithms: Round Robin, Priority Scheduling (preemptive/non-preemptive), Multilevel Queue, and Multilevel Feedback Queue. It provides detailed performance metrics for testing and analysis.

---
**Features**
1. Scheduling Algorithms:
   - Round Robin (configurable time quantum)
   - Priority Scheduling (preemptive and non-preemptive)
   - Multilevel Queue Scheduling
   - Multilevel Feedback Queue Scheduling
2. Calculated Metrics:
   - Waiting Time
   - Turnaround Time
   - Response Time
3. Dynamic Process Handling:
   - Processes with configurable priorities, burst times, and arrival times (including process state and transitions).
4. Real-Time Insights:
   - Visual representation of process creation and execution order of ready queue, as well as CPU usage.
5. Handling Context-switching overhead
---

#### **Build Instructions**

1. Clone the repository:
   ```bash
   git clone [<repository-url>](https://github.com/aosueke/CPU_scheduler_414.git)
   cd CPU_scheduler_414
   ```

2. Compile the program using the makefile:
   ```bash
   make
   ```

3. Run program:
   ```bash
   ./CPUscheduler
   ```

4. Clean the project:
   ```bash
   make clean
   ```

---
