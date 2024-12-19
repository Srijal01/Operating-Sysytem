//Program to execute the program and issue the command ps –el three times in every 10 second and analyze their output
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    const int EXECUTIONS = 3;
    const int INTERVAL = 10;
    for(int i = 0; i<EXECUTIONS;++i)
    {
        printf("Execution %d:\n",i+1);
        int ret = system("ps -el");
        if(ret == -1)
        {
            perror("system");
            return 1;
        }
        sleep(INTERVAL);
    }
    return 0;
}