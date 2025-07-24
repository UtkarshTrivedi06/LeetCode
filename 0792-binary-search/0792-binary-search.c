int search(int* nums, int numsSize, int target) {
    int b=0,m;
    while(b<=numsSize-1){
        m=(b+numsSize-1)/2;
        if(*(nums+m)==target){
            return m;
        }else if(*(nums+m)>target){
            numsSize=m;
        }else{
            b=m+1;
        }
    }
    return -1;
}