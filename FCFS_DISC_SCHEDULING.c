#include<stdio.h>
int main()
{
    int i,j,sum=0,n;
    int array1[20],array2[20];
    int disk;
    printf("enter number of location :");
    scanf("%d",&n);
    printf("enter position of head : ");
    scanf("%d",&disk);
    printf("enter elements of disk queue\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array1[i]);
        array2[i]=disk-array1[i];
        if(array2[i]<0)
        {
            array2[i]=array1[i]-disk;
            
        }
        disk=array1[i];
        sum=sum+array2[i];
        
    }
    for(i=0;i<n;i++)
    {
        printf("\n%d",array2[i]);
        
    }
    printf("\nmovement of total cylinders %d",sum);
    return 0;
}