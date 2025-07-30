int searchInsert(int* nums, int numsSize, int target) {
    for(int i=0;i<numsSize ; i++){
        if(*(nums+i)==target){
            return i;
        }
    }
    int index=0;
    for(int i=0;i<numsSize ; i++){
        if(*(nums+i)<target){
            index++;
        }
    }
    return index;
}