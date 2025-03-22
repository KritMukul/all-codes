#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Structure to represent a process
class Process {
    public:
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime; // For preemption
    int waitingTime = 0;
    int turnaroundTime = 0;
};

// Function to calculate and display results
void displayResults(const vector<Process>& processes, const vector<int>& executionSequence) {
    float totalWaitingTime = 0;

    cout << "Execution Sequence: ";
    for (size_t i = 0; i < executionSequence.size(); i++) {
        if (i == 0 || executionSequence[i] != executionSequence[i - 1]) {
            cout << "P" << executionSequence[i] << " ";
        }
    }
    cout << endl;

    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
        cout << "P" << process.id << " - Waiting Time: " << process.waitingTime << endl;
    }

    cout << "Average Waiting Time: " << fixed << setprecision(2) 
         << totalWaitingTime / processes.size() << endl;
}

// Shortest Job First (Non-Preemptive)
void sjfNonPreemptive(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    vector<int> executionSequence;
    vector<Process> completed;
    int currentTime = 0;

    while (completed.size() < processes.size()) {
        vector<Process*> readyQueue;

        for (auto& process : processes) {
            if (process.remainingTime > 0 && process.arrivalTime <= currentTime) {
                readyQueue.push_back(&process);
            }
        }

        if (!readyQueue.empty()) {
            Process* shortestJob = *min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->burstTime < b->burstTime;
            });

            if (currentTime < shortestJob->arrivalTime)
                currentTime = shortestJob->arrivalTime;

            executionSequence.push_back(shortestJob->id);
            shortestJob->waitingTime = currentTime - shortestJob->arrivalTime;
            currentTime += shortestJob->burstTime;
            shortestJob->remainingTime = 0;
            completed.push_back(*shortestJob);
        } else {
            currentTime++;
        }
    }

    displayResults(processes, executionSequence);
}

// Shortest Job First (Preemptive)
void sjfPreemptive(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    vector<int> executionSequence;
    int currentTime = 0, completedCount = 0;

    while (completedCount < processes.size()) {
        vector<Process*> readyQueue;

        for (auto& process : processes) {
            if (process.remainingTime > 0 && process.arrivalTime <= currentTime) {
                readyQueue.push_back(&process);
            }
        }

        if (!readyQueue.empty()) {
            Process* shortestJob = *min_element(readyQueue.begin(), readyQueue.end(), [](Process* a, Process* b) {
                return a->remainingTime < b->remainingTime;
            });

            executionSequence.push_back(shortestJob->id);
            shortestJob->remainingTime--;
            currentTime++;

            if (shortestJob->remainingTime == 0) {
                shortestJob->waitingTime = currentTime - shortestJob->arrivalTime - shortestJob->burstTime;
                completedCount++;
            }
        } else {
            currentTime++;
        }
    }

    displayResults(processes, executionSequence);
}

// Main function
int main() {
    int n, choice;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time and burst time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    cout << "\nSelect Scheduling Algorithm:\n";
    cout << "1. SJF (Non-Preemptive)\n";
    cout << "2. SJF (Preemptive)\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        sjfNonPreemptive(processes);
        break;
    case 2:
        sjfPreemptive(processes);
        break;
    default:
        cout << "Invalid choice!";
        break;
    }

    return 0;
}
