//Program to print process ID
#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid, ppid;
    pid = getpid();
    ppid = getppid();
    printf("The process ID is %d \n",pid);
    printf("The parent process ID is %d \n",ppid);
    return 0;
}