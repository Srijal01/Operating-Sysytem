//Program to simulate Round Robin (RR) algorithm.
#include<stdio.h>
#define MAX_PROCESS 100
void findWaitingTime(int processes[], int n, int bt[], int quantum, int wt[])
{
    int remaining_time[MAX_PROCESS];
    int current_time = 0;
    for(int i=0;i<n;i++)
    {
        remaining_time[i] = bt[i];
        wt[i] = 0;
    }
    while(1)
    {
        int done = 1;
        for(int i=0;i<n;i++)
        {
            if(remaining_time[i]>0)
            {
                done = 0;
                if(remaining_time[i]>quantum)
                {
                    remaining_time[i] -= quantum;
                    current_time += quantum;
                }
                else
                {
                    current_time += remaining_time[i];
                    wt[i] = current_time - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if(done == 1)
        {
            break;
        }
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for(int i=1;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void findavgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[MAX_PROCESS], tat[MAX_PROCESS];
    findWaitingTime(processes, n, bt, quantum, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    int total_wt = 0, total_tat = 0;
    for(int i=0;i<n;i++)
    {
        int completion_time = tat[i] + wt[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",processes[i], bt[i], wt[i], tat[i], completion_time);
        total_wt += wt[i];
        total_tat += tat[i]; 
    }
    printf("\nAverage waiting time = %.2f", (float)total_wt/n);
    printf("\nAverage turnaround time = %.2f", (float)total_tat/n);
}
int main()
{
    int n;
    int processes[MAX_PROCESS], burst_time[MAX_PROCESS];
    int quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter thwe burst time for each process: \n");
    for(int i=0;i<n;i++)
    {
        processes[i] = i + 1;
        printf("Process %d: ", processes[i]);
        scanf("%d",&burst_time[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d",&quantum);
    findavgTime(processes, n, burst_time, quantum);
    return 0;
}