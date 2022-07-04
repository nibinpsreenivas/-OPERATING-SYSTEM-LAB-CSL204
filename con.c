#include <stdio.h>
int isempty();
int isfull();
int mutex = 1;
void producer();
int consumer();
#define n 10
int buffer[n],front = -1,rear =-1;
int main()
{
   int item,a,o;
    do
     { 
       printf("\n1)produce\n2)consumes\n3)end");
       printf("\nenter the number to perform the operation");
       scanf("%d",&o);
       switch(o)
        {
          case 1 : if(mutex = 1)
                       producer();
                       break;
          case 2 : if(!isempty())
                   {
                    if(mutex = 1)
                    printf("\nthe consumer consumes is %d",consumer());
                   }
                    else
                    printf("\nthe buffer is empty");
                    
                   break;        
        
         }
                                   
        }while(o!=3);
 }
 
 int isempty()
 {
     if(rear == -1)
      return 1;
     else 
      return 0;  
 }
 int isfull()
 {
    if(front == (rear+1)%n)
      return 1;
    else
      return 0;
 }
 void producer()
 {
    mutex=0;
   if(isfull())
          printf("\nthe buffer is full");
   else
  {
    
   if(front==-1)
     front = rear = 0;
   else
     rear = (rear+1)%n;
   buffer[rear]=1;
  printf("\nthe producer produces  %d",(rear+1));
  }
   mutex=1;
 }
 int consumer()
 { 
   int a;
   if(isempty())
           printf("\nthe buffer is empty");
    else
   {
     a=front+1;
     if(front==rear)
       {
         front = rear =-1;
       }
     else
      front= (front+1)%n;
      return a;
}
 }

