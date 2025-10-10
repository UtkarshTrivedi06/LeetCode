#include <stdlib.h>
#include <string.h>

int* P;

int find(int i) {
    if (P[i] == i) return i;
    return P[i] = find(P[i]);
}

int unite(int i, int j) {
    int ri = find(i);
    int rj = find(j);
    
    if (ri != rj) {
        P[ri] = rj;
        return 1;
    }
    return 0;
}

int* findRedundantDirectedConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int N = edgesSize;
    P = (int*)malloc((N + 1) * sizeof(int));
    int* p_count = (int*)calloc(N + 1, sizeof(int));

    int* e1 = NULL;
    int* e2 = NULL;

    for (int i = 0; i < N; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (p_count[v] != 0) {
            e1 = (int*)malloc(2 * sizeof(int));
            e1[0] = p_count[v];
            e1[1] = v;
            
            e2 = (int*)malloc(2 * sizeof(int));
            e2[0] = u;
            e2[1] = v;
            break; 
        }
        p_count[v] = u;
    }
    
    free(p_count);
    
    for (int i = 1; i <= N; i++) P[i] = i;
    
    int* c_e = NULL; 
    
    for (int i = 0; i < N; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        if (e2 != NULL && u == e2[0] && v == e2[1]) continue;

        if (!unite(u, v)) {
            c_e = (int*)malloc(2 * sizeof(int));
            c_e[0] = u;
            c_e[1] = v;
        }
    }

    int* ans = NULL;

    if (e1 == NULL) {
        ans = c_e;
    } else {
        if (c_e == NULL) {
            ans = e2;
            free(e1);
        } else {
            ans = e1;
            free(e2);
            free(c_e);
        }
    }

    *returnSize = 2;
    free(P);
    
    return ans;
}