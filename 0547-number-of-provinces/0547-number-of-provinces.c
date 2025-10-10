#include <stdlib.h>
#include <stdbool.h>

void dfsProv(int u, int n, int** isConnected, bool* vis){
    vis[u]=true;
    for(int v=0;v<n;v++) if(isConnected[u][v] && !vis[v]) dfsProv(v, n, isConnected, vis);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int n = isConnectedSize;
    bool* vis = calloc(n, sizeof(bool));
    int cnt=0;
    for(int i=0;i<n;i++) if(!vis[i]){ dfsProv(i,n,isConnected,vis); cnt++; }
    return cnt;
}
