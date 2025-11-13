#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    int priority; // smaller value = higher priority
    string name;
};

// Custom comparator for min-heap (priority queue)
struct Compare {
    bool operator()(const Task &a, const Task &b) {
        if (a.priority == b.priority)
            return a.id > b.id; // tie-break by task id
        return a.priority > b.priority;
    }
};

class TaskScheduler {
private:
    int n; // number of tasks
    vector<Task> tasks;
    vector<vector<int>> adj; // adjacency list for dependencies
    vector<int> indegree;    // indegree for topological sort

public:
    TaskScheduler(int n) {
        this->n = n;
        tasks.resize(n);
        adj.resize(n);
        indegree.assign(n, 0);
    }

    void addTask(int id, string name, int priority) {
        tasks[id] = {id, priority, name};
    }

    void addDependency(int u, int v) {
        // Task u must be done before v
        adj[u].push_back(v);
        indegree[v]++;
    }

    void scheduleTasks() {
        priority_queue<Task, vector<Task>, Compare> pq;

        // Push all tasks with no dependencies
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                pq.push(tasks[i]);
        }

        vector<int> result;

        while (!pq.empty()) {
            Task cur = pq.top(); pq.pop();
            result.push_back(cur.id);
            cout << "Executing Task: " << cur.name 
                 << " (Priority " << cur.priority << ")\n";

            // Reduce indegree of neighbors
            for (int neigh : adj[cur.id]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    pq.push(tasks[neigh]);
                }
            }
        }

        if ((int)result.size() != n) {
            cout << "Error: Cyclic dependency detected! Scheduling not possible.\n";
        }
    }
};

int main() {
    // Example: 6 tasks
    TaskScheduler scheduler(6);

    // Add tasks (id, name, priority)
    scheduler.addTask(0, "Design", 2);
    scheduler.addTask(1, "Frontend", 3);
    scheduler.addTask(2, "Backend", 1);
    scheduler.addTask(3, "Database", 2);
    scheduler.addTask(4, "Testing", 1);
    scheduler.addTask(5, "Deployment", 2);

    // Add dependencies
    scheduler.addDependency(0, 1); // Design -> Frontend
    scheduler.addDependency(0, 2); // Design -> Backend
    scheduler.addDependency(2, 3); // Backend -> Database
    scheduler.addDependency(1, 4); // Frontend -> Testing
    scheduler.addDependency(3, 4); // Database -> Testing
    scheduler.addDependency(4, 5); // Testing -> Deployment

    cout << "\n--- Task Scheduling Order ---\n";
    scheduler.scheduleTasks();

    return 0;
}
