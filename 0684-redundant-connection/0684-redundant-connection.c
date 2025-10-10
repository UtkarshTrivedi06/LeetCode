#include <stdlib.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int* rank, int u, int v) {
    int pu = find(parent, u), pv = find(parent, v);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) parent[pu] = pv;
    else if (rank[pu] > rank[pv]) parent[pv] = pu;
    else { parent[pv] = pu; rank[pu]++; }
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int n = edgesSize;
    int* parent = malloc((n + 1) * sizeof(int));
    int* rank = calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) parent[i] = i;

    int* res = malloc(2 * sizeof(int));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        int pu = find(parent, u), pv = find(parent, v);
        if (pu == pv) {
            res[0] = u; res[1] = v;
            *returnSize = 2;
            return res;
        }
        unionSet(parent, rank, u, v);
    }
    *returnSize = 0;
    return NULL;
}
