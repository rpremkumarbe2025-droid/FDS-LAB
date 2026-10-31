#include<stdio.h>
#define SIZE 5
int linearsearch(int arr[],int size,int key)
{
​int i;
​for(i=0;i<size;i++)
​{
​  if(arr[i]==key)
​return i;
}
return-1;
}
void print(int a[],int n )
{
int i;
for(i=0;i<n;i++) printf("%d ",a[i]);
}
int main()
{
​int page_number[SIZE]={86,91,34,50,10};
   int key;
​int pos;
​int n;
​n=sizeof(page_number)/sizeof(int);
​print(page_number,n);
​key=50;
​pos=linearsearch(page_number,SIZE,key);
​if(pos!=-1)
​ printf("\n element:%d found at postion:%d\n",key,pos);
​ else
​ printf("\nelement:%d not found",key);
​ key=89;
​ pos=linearsearch (page_number,SIZE,key);
​ if(pos!=-1)
​ printf("\nelement:%d found at position:%d\n",key,pos);
​ else
​ printf("element:%d  not found",key);
​ return 0;
}
 