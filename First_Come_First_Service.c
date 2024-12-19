//Program to simulate First Come First Service (FCFS) algorithm
#include<stdio.h>
#define MAX_PROCESS 100
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for(int i=1;i<n;i++)
    {
        wt[i] = 0;
        for(int j=0;j<i;j++)
        {
            wt[i] += bt[j];
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
void findavgTime(int processes[], int n, int bt[])
{
    int wt[MAX_PROCESS], tat[MAX_PROCESS];
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    int total_wt = 0, total_tat = 0;
    for(int i=0;i<n;i++)
    {
        int completion_time = tat[i] + 0;
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
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time for each process: \n");
    for(int i=0;i<n;i++)
    {
        processes[i] = i + 1;
        printf("Process %d: ", processes[i]);
        scanf("%d",&burst_time[i]);
    }
    findavgTime(processes, n, burst_time);
    return 0;
}