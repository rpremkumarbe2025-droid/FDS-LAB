#include<stdio.h>
int stack[100], n, top, i;
void push(int x)
{
 if(top >= n-1)
 printf("\n STACK is over flow");
 else
 {
 top++;
 stack[top] = x;
 printf("\n element pushed into stack:%d",x);
 }
}
void pop()
{
 if(top <= -1)
 printf("\n Stack is under flow");
 else
 {
 printf("\n The popped elements is %d",stack[top]);
 stack[top] = 0;
 top--;
 }
}
void display()
{
 if(top >= 0)
 {
 printf("\n The elements in STACK:\n");
 for(i=top; i>=0; i--)
 printf("%d \n",stack[i]);
 }
 else
 printf("\n The STACK is empty");
}
int main()
{
 top = -1;
 n = 5;
 push(10);
 push(20);
 push(30);
 push(40);
 push(50);
 push(60);
 display();
 pop();
 pop();
 pop();
 pop();
 pop();
 pop();
 pop(); return 0;
}