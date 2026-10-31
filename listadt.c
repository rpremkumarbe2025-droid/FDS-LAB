#include<stdio.h>
#define MAXSIZE 50
int arr[MAXSIZE],index=0,nofelements;
void append(int data)
{
​arr[index] = data;
​index++;
​nofelements++;
}
void traverse()
{
​for(index=0;index<nofelements;index++)
​{
​​printf("%d->",arr[index]);
​}
}
void prepend(int data)
{
​int i;
​for(i=index;i>0;i--)
​{
​​arr[i] = arr[i-1];
​}
​arr[0] = data;
​index++;
​nofelements++;
}
void insert(int data,int pos)
{
​int i;
​for(i=index;i>pos;i--)
​{
​​arr[i] = arr[i-1];
​}
​arr[pos] = data;
​index++;
​nofelements++;
}
 
 
int getnofelements()
{
​return nofelements;
}
int main()
{
​int n;
​append(5);
​append(6);
​append(7);
​prepend(8);
​prepend(9);
​insert(4,2);
​traverse();
​n = getnofelements();
​printf("nof elments:%d",n);
​return 0;
}
 