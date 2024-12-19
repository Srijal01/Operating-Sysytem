//Program to create a process using one fork
#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("This is to demonstrate the fork. \n");
    fork();
    printf("Hi! Everybody. \n");
}