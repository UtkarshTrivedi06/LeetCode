#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int* indeg = calloc(numCourses, sizeof(int));
    int** graph = calloc(numCourses, sizeof(int*));
    int* sz = calloc(numCourses, sizeof(int));
    for(int i=0;i<prerequisitesSize;i++){
        int a=prerequisites[i][0], b=prerequisites[i][1];
        graph[b]=realloc(graph[b], (sz[b]+1)*sizeof(int)); graph[b][sz[b]++]=a;
        indeg[a]++;
    }
    int* q = malloc(numCourses * sizeof(int)); int l=0,r=0;
    for(int i=0;i<numCourses;i++) if(indeg[i]==0) q[r++]=i;
    int* res = malloc(numCourses * sizeof(int));
    int idx=0;
    while(l<r){
        int u=q[l++]; res[idx++]=u;
        for(int i=0;i<sz[u];i++){
            int v=graph[u][i];
            indeg[v]--;
            if(indeg[v]==0) q[r++]=v;
        }
    }
    if(idx!=numCourses){ *returnSize=0; free(res); return NULL; }
    *returnSize=numCourses;
    return res;
}
