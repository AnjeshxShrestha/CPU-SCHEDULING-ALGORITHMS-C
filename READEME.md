# 🚀 CPU Scheduling Algorithms in C

A clean and efficient implementation of **FCFS**, **SJF**, **Round Robin**, and **Priority Scheduling** using the C programming language.  
Designed for OS lab work, learning, and demonstration purposes.

---

## 📄 File
**`ProcessScheduling.c`** — contains all scheduling algorithms in a single menu-driven C program.

---

## 🔧 Features
- ⚡ Four classic CPU scheduling algorithms  
- 📊 Tabular output showing **CT**, **TAT**, and **WT**  
- 🔁 Round Robin with user-defined time quantum  
- 🧮 SJF and Priority (non-preemptive)  
- 🖥️ Beginner-friendly, well-structured code  

---

## 🧠 Algorithms Implemented

### **1️⃣ FCFS (First Come First Serve)**
- Processes are executed in order of arrival.

### **2️⃣ SJF (Shortest Job First – Non-Preemptive)**
- Chooses the process with the smallest burst time among arrived processes.

### **3️⃣ Round Robin**
- Uses a time quantum to ensure fairness in time-shared systems.

### **4️⃣ Priority Scheduling**
- Lower priority number = higher priority.

---

## ▶️ How to Run

### **Compile**
```bash
gcc ProcessScheduling.c -o scheduling

Run

./scheduling

🧭 Program Menu

Choose Scheduling Algorithm:
1. FCFS
2. SJF
3. Round Robin
4. Priority Scheduling
Enter choice:

If Round Robin is selected, the program will ask for your Time Quantum.
📊 Sample Output (FCFS)

--- FCFS Scheduling ---
PID     BT      AT      CT      TAT     WT
1       6       0       6       6       0
2       4       1       10      9       5
3       8       2       18      16      8
4       3       3       21      18      15

📝 Notes

    Processes are predefined inside main().
    You can edit the list to test other scenarios.

    The table output is aligned for readability in any terminal.

📚 Purpose

Useful for:

    Operating System lab assignments

    Understanding CPU scheduling behavior

    Demonstration and documentation

    Academic or portfolio projects

📜 License

Free to use, modify, and distribute.
