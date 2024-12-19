//Program using threads that prints sum of numbers up to given positive number n.
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define THREAD_COUNT 4
typedef struct
{
    int start;
    int end;
    long long sum;
}ThreadData;
void* calculate_sum(void* arg)
{
    ThreadData* data = (ThreadData*)arg;
    long long sum = 0;
    for(int i = data -> start;i<=data -> end;++i)
    {
        sum += i;
    }
    data -> sum = sum;
    return NULL;
}
int main()
{
    int n;
    printf("Enter a positive number: ");
    scanf("%d",&n);
    if(n <= 0)
    {
        printf("Number must be positive.\n");
        return 1;
    }
    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];
    int segment_size = (n + THREAD_COUNT - 1) / THREAD_COUNT;
    long long total_sum = 0;
    for(int i = 0;i<THREAD_COUNT;++i)
    {
        thread_data[i].start = i + segment_size + 1;
        thread_data[i].end = (i + 1) * segment_size;
        if(thread_data[i].end > n)
        {
            thread_data[i].end = n;
        }
        pthread_create(&threads[i], NULL, calculate_sum, &thread_data[i]);
    }
    for(int i = 0;i < THREAD_COUNT; ++i)
    {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }
    printf("Sum of numbers from 1 to %d is %lld\n", n, total_sum);
    return 0;
}