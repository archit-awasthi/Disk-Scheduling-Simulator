# Disk Scheduling Simulator

A console-based C++ project that simulates disk scheduling algorithms — FCFS, SSTF, and SCAN. Built to visualize how different algorithms handle disk I/O requests and calculate total seek time.

## 📌 Features
- Takes custom disk request queue and initial head position as input
- Simulates three algorithms:
  - FCFS (First-Come, First-Served)
  - SSTF (Shortest Seek Time First)
  - SCAN (Elevator Algorithm)
- Step-by-step simulation of head movements
- Displays total seek time
- Menu-driven and rerun support

## 🛠 Tech Stack
- Language: C++
- Platform: Console (VS Code / g++)

## ▶️ How to Run

1. Compile the code:
   ` `bash` ` 
   g++ DiskSchedulingSimulator.cpp -o DiskSchedulingSimulator
