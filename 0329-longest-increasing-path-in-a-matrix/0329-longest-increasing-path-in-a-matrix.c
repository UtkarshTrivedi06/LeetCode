int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;

int dfs(int** g,int i,int j,int** dp){
    if(dp[i][j]) return dp[i][j];
    int mx=0;
    for(int k=0;k<4;k++){
        int x=i+dirs[k][0], y=j+dirs[k][1];
        if(x>=0&&x<m&&y>=0&&y<n&&g[x][y]>g[i][j])
            if(mx<dfs(g,x,y,dp)) mx=dfs(g,x,y,dp);
    }
    dp[i][j]=mx+1;
    return dp[i][j];
}

int longestIncreasingPath(int** g,int gs,int* cs){
    m=gs; n=cs[0];
    int** dp=(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<m;i++){
        dp[i]=(int*)calloc(n,sizeof(int));
    }
    int ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
            int t=dfs(g,i,j,dp);
            if(ans<t) ans=t;
        }
    for(int i=0;i<m;i++) free(dp[i]);
    free(dp);
    return ans;
}
