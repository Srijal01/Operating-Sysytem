//Program to simulate Shortest First Job (SFJ) algorithm.
#include<stdio.h>
#define MAX_PROCESS 100
void findWaitingTime(int processes[], int n, int arrival[], int bt[], int wt[])
{
    int remaining_time[MAX_PROCESS];
    int completion_time[MAX_PROCESS];
    int completed = 0, current_time = 0;
    for(int i=0;i<n;i++)
    {
        remaining_time[i] = bt[i];
        wt[i] = 0;
        completion_time[i] = 0;
    }
    while(completed<n)
    {
        int min_index = -1;
        int min_burst = 10000;
        for(int i=0;i<n;i++)
        {
            if(arrival[i]<=current_time && remaining_time[i]<min_burst && remaining_time[i]>0)
            {
                min_burst = remaining_time[i];
                min_index = i;
            }
        }
        if(min_index != -1)
        {
            remaining_time[min_index]--;
            current_time++;
            if(remaining_time[min_index]==0)
            {
                completed++;
                completion_time[min_index] = current_time;
                wt[min_index] = completion_time[min_index] - arrival[min_index] - bt[min_index];
            }
        }
        else
        {
            current_time++;
        }
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for(int i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void findavgTime(int processes[], int n, int arrival[], int bt[])
{
    int wt[MAX_PROCESS], tat[MAX_PROCESS];
    findWaitingTime(processes, n, arrival, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    int total_wt = 0, total_tat = 0;
    for(int i=0;i<n;i++)
    {
        int completion_time = tat[i] + arrival[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i],arrival[i], bt[i], wt[i], tat[i], completion_time);
        total_wt += wt[i];
        total_tat += tat[i]; 
    }
    printf("\nAverage waiting time = %.2f", (float)total_wt/n);
    printf("\nAverage turnaround time = %.2f", (float)total_tat/n);
}
int main()
{
    int n;
    int processes[MAX_PROCESS], burst_time[MAX_PROCESS], arrival_time[MAX_PROCESS];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival timr and burst time for each process: \n");
    for(int i=0;i<n;i++)
    {
        processes[i] = i + 1;
        printf("Process %d Arrival Time: ", processes[i]);
        scanf("%d", &arrival_time[i]);
        printf("Process %d Burst Time: ", processes[i]);
        scanf("%d",&burst_time[i]);
    }
    findavgTime(processes, n, arrival_time, burst_time);
    return 0;
}