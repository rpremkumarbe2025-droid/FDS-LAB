#include<stdio.h>
int BinarySearch(int arr[],int low ,int high,int key)
{
  int mid;
  while(low<=high)
  {
  ​mid=(low+high)/2;
  ​if (arr[mid]==key)
    return mid;
   if(arr[mid]<key)
  low=mid+1;
   else
  high=mid-1;
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
​int arr[]={10,23,45,70,90,100,111,123};
​int key =45;
​int found_index;
​int n;
​n=sizeof(arr)/sizeof(int);
​print(arr,n);
​found_index=BinarySearch(arr,0,n-1,key);
​if(found_index!=-1)
​​printf("\n key:%d search found at %d\n",key,found_index);
​else
   ​printf("\n key:%d search not found\n",key);
​key=150;
​found_index=BinarySearch(arr,0,n-1,key);
​if(found_index!=-1)
   ​printf("\n key:%d search found at %d\n",key,found_index);
​else
​​printf("\n key:%d search not found\n",key);
​return 0;
 
}