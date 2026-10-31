#include <stdio.h>
#define MAX 50
int main()
{
 int graph[MAX][MAX];
 int visited[MAX];
 int queue[MAX]; int n, i, j;
 int front = 0, rear = 0;
 int start, current;
 // Read number of vertices
 printf("Enter number of vertices: ");
 scanf("%d", &n);
 // Read adjacency matrix
 printf("Enter the adjacency matrix:\n");
 for (i = 0; i < n; i++)
 {
 for (j = 0; j < n; j++)
 {
 scanf("%d", &graph[i][j]);
 }
 }
 // Initialize visited array
 for (i = 0; i < n; i++)
 {
 visited[i] = 0;
 }
 // Read starting vertex
 printf("Enter starting vertex: ");
 scanf("%d", &start);
 // Insert starting vertex into queue
 visited[start] = 1;
 queue[rear] = start;
 rear++;
 printf("BFS Traversal: ");
 // BFS traversal
 while (front < rear)
 {
 // Remove vertex from queue
 current = queue[front];
 front++;
 printf("%d ", current);
 // Find adjacent vertices
 for (i = 0; i < n; i++) {
 if (graph[current][i] == 1 && visited[i] == 0)
 {
 visited[i] = 1;
 queue[rear] = i;
 rear++;
 }
 }
 }
 return 0;
}