//Program to simulate Priority Scheduling algorithm.
#include<stdio.h>
#define MAX_PROCESSES 10
typedef struct
{
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
}Process;
void swap(Process *a, Process *b)
{
    Process temp = *a;
    *a = *b;
    *b = temp;
}
void priorityScheduling(Process processes[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(processes[j].priority < processes[j+1].priority)
            {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    for(int i=1;i<n;i++)
    {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}
void printProcessTable(Process processes[], int n)
{
    printf("Process ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].id,processes[i].burstTime,processes[i].priority,processes[i].waitingTime,processes[i].turnaroundTime);
    }
}
int main()
{
    Process processes[MAX_PROCESSES];
    int n;
    printf("Enter the number of processes (max %d): ",MAX_PROCESSES);
    scanf("%d",&n);
    if(n>MAX_PROCESSES)
    {
        printf("Number of processes exceeds the maximum allowed (%d).\n",MAX_PROCESSES);
        return 1;
    }
    for(int i=0;i<n;i++)
    {
        processes[i].id = i + 1;
        printf("Enter burst time and priority for process %d: ",i+1);
        scanf("%d %d",&processes[i].burstTime,processes[i].priority);
    }
    priorityScheduling(processes, n);
    printProcessTable(processes, n);
    return 0;
}