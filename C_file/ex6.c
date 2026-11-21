#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], pr[10], endTime, i, smallest;
    int remain = 0, time, sum_wait = 0, sum_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    pr[9] = 9999; // Sentinel lowest priority
    printf("\nProcess\tTurnaround Time\tWaiting Time\n");
    for (time = 0; remain != n; time++) {
        smallest = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && pr[i] < pr[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain++;
            endTime = time + 1;
            printf("P%d\t%d\t\t%d\n", smallest + 1, endTime - at[smallest], endTime - bt[smallest] - at[smallest]);
            sum_wait += endTime - bt[smallest] - at[smallest];
            sum_turnaround += endTime - at[smallest];
        }
    }

    printf("\nAverage Waiting Time = %.2f", (float)sum_wait / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)sum_turnaround / n);
    return 0;
}