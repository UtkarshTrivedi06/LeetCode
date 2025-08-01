/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* a, int n, int* rc) {
    int *r=(int *)malloc(n*sizeof(int));
    int *r1=(int *)calloc(n,sizeof(int));
    int c=0,i=0;
    
    for(int i=0;i<n;i++){
        if(r1[a[i]-1]!=-1){
            r1[a[i]-1]=-1;
        }
    }
    for(int i=0;i<n;i++){
        if(r1[i]!=-1){
            
            *(r+c)=i+1;
            c++;
        }
    } 
    *rc=c;
    return r;
}