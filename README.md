# 🧩 Dynamic Task Scheduler in C++

A robust and efficient C++ implementation of a **Dynamic Task Scheduler** that intelligently determines the optimal execution order of interdependent tasks.

It leverages **Topological Sorting (Kahn’s Algorithm)** to resolve dependencies and a **Min-Heap (priority queue)** to always execute the **highest-priority task first**.

---

## ✨ Key Features

- **Dependency Resolution:**  
  - Automatically manages and resolves task dependencies using **Topological Sort**.  
  - Ensures all tasks execute in a valid order without violating constraints.

- **Priority-Based Execution:**  
  - Uses a **Min-Heap** to dynamically pick the task with the **highest priority** (lowest numeric value).  
  - Makes scheduling responsive and optimal.

- **Cycle Detection:**  
  - Detects and reports **cyclic dependencies**.  
  - Prevents execution when tasks cannot be scheduled properly.

- **Dynamic Task Management:**  
  - Supports easy addition of new tasks and dependencies.  
  - Suitable for systems where workflows evolve over time.

- **High Efficiency:**  
  - Overall complexity: **O((V + E) log V)**  
  - Scales smoothly for large task graphs.

---

## ⚙️ Core Algorithms & Data Structures

- **Topological Sort (Kahn’s Algorithm)**  
  - Ensures dependency-safe execution order.

- **Priority Queue (Min-Heap)**  
  - Selects available tasks by priority.

- **Adjacency List**  
  - Efficient graph representation for task links.

---

## 💡 Use Cases

- **Build Systems**  
  - Managing compilation and linking tasks with dependencies.

- **Workflow Automation Engines**  
  - Coordinating multi-step task pipelines.

- **Project Planning Tools**  
  - Organizing tasks and deadlines with dependencies.

- **OS or Compiler Task Scheduling**  
  - Intelligent ordering and resource management.

