//  C Program to Implement a Queue using an Array

#include<stdio.h>
#include<stdlib.h>
int queue_array[100010],rear=-1,front=-1;
void insert()
{
        int add_item;
        if(front==-1)
           front=0;
        printf("Insert the element in queue: ");
        scanf("%d",&add_item);
        rear++;
        queue_array[rear]=add_item;
}
void delete()
{
    if((front==-1) || (front>rear))
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from queue is: %d\n",queue_array[front]);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is: ");
        for(i=front;i<=rear;i++)
            printf("%d ",queue_array[i]);
        printf("\n");
    }
}

int main()
{
    char ans;
    int choice;

    do
    {
        printf("1.Insert element to queue \n");
        printf("2.Delete element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Quit \n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
        printf("Do You want To Continue: ");
        getchar();
        ans=getchar();
        printf("\n");
   }while((ans=='Y') || (ans=='y'));

   return 0;
}
