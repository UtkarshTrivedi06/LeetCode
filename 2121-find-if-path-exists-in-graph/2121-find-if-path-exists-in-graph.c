#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) return true;

    Node** graph = calloc(n, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        Node* nodeU = malloc(sizeof(Node));
        nodeU->val = v;
        nodeU->next = graph[u];
        graph[u] = nodeU;

        Node* nodeV = malloc(sizeof(Node));
        nodeV->val = u;
        nodeV->next = graph[v];
        graph[v] = nodeV;
    }

    bool* visited = calloc(n, sizeof(bool));
    int* queue = malloc(n * sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;

    while (front < rear) {
        int node = queue[front++];
        for (Node* temp = graph[node]; temp; temp = temp->next) {
            if (!visited[temp->val]) {
                if (temp->val == destination) {
                    free(queue);
                    free(visited);
                    for (int i = 0; i < n; i++) {
                        Node* curr = graph[i];
                        while (curr) {
                            Node* next = curr->next;
                            free(curr);
                            curr = next;
                        }
                    }
                    free(graph);
                    return true;
                }
                visited[temp->val] = true;
                queue[rear++] = temp->val;
            }
        }
    }

    free(queue);
    free(visited);
    for (int i = 0; i < n; i++) {
        Node* curr = graph[i];
        while (curr) {
            Node* next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(graph);

    return false;
}
