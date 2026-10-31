#include <stdio.h>
#include <malloc.h>
struct node
{
 int data;
 struct node *next;
};
struct node *head, *tail, *newnode, *temp, *prev;
void createnode(int d)
{
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = d;
 newnode->next = NULL;
}
void insert(int key, int data)
{
 int found = 0;
 temp = head;
 do
 {
 if(temp->data == key)
 {
 found = 1;
 break;
 }
 temp = temp->next;
 }while(temp != head);
 if(found == 0)
 printf("key element not found \n");
 else
 {
 createnode(data);
 if(temp == tail)
 {
 temp->next = newnode;
 tail = newnode;
 tail->next = head;
 }
 else
 {
 newnode->next = temp->next;
 temp->next = newnode;
 }
 printf("inserted :%d after :%d",data,key);
 }
}
void prepend(int d)
{
 createnode(d);
 if(head == NULL)
 {
 head = tail = newnode;
 tail->next = head; }
 else
 {
 newnode->next = head;
 head = newnode;
 tail->next = head;
 }
 printf("data prepended :%d \n",d);
}
void append(int d)
{
 createnode(d);
 if(head == NULL)
 {
 head = tail = newnode;
 tail->next = head;
 }
 else
 {
 tail->next = newnode;
 tail = newnode;
 tail->next = head;
 }
 printf("data appended :%d \n",d);
}
void display()
{
 temp = head;
 do
 {
 printf("%d ->",temp->data);
 temp = temp->next;
 }while(temp != head);
}
void delete(int data)
{
 int found = 0;
 temp = head;
 do {
 if(temp->data == data) {
 found = 1;
 break;
 }
 temp = temp->next;
 }while(temp != head);
 if(found == 0)
 printf("key element not found \n");
 else
 {
 if(temp == head)
 {
 head = head->next;
 tail->next = head;
 free(temp);
 } printf("data deleted :%d \n",data);
 }
}
int main()
{
 append(10);
 append(20);
 append(30);
 prepend(40);
 display();
 printf("\n--\n");
 insert(20,25);
 display();
 printf("\n--\n");
 delete(10);
 display();
 printf("\n--\n");
 display();
}