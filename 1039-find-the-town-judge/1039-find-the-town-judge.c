#include <stdio.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int* indegree = calloc(n + 1, sizeof(int));
    int* outdegree = calloc(n + 1, sizeof(int));

    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0], b = trust[i][1];
        outdegree[a]++; indegree[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0)
            return i;
    }
    return -1;
}
