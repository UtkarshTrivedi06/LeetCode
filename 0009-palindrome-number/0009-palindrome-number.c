bool isPalindrome(long long x) {
    long long a=x, p=0;
    while(x>=1){
        p=10*p+x%10;
        x=x/10;
    }
    if(p==a){
        return true;
    }else{
        return false;
    }
}