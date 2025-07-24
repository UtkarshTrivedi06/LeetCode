int missingNumber(int* nums, int numsSize) {
    for(int i=0;i<=numsSize;i++){
        int p=0;
        for (int j=0;j<numsSize;j++){
            if(*(nums + j)==i){
                p=1;
            }
        }
        if(p==0){
            return i;
        }
    }
    return -1;
}