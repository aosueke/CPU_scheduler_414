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
### **Use Cases**

1. **Case 1: Testing Round Robin Scheduling**
   - A user wants to simulate a Round Robin Scheduler with 5 processes, each with different burst times and arrival times.
   - **Input:**
     - Time quantum: 4
     - Processes: `P1 (arrival=0, burst=10)`, `P2 (arrival=1, burst=5)`, `P3 (arrival=2, burst=8)`, `P4 (arrival=3, burst=6)`, `P5 (arrival=4, burst=7)`
   - **Expected Outcome:**
     - The processes are scheduled in a cyclic order with a time slice of 4 units.
     - The program calculates average waiting, turnaround, and response times.

2. **Case 2: Testing Priority Scheduling**
   - A user wants to test priority-based scheduling (non-preemptive) with 4 processes.
   - **Input:**
     - Processes: `P1 (priority=2, arrival=0, burst=10)`, `P2 (priority=1, arrival=2, burst=6)`, `P3 (priority=3, arrival=4, burst=8)`, `P4 (priority=1, arrival=6, burst=5)`
   - **Expected Outcome:**
     - Processes are executed based on priority, and processes with the same priority are executed in the order of arrival time.

3. **Case 3: Testing Multilevel Queue**
   - A user assigns 6 processes to two separate queues (Queue 1: high priority, Queue 2: low priority).
   - **Input:**
     - Processes: `P1, P2, P3` in Queue 1, `P4, P5, P6` in Queue 2.
     - Queue scheduling: Queue 1 executes before Queue 2.
   - **Expected Outcome:**
     - All processes in Queue 1 execute before Queue 2 begins.

4. **Case 4: Testing Multilevel Feedback Queue**
   - A user simulates 3 processes with a feedback mechanism for priority adjustment based on time quantum.
   - **Input:**
     - Time Quantum for Queue 1: 5, Queue 2: 10
     - Processes: `P1 (arrival=0, burst=15)`, `P2 (arrival=2, burst=10)`, `P3 (arrival=4, burst=20)`
   - **Expected Outcome:**
     - Processes move between queues based on burst time and time quantum.
     - Average waiting and turnaround times are calculated.

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
