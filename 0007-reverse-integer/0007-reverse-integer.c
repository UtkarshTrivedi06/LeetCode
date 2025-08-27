int reverse(long x){
    int n=0,c=0;
    long r=0;
    
    if(x<0){
        x=x*-1;
        n=1;
    }
    while(x>0){
        r=r*10+x%10;
        c++;
        x/=10;
        //printf("\n%d",r);
    }
    if(r<pow(2,31)*-1||r>=pow(2,31)-1){
        return 0;
    }
    if(n==1){
        r=r*-1;
    }
    return r;
}