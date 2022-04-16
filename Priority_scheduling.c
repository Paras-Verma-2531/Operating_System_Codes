# include <stdio.h> 
# include <string.h> 
typedef struct process
{
    char name[20];
    int burst_time;int priority,startingTime,arrival_time,waitingTime,turnAround;
}Process;
void inputDetails(Process *p,int n);
void sort(Process *p,int size);
void calculateWaitingTime(Process *p1,int size);
int main() {
    int number_of_processes;
    printf("enter the number of processes: ");
    scanf("%d",&number_of_processes);
    Process array[number_of_processes];
    Process *p=array;
    inputDetails(p,number_of_processes);
    sort(p,number_of_processes);
    calculateWaitingTime(p,number_of_processes);
   return 0 ;
}
void inputDetails(Process *p,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("enter the details of %d process: \n",(i+1));
        printf("enter the process id: ");
        scanf("%s",(p+i)->name);
        printf("enter the burst time : ");
        scanf("%d",&(p+i)->burst_time);
        printf("enter the arrival time: ");
        scanf("%d",&(p+i)->arrival_time);
        printf("enter the priority : ");
        scanf("%d",&(p+i)->priority);
        printf("       ********     \n");
    }
}
void sort(Process *p,int size)
{
    int temp; char name[10];int temp2,temp3;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if((p+j)->arrival_time>(p+j+1)->arrival_time)
            {
                temp=(p+j)->priority;
                strcpy(name,(p+j)->name);
                temp2=(p+j)->burst_time;
                temp3=(p+j)->arrival_time;
                //////
                strcpy((p+j)->name,(p+j+1)->name);
                (p+j)->priority=(p+j+1)->priority;
                (p+j)->burst_time=(p+j+1)->burst_time;
                (p+j)->arrival_time=(p+j+1)->arrival_time;
                /////
                strcpy((p+j+1)->name,name);
                (p+j+1)->priority=temp;
                (p+j+1)->burst_time=temp2;
                (p+j+1)->arrival_time=temp3;

            }
        }
    }
}
void calculateWaitingTime(Process *p1,int size)
{
    float average_waiting=0.0,average_turnAround=(p1)->burst_time;
    p1->waitingTime=0;p1->startingTime=0;
    for(int i=1;i<size;i++)
    {
        (p1+i)->startingTime= (p1+i-1)->startingTime +(p1+i-1)->burst_time;
        (p1+i)->waitingTime=(p1+i)->startingTime;
        (p1+i)->turnAround=(p1+i)->waitingTime+(p1+i)->burst_time;
        average_waiting+=(p1+i)->waitingTime;
        average_turnAround+=(p1+i)->turnAround;
    }
    printf("....THE AVERAGE WAITING TIME IS : %.2f\n",average_waiting/(float)size);
    printf("....THE AVERAGE TURNAROUND TIME IS : %.2f\n",average_turnAround/(float)size);
}
