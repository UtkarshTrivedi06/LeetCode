#include <stdlib.h>
#include <stdbool.h>

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize){
    int** adj = calloc(N+1, sizeof(int*));
    int* sz = calloc(N+1, sizeof(int));
    for(int i=0;i<dislikesSize;i++){
        int a=dislikes[i][0], b=dislikes[i][1];
        adj[a]=realloc(adj[a], (sz[a]+1)*sizeof(int)); adj[a][sz[a]++]=b;
        adj[b]=realloc(adj[b], (sz[b]+1)*sizeof(int)); adj[b][sz[b]++]=a;
    }
    int* color = calloc(N+1, sizeof(int));
    int* q = malloc((N+1)*sizeof(int));
    for(int i=1;i<=N;i++){
        if(color[i]) continue;
        color[i]=1; int l=0,r=0; q[r++]=i;
        while(l<r){
            int u=q[l++];
            for(int j=0;j<sz[u];j++){
                int v=adj[u][j];
                if(!color[v]){ color[v]=3-color[u]; q[r++]=v; }
                else if(color[v]==color[u]) return false;
            }
        }
    }
    return true;
}
