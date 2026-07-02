#include<stdio.h>

void quicksort(int ss[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
         {
             while(ss[i]<=ss[pivot] && i<last)
                 i++;
             while(ss[j]>ss[pivot])
                 j--;
             if(i<j)
             {
                  temp=ss[i];
                  ss[i]=ss[j];
                  ss[j]=temp;
             }
         }

         temp=ss[pivot];
         ss[pivot]=ss[j];
         ss[j]=temp;
         quicksort(ss,first,j-1);
         quicksort(ss,j+1,last);
    }
}

int main()
{
  int x[20],size,i;

  printf("Enter size of the array: ");
  scanf("%d",&size);

  printf("Enter %d elements: ",size);
  for(i=0;i<size;i++)
    scanf("%d",&x[i]);

  quicksort(x,0,size-1);

  printf("Sorted elements: ");
  for(i=0;i<size;i++)
    printf("%d ",x[i]);

  return 0;
}
