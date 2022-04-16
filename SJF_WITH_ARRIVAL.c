# include <stdio.h> 
#include<string.h>
typedef struct Process
{
    char name[20];
    int arrival_time;int burst_time;//int waitingTime;int startingTime;
}Process;
void inputDetails(Process *p,int n);
//void sortArrivalTime(Process *p,int size);
void sortBurstTime(Process *p,int size);
void display(Process *p,int size);
//void calculateWaitingTime(Process *p1,int size);
int main() {
    int number_of_processes;
    printf("enter the number of process:\n");
    scanf("%d",&number_of_processes);
    Process array[number_of_processes]; Process *ptr=array;
    inputDetails(ptr,number_of_processes);
    //sortArrivalTime(ptr,number_of_processes);
    sortBurstTime(ptr,number_of_processes);
    //calculateWaitingTime(ptr,number_of_processes);
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
        //printf("enter the arrival time: ");
        //scanf("%d",&(p+i)->arrival_time);
        printf("       ********     \n");
        
    }
}
// void sortArrivalTime(Process *p,int size)
// {
//     int temp; char name[10];int temp2;
//     for(int i=0;i<size-1;i++)
//     {
//         for(int j=0;j<size-i-1;j++)
//         {
//             if((p+j)->arrival_time>(p+j+1)->arrival_time)
//             {
//                 temp=(p+j)->arrival_time;
//                 strcpy(name,(p+j)->name);
//                 temp2=(p+j)->burst_time;
//                 //////
//                 strcpy((p+j)->name,(p+j+1)->name);
//                 (p+j)->arrival_time=(p+j+1)->arrival_time;
//                 (p+j)->burst_time=(p+j+1)->burst_time;
//                 /////
//                 strcpy((p+j+1)->name,name);
//                 (p+j+1)->arrival_time=temp;
//                 (p+j+1)->burst_time=temp2;

//             }
//         }
//     }
// }
void display(Process *p,int size)
{
    for(int i=0;i<size;i++)
    {
        printf("the details of %d process are :\n",(i+1));
        printf("       ********     \n");
        printf("process id : %s\n",(p+i)->name);
        //printf("arrival time : %d\n",(p+i)->arrival_time);
        printf("burst time : %d\n",(p+i)->burst_time);
        // printf("starting time : %d\n",(p+i)->startingTime);
        // printf("it's waiting time is :%d\n",(p+i)->waitingTime);
    }
}
void sortBurstTime(Process *p,int size)
{
    int temp; char name[10];int temp2;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if((p+j)->burst_time>(p+j+1)->burst_time)
            {
                //temp=(p+j)->arrival_time;
                strcpy(name,(p+j)->name);
                temp2=(p+j)->burst_time;
                //////
                strcpy((p+j)->name,(p+j+1)->name);
                //(p+j)->arrival_time=(p+j+1)->arrival_time;
                (p+j)->burst_time=(p+j+1)->burst_time;
                /////
                strcpy((p+j+1)->name,name);
                //(p+j+1)->arrival_time=temp;
                (p+j+1)->burst_time=temp2;

            }
        }
    }
}