#include<stdio.h>
#define MAX 50
int queue[MAX];
int rear = -1;
int front = -1;
void enqueue(int data)
{
 if(rear == MAX - 1)
 printf("Queue Overflow \n");
 else
 {
 if(front == -1)
 front = 0;
 rear = rear + 1;
 queue[rear] = data;
 printf("Element inserted is : %d\n", queue[rear]);
 }
}
void dequeue()
{
 if(front == -1 || front > rear)
 {
 printf("Queue Underflow \n");
 return;
 }
 else
 {
 printf("\nElement deleted is : %d\n", queue[front]);
 front = front + 1;
 }
}
void display()
{
 int i;
 if(front == -1)
 printf("Queue is empty \n");
 else
 {
 printf("Queue is : \n");
 for(i = front; i <= rear; i++)
 printf("%d ", queue[i]);
 }
}
int main()
{
 enqueue(10);
 enqueue(20);
 enqueue(30);
 enqueue(50);
 enqueue(50);
 enqueue(60);
 display();
 dequeue(); dequeue();
 display();
 return 0;
}