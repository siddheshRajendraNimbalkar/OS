#include <stdio.h>

// Define struct Process
struct Process {
    int id;
    int AT;             // Arrival Time
    int BT;             // Burst Time
    int CT;             // Completion Time
    int TAT;            // Turnaround Time
    int WT;             // Waiting Time
    int isCT;           // Completion flag (1 if complete, 0 if not)
    int remaining_time; // Remaining burst time
};

// Function to calculate waiting and turnaround times for processes
void calTime(struct Process p[], int n) {
    int q = 1;                 // Quantum time slice (assumed as 1 here)
    int currentTime = 0;        // Current time
    int completed = 0;          // Number of processes completed
    int TWT = 0, TTAT = 0;      // Total Waiting Time and Total Turnaround Time

    printf("\nGantt Chart: ");
    
    while (completed < n) {
        int minBT = -1;
        int shortestJob = -1;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= currentTime && !p[i].isCT) {
                if (minBT == -1 || p[i].remaining_time < minBT) {
                    shortestJob = i;
                    minBT = p[i].remaining_time;
                }
            }
        }

        // If no process is available, increment the current time
        if (shortestJob == -1) {
            currentTime++;
            continue;
        }

        // Process the shortest job
        printf("P%d | ", p[shortestJob].id);  // Output for Gantt chart

        if (p[shortestJob].remaining_time > q) {
            p[shortestJob].remaining_time -= q;
            currentTime += q;
        } else {
            // Process completes its execution
            currentTime += p[shortestJob].remaining_time;
            p[shortestJob].CT = currentTime;
            p[shortestJob].TAT = p[shortestJob].CT - p[shortestJob].AT;
            p[shortestJob].WT = p[shortestJob].TAT - p[shortestJob].BT;
            p[shortestJob].remaining_time = 0;
            p[shortestJob].isCT = 1;
            
            TTAT += p[shortestJob].TAT;
            TWT += p[shortestJob].WT;
            
            completed++;
        }
    }

    // Display the waiting times and turnaround times
    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].AT, p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }

    printf("\nAverage Turnaround Time: %.2f", (float)TTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", (float)TWT / n);
}

int main() {
    int n;

    // Input the total number of processes
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct Process p[n];  // Array of processes

    // Input arrival and burst times for each process
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter the arrival time and burst time for process P[%d]: ", p[i].id);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].remaining_time = p[i].BT;
        p[i].isCT = 0;  // Mark the process as incomplete initially
    }

    // Calculate times and display results
    calTime(p, n);

    return 0;
}
