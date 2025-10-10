#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* indegree = calloc(numCourses, sizeof(int));
    int** graph = calloc(numCourses, sizeof(int*));
    int* size = calloc(numCourses, sizeof(int));

    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0], b = prerequisites[i][1];
        graph[b] = realloc(graph[b], (size[b] + 1) * sizeof(int));
        graph[b][size[b]++] = a;
        indegree[a]++;
    }

    int* queue = malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    int count = 0;
    while (front < rear) {
        int node = queue[front++];
        count++;
        for (int i = 0; i < size[node]; i++) {
            int next = graph[node][i];
            indegree[next]--;
            if (indegree[next] == 0) queue[rear++] = next;
        }
    }
    return count == numCourses;
}
