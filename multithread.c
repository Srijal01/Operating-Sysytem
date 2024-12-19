//Program that have two threads, one reads a word from keywords and another checks for valid word (you can use your own word list, at least 10, to check validity).
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
char s[10];
void *check(void *parameter)
{
    int i;
    char *strings[]={"NEPAL","CANADA","USA","UK","FRANCE","BHUTAN","CHINA","JAPAN","ITALY","BRAZIL"};
    char *ch=(char *)parameter;
    for(i=0;i<10;i++)
    if(strcmp(strings[i],s)==0)
    {
        printf("Valid Country\n");
        return NULL;
    }
    printf("Not Valid Country\n");
    return NULL;
}
void *string(void *parameter)
{
    printf("Enter country name (all caps): ");
    scanf("%s",s);
    return NULL;
}
int main()
{
    pthread_t sthread_id;
    pthread_t cthread_id;
    pthread_create(&sthread_id, NULL, &string, NULL);
    pthread_join(sthread_id, NULL);
    pthread_create(&cthread_id, NULL, &check, NULL);
    pthread_join(cthread_id, NULL);
    return 0;
}