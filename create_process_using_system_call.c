//Program to create a process using system call
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int r_value;
    r_value = system("ls -l");
    return r_value;
}