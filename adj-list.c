#include<stdio.h>
//#include<stdlib.h>
#define MAXNODE 4
typedef struct node
{
int vertexno;
struct node *next;
}node;
typedef struct list
{
node *head;
} List;
List *adjlist[MAXNODE] = {0};
void addnode(int s,int d)
{
node *dest,*temp,*src;
if(adjlist[s]->head == NULL)
{
dest = (node*)malloc(sizeof(node));
dest->vertexno = d;
dest->next = NULL;
adjlist[s]->head = dest;
}
else
{
dest = (node*)malloc(sizeof(node));
dest->vertexno = d;
dest->next = NULL;
temp = adjlist[s]->head;
while(temp->next != NULL)
 temp = temp->next;
temp->next = dest;
}
}
printlist()
{
int i;
for(i=0;i<MAXNODE;i++)
{
node *p = adjlist[i]->head;
printf("adjacency list of %d :",i);
while(p!=NULL)
{
printf("%d ",p->vertexno);
p = p->next;
}
printf("\n");
}
}
int main() {
int i;
for(i=0;i<MAXNODE;i++)
{
adjlist[i] = (List*)malloc(sizeof(List));
adjlist[i]->head = NULL;
}
addnode(0,1);
addnode(0,3);
addnode(1,2);
addnode(3,2);
addnode(2,3);
printlist();
}