#include <stdlib.h>
#include <limits.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int** adj = calloc(n, sizeof(int*));
    int* sz = calloc(n, sizeof(int));
    int** cost = calloc(n, sizeof(int*));
    for(int i=0;i<flightsSize;i++){
        int u=flights[i][0], v=flights[i][1], w=flights[i][2];
        adj[u]=realloc(adj[u], (sz[u]+1)*sizeof(int)); cost[u]=realloc(cost[u], (sz[u]+1)*sizeof(int));
        adj[u][sz[u]]=v; cost[u][sz[u]]=w; sz[u]++;
    }
    int* dist = malloc(n*sizeof(int));
    for(int i=0;i<n;i++) dist[i]=INT_MAX; dist[src]=0;
    for(int t=0;t<=K;t++){
        int* tmp = malloc(n*sizeof(int));
        for(int i=0;i<n;i++) tmp[i]=dist[i];
        for(int u=0;u<n;u++){
            if(dist[u]==INT_MAX) continue;
            for(int j=0;j<sz[u];j++){
                int v=adj[u][j], w=cost[u][j];
                if(dist[u]+w < tmp[v]) tmp[v]=dist[u]+w;
            }
        }
        for(int i=0;i<n;i++) dist[i]=tmp[i];
        free(tmp);
    }
    return dist[dst]==INT_MAX ? -1 : dist[dst];
}
