# include <stdio.h> 
#include<string.h>
typedef struct Process
{
    char name[20];
    int burst_time;int waitingTime;int startingTime;
}Process;
void inputDetails(Process *p,int n);
void display(Process *p,int size);
void calculateWaitingTime(Process *p1,int size);
int main() {
    int number_of_processes;
    printf("enter the number of process:\n");
    scanf("%d",&number_of_processes);
    Process array[number_of_processes]; Process *ptr=array;
    inputDetails(ptr,number_of_processes);
    calculateWaitingTime(ptr,number_of_processes);
    display(ptr,number_of_processes);
    return 0 ;
}
void inputDetails(Process *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("enter the details of %d process:\n",(i+1));
        printf("enter the process id: ");
        scanf("%s",(p+i)->name);
        printf("enter the burst time : ");
        scanf("%d",&(p+i)->burst_time);
        printf("       ********     \n");
    }
}
void display(Process *p,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("the details of %d process are :\n",(i+1));
        printf("       ********     \n");
        printf("process id : %s\n",(p+i)->name);
        printf("burst time : %d\n",(p+i)->burst_time);
        printf("starting time : %d\n",(p+i)->startingTime);
        printf("it's waiting time is :%d\n",(p+i)->waitingTime);
    }
}
void calculateWaitingTime(Process *p1,int size)
{
    float average_waiting=0.0;
    p1->waitingTime=0;p1->startingTime=0;
    for(int i=1;i<size;i++)
    {
        (p1+i)->startingTime= (p1+i-1)->startingTime +(p1+i-1)->burst_time;
        (p1+i)->waitingTime=(p1+i)->startingTime;
        average_waiting+=(p1+i)->waitingTime;
    }
    printf("....THE AVERAGE WAITING TIME IS : %.2f\n",average_waiting/(float)size);
}
