#include<stdio.h>
#include<conio.h>
int main()
{
 int frag[10],b[10],p[10],i,j,nb,np,temp,highest=0;
 static int bf[10],ff[10];


 printf("\nEnter the number of blocks:");
 scanf("%d",&nb);
 printf("Enter the number of process:");
 scanf("%d",&np);
 printf("\nEnter the size of the blocks:-\n");
 for(i=0;i<nb;i++) {printf("Block %d:",i);scanf("%d",&b[i]);}
 printf("Enter the size of the process :-\n");
 for(i=0;i<np;i++) {printf("Process %d:",i);scanf("%d",&p[i]);}

 for(i=0;i<np;i++)
 {
  for(j=0;j<nb;j++)
  {
   if(bf[j]!=1)    //if bf[j] is not allocated
   {
    temp=b[j]-p[i];
    if(temp>=0)
    if(highest<temp)
    {
     ff[i]=j;
     highest=temp;
    }
   }
  }
  frag[i]=highest;
  bf[ff[i]]=1;
  highest=0;
 }
 printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
 for(i=0;i<np;i++)
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],ff[i],b[ff[i]],frag[i]);
 return 0;
}