#include <stdio.h>

struct Process {
    int pid, bt, at, priority;
};

/* ======================= FCFS ======================= */
void fcfs(struct Process p[], int n) {
    int ct = 0;

    printf("\n--- FCFS Scheduling ---\n");
    printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "PID", "BT", "AT", "CT", "TAT", "WT");

    for (int i = 0; i < n; i++) {
        if (ct < p[i].at)
            ct = p[i].at;

        ct += p[i].bt;
        int tat = ct - p[i].at;
        int wt  = tat - p[i].bt;

        printf("%-8d%-8d%-8d%-8d%-8d%-8d\n",
               p[i].pid, p[i].bt, p[i].at, ct, tat, wt);
    }
}

/* ======================= SJF ======================= */
void sjf(struct Process p[], int n) {
    int done[20] = {0}, time = 0, completed = 0;

    printf("\n--- SJF Scheduling ---\n");
    printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "PID", "BT", "AT", "CT", "TAT", "WT");

    while (completed < n) {
        int idx = -1, min_bt = 99999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].bt < min_bt) {
                min_bt = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].bt;

        int tat = time - p[idx].at;
        int wt  = tat - p[idx].bt;

        printf("%-8d%-8d%-8d%-8d%-8d%-8d\n",
               p[idx].pid, p[idx].bt, p[idx].at, time, tat, wt);

        done[idx] = 1;
        completed++;
    }
}

/* ======================= ROUND ROBIN ======================= */
void rr(struct Process p[], int n, int q) {
    int rem_bt[20], ct[20], time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        rem_bt[i] = p[i].bt;

    printf("\n--- Round Robin (Q = %d) ---\n", q);
    printf("%-8s%-8s%-8s%-8s%-8s%-8s\n", "PID", "BT", "AT", "CT", "TAT", "WT");

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && p[i].at <= time) {

                if (rem_bt[i] > q) {
                    time += q;
                    rem_bt[i] -= q;
                } else {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    completed++;
                }

            } else if (p[i].at > time) {
                time++;
                i--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int tat = ct[i] - p[i].at;
        int wt  = tat - p[i].bt;

        printf("%-8d%-8d%-8d%-8d%-8d%-8d\n",
               p[i].pid, p[i].bt, p[i].at, ct[i], tat, wt);
    }
}

/* ======================= PRIORITY SCHEDULING ======================= */
void priority_sch(struct Process p[], int n) {
    int done[20] = {0}, time = 0, completed = 0;

    printf("\n--- Priority Scheduling (Lower Number = Higher Priority) ---\n");
    printf("%-8s%-12s%-8s%-8s%-8s%-8s%-8s\n",
           "PID", "Priority", "BT", "AT", "CT", "TAT", "WT");

    while (completed < n) {
        int idx = -1, best = 9999;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].at <= time && p[i].priority < best) {
                best = p[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        time += p[idx].bt;

        int tat = time - p[idx].at;
        int wt  = tat - p[idx].bt;

        printf("%-8d%-12d%-8d%-8d%-8d%-8d%-8d\n",
               p[idx].pid, p[idx].priority, p[idx].bt,
               p[idx].at, time, tat, wt);

        done[idx] = 1;
        completed++;
    }
}

/* ======================= MAIN ======================= */
int main() {
    int n = 4;

    struct Process p[20] = {
        {1, 6, 0, 2},
        {2, 4, 1, 1},
        {3, 8, 2, 3},
        {4, 3, 3, 2}
    };

    int choice;

    printf("Choose Scheduling Algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");
    printf("4. Priority Scheduling\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        fcfs(p, n);
    } else if (choice == 2) {
        sjf(p, n);
    } else if (choice == 3) {
        int q;
        printf("Enter Time Quantum: ");
        scanf("%d", &q);
        rr(p, n, q);
    } else if (choice == 4) {
        priority_sch(p, n);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
