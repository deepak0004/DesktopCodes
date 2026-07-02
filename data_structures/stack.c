#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define siz 5

struct stack
{
   int s[siz];     //s is the array.
   int top;
}st;
int stfull()
{
   if(st.top>=siz-1)
      return 1;
   else
      return 0;
}
int stempty()
{
   if(st.top==-1)
      return 1;
   else
      return 0;
}
void push(int item)
{
   st.top++;
   st.s[st.top]=item;
}
int pop()
{
   int item;
   item=st.s[st.top];
   st.top--;
   return item;
}
void display()
{
   int i;
   if(stempty())
      printf("Stack Is Empty!\n");
   else
   {
      for(i=st.top;i>=0;i--)
         printf("%d\n",st.s[i]);
   }
}

int main()
{
           int item,choice;
           char ans;
           st.top=-1;
           do
           {
                  printf("Main Menu\n");
                  printf("1.Push \n2.Pop \n3.Display \n4.Exit \n");
                  printf("Enter Your Choice:");
                  scanf("%d",&choice);
                  switch(choice)
                  {
                          case 1:
                             printf("Enter The item to be pushed:");
                             scanf("%d",&item);
                             if(stfull())
                                printf("Stack is Full!\n");
                             else
                                push(item);
                             break;
                          case 2:
                             if(stempty())
                                printf("Empty stack-Underflow!!\n");
                             else
                             {
                                item=pop();
                                printf("The popped element is %d\n", item);
                             }
                             break;
                          case 3:
                             display();
                             break;
                          case 4:
                             exit(0);
                  }
                  printf("Do You want To Continue: ");
                  getchar();
                  ans=getchar();
                  printf("\n");
             }while((ans=='Y') || (ans=='y'));
             return 0;
}
