int missingNumber(int* nums, int numsSize) {
    int a=0,b=0;
    for(int i=0;i<=numsSize;i++){
        a+=i;
    }
        
    for (int j=0;j<numsSize;j++){
        b+=nums[j];
    }
    return a-b;
}