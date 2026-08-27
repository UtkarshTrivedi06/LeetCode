int removeDuplicates(int* nums, int numsSize) {
    int c=1;
    int curr=nums[0];
    for(int i=0;i<numsSize;i++){
        if(nums[i]>curr){
            nums[c]=nums[i];
            curr=nums[i];
            c++;
        }
    }
    return c;
}