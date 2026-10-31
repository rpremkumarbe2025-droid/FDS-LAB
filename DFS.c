#include <stdio.h>
#define MAX 50
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int vertex)
{
 int i;
 // Mark vertex as visited visited[vertex] = 1;
 // Display vertex
 printf("%d ", vertex);
 // Visit adjacent vertices
 for (i = 0; i < n; i++)
 {
 if (graph[vertex][i] == 1 && visited[i] == 0)
 {
 DFS(i);
 }
 }
}
int main()
{
 int i, j;
 int start;
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
 printf("DFS Traversal: ");
 DFS(start);
 return 0;
}