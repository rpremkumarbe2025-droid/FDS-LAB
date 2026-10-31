#include<stdio.h>
#include<stdlib.h>
/* Structure to create a node with data and next pointer */
struct node
{
 int data;
 struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
/* Enqueue operation on a queue */
void enqueue(int value)
{
 struct node *ptr;
 ptr = (struct node*)malloc(sizeof(struct node));
 ptr->data = value;
 ptr->next = NULL;
 if((front == NULL) && (rear == NULL))
 front = rear = ptr;
 else
 {
 rear->next = ptr;
 rear = ptr;
 }
 printf("Node is Inserted:%d\n\n",value);
}
/* Dequeue operation on a queue */
int dequeue()
{
 if(front == NULL)
 {
 printf("\nUnderflow\n");
 return -1;
 }
 else
 {
 struct node *temp = front;
 int temp_data = front->data;
 front = front->next;
 free(temp);
 return temp_data;
 }
}
/* Display all elements of queue */
void display()
{
 struct node *temp;
 if((front == NULL) && (rear == NULL))
 printf("\nQueue is Empty\n");
 else
 {
 printf("The queue is \n");
 temp = front;
 while(temp) {
 printf("%d--->",temp->data);
 temp = temp->next;
 }
 printf("NULL\n\n");
 }
}
int main()
{
 enqueue(10);
 enqueue(20);
 enqueue(30);
 display();
 dequeue();
 display();
 return 0;
}