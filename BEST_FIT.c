#include<stdio.h>
#include<conio.h>
int main()
{
 int frag[20],b[20],f[20],i,j,nb,np,temp,lowest=10000;
 static int bf[20],ff[20];


 printf("\nEnter the number of blocks:");
 scanf("%d",&nb);
 printf("Enter the number of Process:");
 scanf("%d",&np);
 printf("\nEnter the size of the blocks:-\n");
 for(i=1;i<=nb;i++) {printf("Block %d:",i);scanf("%d",&b[i]);}
 printf("Enter the size of the Process :-\n");
 for(i=1;i<=np;i++) {printf("Process %d:",i);scanf("%d",&f[i]);}

 for(i=1;i<=np;i++)
 {
  for(j=1;j<=nb;j++)
  {
   if(bf[j]!=1)
   {
    temp=b[j]-f[i];
    if(temp>=0)
    if(lowest>temp)
    {
     ff[i]=j;
     lowest=temp;
    }
   }
  }
  frag[i]=lowest;
  bf[ff[i]]=1;
  lowest=10000;
 }
 printf("\nProcess_no:\tProcess_size :\tBlock_no:\tBlock_size:\tFragement");
 for(i=1;i<=np && ff[i]!=0;i++)
 printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
 return 0;
}