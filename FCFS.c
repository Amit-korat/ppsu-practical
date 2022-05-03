// 1. Implement FCFS algorithm (input process count, arrival time and burst time)
// Compute: average completion time, average response time, average turnaround time,
// average waiting time, CPU utilization and throughput.


#include <stdio.h>
int main()
{
    int AT[10], BT[10], WT[10], TT[10], n, i;
    int burst = 0, cmpl_T;
    float Avg_WT, Avg_TT, Total = 0;
    printf("Enter number of the process\n");
    scanf("%d", &n);
    printf("Enter Arrival time and Burst time of the process\n");
    printf("AT\tBT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &AT[i], &BT[i]);
    }
    WT[i] = AT[i];
    for (int i = 0; i < n; i++)
    {
        WT[i] = burst - AT[i];
        burst += BT[i];
        Total += WT[i];
        if (WT[i] < 0)
        {
        WT[i] = 0;
        }
    }
    Avg_WT = Total / n;
    cmpl_T = 0;
    Total = 0;
    for (int i = 0; i < n; i++)
    {
        cmpl_T += BT[i];
        TT[i] = cmpl_T - AT[i];
        Total += TT[i];
    }
    Avg_TT = Total / n;
    printf("Process ,Waiting_time ,TurnA_time\n");
    for (int i = 0; i < n; i++)
    {
    printf("%d\t\t%d\t\t%d\n", i + 1, WT[i], TT[i]);
    }
    printf("Average waiting time is : %f\n", Avg_WT);
    printf("Average turn around time is : %f\n", Avg_TT);
    printf("Throughput is : %f\n", (n / cmpl_T));
    return 0;
}
