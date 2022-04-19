# include <stdio.h> 
# include <string.h> 
typedef struct process
{
    char name[20];
    int burst_time;int waitingTime,turnAround,rem_burst_time;
}Process;
int time_quantam=4,temp,temp2=0,count=0;
void inputDetails(Process *p,int n);
void display(Process *p,int size);
void calculateWaitingTime(Process *p1,int size);
int main() {
    int number_of_processes;
    printf("enter the number of processes: ");
    scanf("%d",&number_of_processes);
    Process array[number_of_processes];
    Process *p=array;
    inputDetails(p,number_of_processes);
    calculateWaitingTime(p,number_of_processes);
    display(p,number_of_processes);
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
        (p+i)->rem_burst_time=(p+i)->burst_time;
       printf("       ********     \n");
    }
}
void calculateWaitingTime(Process *p1,int size)
{
    while(1)
   {
    for(int i=0,count=0;i<size;i++)
    {
        temp=time_quantam;
        if((p1+i)->burst_time==0){
            //printf("here 1:\n");
            count++;continue;}
        if((p1+i)->rem_burst_time>time_quantam){
            (p1+i)->rem_burst_time-=time_quantam;}
        else{
            if((p1+i)->rem_burst_time>=0)
            {
                temp=(p1+i)->rem_burst_time;
                (p1+i)->rem_burst_time=0;
            }
            temp2=temp2+temp;
           (p1+i)->turnAround=temp2;
        }
    }
    if(size==count)
      break;
    }
}
void display(Process *p,int size)
{
  float average_waiting=0.0,average_turnAround=0.0;
    for(int i=0;i<size;i++)
    {
        (p+i)->waitingTime=(p+i)->turnAround-(p+i)->burst_time;
        printf("waiting time of %d is %d\n",(i+1),(p+i)->waitingTime);
        average_waiting+=(p+i)->waitingTime;
        average_turnAround+=(p+i)->turnAround;
    }
    printf("....THE AVERAGE WAITING TIME IS : %.2f\n",average_waiting/(float)size);
    printf("....THE AVERAGE TURNAROUND TIME IS : %.2f\n",average_turnAround/(float)size);
}