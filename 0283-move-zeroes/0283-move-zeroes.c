void moveZeroes(int* a, int c) {
    int cnt=0,i=0,j;
    while(i<c-cnt){
        if(a[i]==0){
            int t=a[i];
            for(j=i;j<c-cnt-1;j++){
                a[j]=a[j+1];
                
            }
            a[j]=t;
            cnt++;
        }
        else{
            i++;
        }
    }
        
}