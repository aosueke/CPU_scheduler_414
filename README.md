# CPU_scheduler_414
#### **Advanced CPU Scheduler**
The **Advanced CPU Scheduler** simulates multiple CPU scheduling algorithms: Round Robin, Priority Scheduling (preemptive & non-preemptive), Multilevel Queue, and Multilevel Feedback Queue. It provides detailed performance metrics for testing and analysis.

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
   git clone https://github.com/aosueke/CPU_scheduler_414.git
   cd CPU_scheduler_414
   ```

2. Compile the program using the makefile:
   ```bash
   make
   ```

3. Run program:
   ```bash
   ./scheduler
   ```
4. Clean up the project:
   ```bash
   make clean
   ```

---

#### **Usage Examples**

1. **Run Round Robin Scheduling:**
   - Input the number of processes, their arrival times, burst times, and the time quantum.

2. **Run Priority Scheduling:**
   - Select either preemptive or non-preemptive mode, then input process attributes (priority, arrival time, burst time).

3. **Run Multilevel Queue Scheduling:**
   - Assign processes to specific queues based on priority and execute them.

4. **Run Multilevel Feedback Queue Scheduling:**
   - Configure time quantum values for each queue and add processes dynamically.

---

#### **Design Decisions**

1. **Modular Design:**
   - Each scheduling algorithm is implemented in a separate class for scalability and maintainability.
2. **Dynamic Process Handling:**
   - Processes are stored in vectors or queues, allowing dynamic addition.
3. **Standard Libraries:**
   - Used `std::vector`, `std::queue`, and modern C++17 features for efficient data handling.

---

#### **Known Limitations**

1. **Multilevel Queue Priority:**
   - Assumes fixed priorities for queues; no dynamic priority adjustments.
2. **No Preemption in Multilevel Queue:**
   - Once a process starts in a lower-priority queue, higher-priority queues are not checked for newly arrived processes.
3. **Visualization:**
   - Execution visualization is text-based; GUI support is not included.
4. **Error Handling:**
   - Limited error checks for incorrect user inputs (e.g., invalid priority or negative burst times).

---

#### **Future Enhancements**
- Add support for real-time scheduling algorithms (e.g., EDF).
- Improve the user interface for better usability.
- Incorporate logging for analysis over large datasets.

---

#### **References**
- GeeksForGeeks
  https://www.geeksforgeeks.org/multilevel-feedback-queue-scheduling-mlfq-cpu-scheduling/
- Medium page about Multilevel Feedback Queue
  https://medium.com/@francescofranco_39234/multilevel-feedback-queue-3ae862436a95


---
