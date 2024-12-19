//Program to create a simple thread
#include<stdio.h>
#include<pthread.h>
void *threadFunction(void *args)
{
    while(1)
    {
        printf("I am Thread Function. \n");
    }
}
int main()
{
    pthread_t id;
    int ret;
    ret = pthread_create(&id, NULL, &threadFunction, NULL);
    if(ret == 0)
        printf("Thread created successfully.\n");
    else
    {
        printf("Thread is not created.\n");
        return 0;
    }
    while(1)
    {
        printf("I am Main Function.\n");
    }
    return 0;
}