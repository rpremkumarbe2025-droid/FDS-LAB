#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *prev,*next;
};
struct node *head,*newnode,*temp,*tail,*before,*curr;
int total_elements = 0;
void delete(int data)
{
 int found = 0;
 before = NULL;
 curr = head;
 while(curr != NULL) {
 if(curr->data == data)
 {
 found = 1;
 break;
 }
 before = curr;
 curr = curr->next;
 }
 if(found == 0)
 printf("\n element not found \n");
 else
 {
 if(curr == head)
 {
 head = curr->next;
 head->prev = NULL;
 free(curr);
 }
 else if(curr->next == NULL) {
 before->next = NULL;
 tail = before;
 free(curr);
 } else {
 before->next = curr->next;
 curr->next->prev = before;
 free(curr);
 }
 total_elements--;
 printf("the element deleted: %d \n",data);
 }
}
void prepend(int data)
{
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = data;
 newnode->next = newnode->prev = NULL;
 if(head == NULL) {
 head = newnode;
 } else {
 newnode->next = head; head->prev = newnode;
 head = newnode;
 }
 total_elements++;
 printf("the element prepended: %d \n",data);
}
void append(int data)
{
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = data;
 newnode->next = newnode->prev = NULL;
 if(head == NULL) {
 head = newnode;
 tail = newnode;
 } else {
 temp = head;
 while(temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newnode;
 newnode->prev = temp;
 tail = newnode;
 }
 total_elements++;
 printf("the element appended: %d \n",data);
}
void display()
{
 temp = head;
 printf("\n NULL <->");
 while(temp != NULL) {
 printf("%d <->",temp->data);
 temp = temp->next;
 }
 printf("NULL \n");
}
void reverse() {
 temp = tail;
 printf("\n NULL <->");
 while(temp != NULL) {
 printf("%d <->",temp->data);
 temp = temp->prev;
 }
 printf("NULL\n");
}
int main() {
 append(10);
 append(20);
 append(30);
 display();
 prepend(40);
 display();
 printf("\n total elements:%d",total_elements);
 printf("\n----\n");
 delete(30); display();
 printf("\n total elements:%d",total_elements);
 reverse();
 return 0;
}
