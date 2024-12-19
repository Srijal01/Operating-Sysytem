//Program to create process using fork and print process ID
#include<stdio.h>
#include<unistd.h>
int main()
{
    int pid;
    printf("The main program process ID is %d \n\n\n",(int)getpid());
    pid = fork();
    if(pid != 0)
    {
        printf("This is the parent process with ID %d \n",(int)getpid());
        printf("The child process ID is %d \n\n\n",(int)getpid());
    }
    else
    {
        printf("This is the child process with ID %d \n\n\n",(int)getpid());
    }
    return 0;
}