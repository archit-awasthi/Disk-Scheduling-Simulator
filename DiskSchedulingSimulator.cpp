#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

void displaySimulation(const vector<int>& sequence, int headStart) {
    int totalSeek = 0;
    int current = headStart;

    cout << "\nSeek Sequence Simulation:\n";
    for (int i = 0; i < sequence.size(); ++i) {
        int seek = abs(sequence[i] - current);
        cout << "=> Moving from " << current << " to " << sequence[i]
             << " [Seek: " << seek << "]\n";
        totalSeek += seek;
        current = sequence[i];
    }
    cout << "Total Seek Time: " << totalSeek << "\n";
}

void fcfs(vector<int> requests, int head) {
    cout << "\n--- FCFS (First-Come, First-Served) Scheduling ---\n";
    displaySimulation(requests, head);
}

void sstf(vector<int> requests, int head) {
    cout << "\n--- SSTF (Shortest Seek Time First) Scheduling ---\n";
    vector<bool> visited(requests.size(), false);
    vector<int> sequence;
    int current = head;

    for (int i = 0; i < requests.size(); ++i) {
        int minDist = INT_MAX, minIndex = -1;
        for (int j = 0; j < requests.size(); ++j) {
            if (!visited[j]) {
                int dist = abs(current - requests[j]);
                if (dist < minDist) {
                    minDist = dist;
                    minIndex = j;
                }
            }
        }
        visited[minIndex] = true;
        sequence.push_back(requests[minIndex]);
        current = requests[minIndex];
    }

    displaySimulation(sequence, head);
}

void scan(vector<int> requests, int head, int diskSize) {
    cout << "\n--- SCAN (Elevator) Scheduling ---\n";
    vector<int> left, right, sequence;
    requests.push_back(head);
    sort(requests.begin(), requests.end());

    int pos = find(requests.begin(), requests.end(), head) - requests.begin();

    // Move towards 0 first (can reverse if desired)
    for (int i = pos - 1; i >= 0; --i) sequence.push_back(requests[i]);
    for (int i = pos + 1; i < requests.size(); ++i) sequence.push_back(requests[i]);

    displaySimulation(sequence, head);
}

int main() {
    int n, head, choice, diskSize = 200;
    char again;

    cout << "==== Disk Scheduling Simulator ====\n";

    do {
        cout << "\nEnter number of disk requests: ";
        cin >> n;

        vector<int> requests(n);
        cout << "Enter the disk request queue (space-separated): ";
        for (int i = 0; i < n; ++i) cin >> requests[i];

        cout << "Enter the initial head position: ";
        cin >> head;

        cout << "\nChoose the scheduling algorithm:\n";
        cout << "1. FCFS (First-Come, First-Served)\n";
        cout << "2. SSTF (Shortest Seek Time First)\n";
        cout << "3. SCAN (Elevator Algorithm)\n";
        cout << "Enter choice (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1: fcfs(requests, head); break;
            case 2: sstf(requests, head); break;
            case 3: scan(requests, head, diskSize); break;
            default: cout << "Invalid choice!\n";
        }

        cout << "\nDo you want to try another algorithm? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the Disk Scheduling Simulator!\n";
    return 0;
}
