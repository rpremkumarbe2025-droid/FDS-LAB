#include <stdio.h>
// Function to print the array elements
void printArray(int arr[], int size) {
   for (int i = 0; i < size; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");
}
 
// Function to implement insertion sort
void insertionSort(int arr[], int size) {
   int key, j;
   
   // Outer loop starts from the second element (index 1)
   for (int i = 1; i < size; i++) {
       key = arr[i]; // The element to be inserted into the sorted part
       j = i - 1;
 
       /* Move elements of arr[0..i-1] that are greater than the key
          to one position ahead of their current position */
       while (j >= 0 && arr[j] > key) {
           arr[j + 1] = arr[j]; // Shift element to the right
           j = j - 1;           // Move to the next element on the left
       }
       
       // Insert the key at its correct position
       arr[j + 1] = key;
       printArray(arr, size);
 
   }
}
 
int main() {
   int data[] = {12, 11, 13, 5, 6};
   int size = sizeof(data) / sizeof(data[0]);
 
   printf("Original array:\n");
   printArray(data, size);
 
   insertionSort(data, size);
 
   printf("Sorted array in ascending order:\n");
   printArray(data, size);
   
   return 0;
}
